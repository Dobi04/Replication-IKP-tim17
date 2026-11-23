# PROJEKAT 17 · DOKUMENTACIJA

# Dizajn sistema

*Dijagram komponenti i komunikacija između računara Original i Kopija*

## Dijagram komponenti i komunikacija

``` mermaid
flowchart LR
    subgraph O["RAČUNAR 1 — ORIGINAL"]
        C["Uređaj / klijent + ClientLib<br/>Javni interfejs: Connect(), SendMessage() i GetMessages()."]
        OM["OriginalMaster · TCP :5000<br/>Upravlja procesima redova; pronalazi postojeći proces ili pokreće novi."]
        OQ["Original-QueueProc A<br/>Prima merenja, dodeljuje messageId i čuva nepotvrđene poruke u lokalnom redu."]
        C -->|"1. CONNECT / zahtev za port"| OM
        OM -->|"2. veza sa procesom reda"| OQ
        C -->|"DEVICE_DATA"| OQ
    end

    subgraph K["RAČUNAR 2 — KOPIJA"]
        KM["KopijaMaster · TCP :6000<br/>Pronalazi ili pokreće proces para za traženi red."]
        KQ["Kopija-QueueProc A<br/>Prepoznaje duplikate, trajno čuva poruke i šalje ACK potvrdu."]
        KM -->|"pokretanje / port procesa"| KQ
    end

    OQ <-->|"4. direktna TCP veza<br/>DATA → Kopija<br/>ACK → Original<br/>GET_MESSAGES / RESPONSE"| KQ
    OQ -->|"3. PAIR_HELLO"| KM
```

**Ključno pravilo:** Original uklanja poruku iz reda tek nakon ACK
potvrde da je Kopija trajno sačuvala poruku.

------------------------------------------------------------------------

# Komponente i obrazloženje

*Uloge komponenti, inicijalna sinhronizacija i oporavak veze*

  -----------------------------------------------------------------------
  Komponenta                          Opis
  ----------------------------------- -----------------------------------
  **Uređaj / klijent i ClientLib**    Klijent koristi biblioteku
                                      ClientLib za komunikaciju sa
                                      sistemom. Biblioteka obezbeđuje
                                      funkcije `Connect`, `SendMessage` i
                                      `GetMessages`. Pri povezivanju
                                      kontaktira OriginalMaster, dobija
                                      port procesa reda, a zatim otvara
                                      TCP vezu ka tom procesu.

  **OriginalMaster**                  Kontrolni proces na računaru
                                      Original sluša na portu 5000 i vodi
                                      registar aktivnih procesa redova.
                                      Za zahtevani red vraća port
                                      postojećeg procesa ili pokreće novi
                                      Original-QueueProc.

  **Original-QueueProc**              Za svaki red postoji zaseban OS
                                      proces. On prima i proverava
                                      merenja, dodeljuje messageId i
                                      stavlja poruke u lokalni red
                                      čekanja. Poruke šalje procesu para
                                      na kopiji, ali ih ne uklanja dok ne
                                      stigne potvrda ACK.

  **KopijaMaster**                    Kontrolni proces na računaru Kopija
                                      sluša na portu 6000. Kada primi
                                      PAIR_HELLO, pronalazi odgovarajući
                                      proces reda ili ga pokreće ako ne
                                      postoji, a zatim vraća njegov port.

  **Kopija-QueueProc**                Za svaki red postoji zaseban proces
                                      koji prima poruke od svog para na
                                      Originalu. Proverava messageId,
                                      trajno čuva nove poruke i šalje ACK
                                      tek nakon upisa. Duplikat ne
                                      upisuje ponovo, ali za njega takođe
                                      vraća ACK.

  **Veza između procesa**             Master procesi služe za
                                      pronalaženje i pokretanje procesa,
                                      a ne za prenos merenja. Nakon
                                      uparivanja uspostavlja se direktna
                                      TCP veza između Original-QueueProc
                                      i Kopija-QueueProc. Njome se
                                      prenose DATA, ACK i zahtevi za
                                      preuzimanje poruka.

  **Integrity update pri pokretanju** Pri startu Original-QueueProc
                                      poziva GetMessages i od kopije
                                      preuzima sve prethodno sačuvane
                                      poruke; tek po završetku
                                      sinhronizacije otvara port za
                                      uređaje.

  **Prekid i ponovno uspostavljanje   Ako se TCP veza prekine,
  veze**                              nepotvrđene poruke ostaju u redu i
                                      šalju se ponovo nakon povezivanja;
                                      kopija prepoznaje već primljene
                                      poruke pomoću messageId i ne
                                      upisuje duplikate ponovo.
  -----------------------------------------------------------------------

------------------------------------------------------------------------

# Unutrašnji dizajn i protokol

