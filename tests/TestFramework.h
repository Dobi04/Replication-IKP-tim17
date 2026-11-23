    #pragma once

    #include <stdio.h>

    /** @brief Test function type. */
    typedef bool (*TestFunction)();

    /** @brief One registered test. */
    struct TestRegistration
    {
        const char* name;
        TestFunction function;
    };

    inline TestRegistration testRegistrations[256];
    inline unsigned int testRegistrationCount = 0;

    /** @brief Register a test and return it as a static test registrar. */
    class TestRegistrar
    {
    public:
        /** @brief Register a test function. */
        TestRegistrar(const char* name, TestFunction function)
        {
            if (testRegistrationCount < 256)
            {
                testRegistrations[testRegistrationCount].name = name;
                testRegistrations[testRegistrationCount].function = function;
                ++testRegistrationCount;
            }
        }
    };

    /** @brief Assert that a condition is true. */
    #define ASSERT_TRUE(x) do { if (!(x)) { printf("ASSERT_TRUE failed: %s\n", #x); return false; } } while (0)
    /** @brief Assert that two values are equal. */
    #define ASSERT_EQ(a, b) do { if (!((a) == (b))) { printf("ASSERT_EQ failed: %s == %s\n", #a, #b); return false; } } while (0)
    /** @brief Declare and register one test. */
    #define TEST(name) \
        static bool test_##name(); \
        static TestRegistrar testRegistrar_##name(#name, test_##name); \
        static bool test_##name()

    /** @brief Run all registered tests and return the failed-test count. */
    inline int RunAllTests()
    {
        unsigned int failed = 0;
        for (unsigned int i = 0; i < testRegistrationCount; ++i)
        {
            bool passed = testRegistrations[i].function();
            printf("%s: %s\n", testRegistrations[i].name, passed ? "PASS" : "FAIL");
            if (!passed)
            {
                ++failed;
            }
        }
        return static_cast<int>(failed);
    }