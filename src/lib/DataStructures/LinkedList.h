#pragma once

#include <stdint.h>

/** @brief Node in a linked list. */
struct LinkedListNode
{
    void* data;
    LinkedListNode* next;
};

/** @brief Singly linked list for non-owning void pointers. */
class LinkedList
{
public:
    /** @brief Construct an empty list. */
    LinkedList();
    /** @brief Destroy the list and clear its nodes. */
    ~LinkedList();
    /** @brief Append data to the end of the list. */
    void Append(void* data);
    /** @brief Remove the first node containing data. */
    bool Remove(void* data);
    /** @brief Return and remove the first node value. */
    void* PopFront();
    /** @brief Peek at the first node value. */
    void* PeekFront() const;
    /** @brief Return the number of nodes. */
    uint32_t Size() const;
    /** @brief Return true when the list has no nodes. */
    bool IsEmpty() const;
    /** @brief Remove all nodes. */
    void Clear();
private:
    LinkedListNode* head;
    LinkedListNode* tail;
    uint32_t size;
};