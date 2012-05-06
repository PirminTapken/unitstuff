#ifndef UNITSTUFF_MINUNIT_H
#define UNITSTUFF_MINUNIT_H

typedef struct Test_Data {
    int tests_run ;
    int tests_failed;
} Test_Data;

#define MU_ASSERT(msg, test)                    \
    do {                                        \
        if (!(test)) {                          \
            return msg;                         \
        }                                       \
    } while (0)

#define MU_RUN_TESTS(event_handler, testdata, ...)        \
    do {                                        \
        /**
         * This is a list of function pointers
         * returning pointers to char-arrays.
         * The functions don't take arguments.
         */                                     \
        char *(*tests[])(void) = {              \
            __VA_ARGS__,                        \
            NULL                                \
        };                                      \
        /* Resetting the values */              \
        testdata->tests_run = 0;                \
        testdata->tests_failed = 0;             \
        int i = 0;                              \
        while (tests[i] != NULL) {              \
            char *message = tests[i]();         \
            int is_successful;                  \
            if (message) {                      \
                is_successful = 0;              \
            } else {                            \
                is_successful = 1;              \
            }                                   \
            event_handler(message, is_successful, testdata);\
            i++;                                \
        }                                       \
    } while (0)

#endif // UNITSTUFF_MINUNIT_H
