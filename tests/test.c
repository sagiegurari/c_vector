#include "test.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void test_run(void (*fn)(void))
{
  printf("Test ... ");
  fn();
  printf("Done\n");
}


void test_fail()
{
  printf(" Error\n");
  exit(1);
}


void assert_true(bool value)
{
  if (!value)
  {
    test_fail();
  }
}


void assert_num_equal(size_t value1, size_t value2)
{
  if (value1 != value2)
  {
#ifdef linux
    printf("Assert Failed, value: %zu not equals to value: %zu", value1, value2);
#endif
    test_fail();
  }
}


void assert_string_equal(char *value1, char *value2)
{
  if (strcmp(value1, value2) != 0)
  {
    printf("Assert Failed, value: %s not equals to value: %s", value1, value2);
    test_fail();
  }
}


void free_deep(void **array, size_t size)
{
  if (array == NULL)
  {
    return;
  }

  for (size_t index = 0; index < size; index++)
  {
    void *value = array[index];
    if (value != NULL)
    {
      free(value);
    }
  }

  free(array);
}

