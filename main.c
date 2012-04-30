#include <minunit.h>
#include <stdio.h>

int tests_run = 0;
int tests_failed = 0;

int add_two_numbers(int a, int b)
{
	return a + b;
}

char *test_one_plus_one(void)
{ 
	MU_ASSERT("test 1+1", 2 == 1+1);
	return 0;
}

char *test_adding(void)
{
	MU_ASSERT("test adding 1 and 3", 2 == add_two_numbers(1, 3));
	return 0;
}

void event_handler(char *message, char success)
{
    tests_run++;
    printf("Test %d...", tests_run);
    if (!(success)) {
        tests_failed++;
        printf("FAIL: %s\n", message);
    } else {
        printf("done.\n");
    }
}

char test_suite(void)
{
    MU_RUN_TESTS(event_handler,
        test_one_plus_one,
        test_adding);
    return 0;
}

int main(int ac, char **av)
{
    char result = test_suite();

    printf("Number of tests run: %d\n", tests_run);
    printf("Tests failed: %d\n", tests_failed);
    return result;
}
