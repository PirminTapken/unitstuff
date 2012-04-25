#define MU_ASSERT(message, test)\
	do {\
		if (!(test)) {\
			return {message, 1};\
		} else {\
			return {message, 0}; \
		}\
	} while (0)
#define MU_RUN_TEST(test) do { char *message = test(); tests_run++; \
                               if (message) return message; } while (0)
extern int tests_run;

typedef struct test_result {
	char *message;
	int retval;
} test_result_type;
