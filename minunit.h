#ifndef UNITSTUFF_MINUNIT_H
#define UNITSTUFF_MINUNIT_H

/*extern int tests_run;*/

#define MU_ASSERT(msg, test)                    \
    do {                                        \
        if (!(test)) {                          \
            return msg;                         \
        }                                       \
    } while (0)

#define MU_RUN_TESTS(event_handler, ...)        \
    do {                                        \
        char *(*tests[])(void) = {               \
            __VA_ARGS__,                        \
            NULL                                \
        };                                      \
        int i = 0;                              \
        while (tests[i] != NULL) {              \
/*            tests_run++;*/                        \
            char *message = tests[i]();         \
            if (message) {                      \
                event_handler(message, 0);      \
            } else {                            \
                event_handler(message, 1);      \
            }                                   \
            i++;                                \
        }                                       \
    } while (0)

#endif // UNITSTUFF_MINUNIT_H
