#include "test.h"
#include "vector.h"


void test_impl()
{
  assert_num_equal(vector_capacity(NULL), 0);
}


int main()
{
  test_run(test_impl);
}

