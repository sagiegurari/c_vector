#include "test.h"
#include "vector.h"


void test_impl()
{
  assert_true(vector_is_empty(NULL));
}


int main()
{
  test_run(test_impl);
}

