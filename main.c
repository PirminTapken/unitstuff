#include <minunit.h>
#include <stdio.h>
#include <stdlib.h>

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

void event_handler(char *message, char success, Test_Data *testdata)
{
    testdata->tests_run++;
    printf("Test %d...", testdata->tests_run);
    if (!(success)) {
        testdata->tests_failed++;
        printf("FAIL: %s\n", message);
    } else {
        printf("done.\n");
    }
}

Test_Data *test_suite(void)
{
    Test_Data *testdata = malloc(sizeof(Test_Data));
    testdata->tests_run = 0;
    testdata->tests_failed = 0;
    MU_RUN_TESTS(event_handler,
        testdata,
        test_one_plus_one,
        test_adding);
    return testdata;
}

int main(int ac, char **av)
{
    Test_Data *result = test_suite();

    printf("Number of tests run: %d\n", result->tests_run);
    printf("Tests failed: %d\n", result->tests_failed);
    return result->tests_failed;
}