*Organizacija niti, sinhronizacija, oporavak, format poruka i
testiranje*

## Original-QueueProc --- niti i strukture

Proces koristi jednu accept nit za prijem konekcija, po jednu radnu nit
za svakog povezanog uređaja, zasebnu sender nit za slanje Kopiji i ACK
nit za prijem potvrda. Merenja se smeštaju u FIFO pendingQueue; mapa
prati stanje i ID-jeve. Kritične sekcije štite red, mapu i brojač.

U testu sa 100 istovremeno povezanih uređaja očekuje se 103 niti u
Original-QueueProc: 100 radnih + 3 servisne (accept, sender i ACK).

## Kopija-QueueProc --- prijem i grupni upis

Receiver nit prima DATA okvire i prosleđuje ih Writer niti. Writer
proverava indeks ID-jeva i grupiše pristigle nove poruke (najviše 64, u
skladu sa prozorom slanja). Grupu upisuje u append-only dnevnik, poziva
FlushFileBuffers jednom za celu grupu, pa tek nakon uspešnog flush-a
šalje ACK za svaku poruku iz grupe.

Ako upis ili flush ne uspe, ACK se ne šalje. Duplikat se ne upisuje
ponovo; ACK se ponovo šalje samo za već trajno sačuvanu poruku. Indeks
se pri startu obnavlja čitanjem dnevnika.

## ID poruke i oporavak nakon restarta

messageId je 64-bitni rastući broj za svaki red. Pri pokretanju Original
učitava najveći ID iz oba izvora:

1.  Poruka preuzetih sa Kopije tokom integrity update-a.
2.  Sopstvenog lokalnog dnevnika, uključujući nepotvrđene poruke koje
    Kopija još nema.

Sledeći ID je:

`max(maxID_kopije, maxID_lokalni) + 1`

Ako oba izvora nemaju poruke, počinje od 1. Pending poruke iz lokalnog
dnevnika vraćaju se u red za slanje. Port za uređaje otvara se tek nakon
sinhronizacije i obnove brojača.

## Integrity update u paketima

Kopija vraća ranije sačuvane poruke u paketima od najviše 500 zapisa, uz
oznaku poslednjeg paketa. Original ih smešta u recovery bafer, odnosno
staging fajl ako nema dovoljno memorije, i ažurira najveći ID.

Paketi se obrađuju redom; prijem novih merenja počinje tek kada je
primljen i obrađen poslednji paket. Uređaji koji se povežu tokom
sinhronizacije dobijaju BUSY i ponavljaju CONNECT nakon kratke pauze.
Port reda se otvara tek po završetku update-a.

## Portovi i format TCP poruka

OriginalMaster sluša na TCP 5000, a KopijaMaster na TCP 6000.

TCP okvir ima zaglavlje:

  Polje           Veličina
  ------------- ----------
  Verzija              1 B
  Tip                  1 B
  Dužina tela          4 B

Višebajtne vrednosti su big-endian.

**DATA telo sadrži:**

  Polje          Tip         Veličina Jedinica
  -------------- --------- ---------- ----------
  messageId      uint64           8 B ---
  deviceNumber   uint32           4 B ---
  current        float32          4 B A
  voltage        float32          4 B V
  power          float32          4 B W

Ukupno telo DATA poruke: **24 B**.

**ACK telo** sadrži `messageId` (`uint64`, 8 B).

Maksimalni okvir je 1 MiB; prijem čita sve bajtove okvira.

## Prozor slanja, gašenje i testovi

Original šalje do 64 poruke istovremeno bez ACK-a. Svaki ACK potvrđuje
pojedinačni messageId; uklanja se samo odgovarajući zapis iz
pendingQueue.

Graceful shutdown zaustavlja prijem novih klijenata, završava niti i
zatvara sokete/handle-ove.

Testirati:

-   1, 10 i 100 uređaja i 10.000 poruka;
-   integrity update;
-   restart;
-   prekid veze;
-   duplikate i ponovni prenos.

Meriti propusnost, kašnjenje ACK-a, CPU, RAM, mrežu, broj niti i context
switch-eve. Posebno uporediti grupni upis/flush sa upisom i flush-om po
poruci; zabeležiti veličinu grupe i ostvarenu propusnost. Proveriti
curenje memorije i handle-ova pomoću UMDH i performance counter-a.

------------------------------------------------------------------------

**Napomena:** Veličine paketa, prozora i maksimalnog TCP okvira
predstavljaju početne projektne vrednosti i proveravaju se stress
testovima. Grupni flush potvrđuje poruke tek nakon uspešnog trajnog
upisa.

**Implementacija:** C/C++ na Windows-u, Visual Studio i WinSock2.
Strukture podataka implementiraju se samostalno, bez STL-a.
