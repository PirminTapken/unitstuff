#include <minunit.h>
#include <stdio.h>

int tests_run = 0;
TestResult **result_stack;

int add_two_numbers(int a, int b)
{
    return a + b;
}

TestResult *test_one_plus_one(void)
{ 
    MU_ASSERT("test 1+1", 2 == 1+1);
    return NULL;
}

TestResult *test_adding(void)
{
    MU_ASSERT("test adding 1 and 3", 4 == add_two_numbers(1, 3));
    return NULL;
}

TestResult *test_suite(void)
{
    MU_RUN_TEST(test_one_plus_one);
    MU_RUN_TEST(test_adding);
    return NULL;
}

int main(int ac, char **av)
{
    TestResult *result = test_suite();

    printf("number of tests run: %d\n", tests_run);
    if ((*result).retval) printf("FAIL: %s\n", (*result).message);
    return 0 != result;
}
