#ifndef UNITSTUFF_MINUNIT_H
#define UNITSTUFF_MINUNIT_H

typedef struct {
	char *message;
	int retval;
} TestResult;

extern int tests_run;

#define MU_ASSERT(msg, test)            \
    do {                                \
        TestResult test_result;         \
        test_result.message = msg;      \
        if (!(test)) {                  \
            test_result.retval = 1;     \
        } else {                        \
            test_result.retval = 0;     \
        }                               \
        return &test_result;            \
    } while (0)

#define MU_RUN_TEST(test)\
    do {\
        TestResult *message = test();\
        tests_run++;\
        return message;\
    } while (0)

#endif // UNITSTUFF_MINUNIT_H
