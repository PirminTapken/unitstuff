#include <minunit.h>
#include <stdio.h>

int tests_run = 0;

int add_two_numbers(int a, int b)
{
	return a + b;
}

test_result_type *test_one_plus_one(void)
{ 
	MU_ASSERT("test 1+1", 2 == 1+1);
	return {'',0};
}

test_result_type *test_adding(void)
{
	MU_ASSERT("test adding 1 and 3", 2 == add_two_numbers(1, 3));
	return {'',0};
}

char *test_suite(void)
{
    MU_RUN_TEST(test_one_plus_one);
    MU_RUN_TEST(test_adding);
    return {'',0};
}

int main(int ac, char **av)
{
  char *result = test_suite();

  printf("number of tests run: %d\n", tests_run);
  if (result) printf("FAIL: %s\n", result);
  return 0 != result;
}
