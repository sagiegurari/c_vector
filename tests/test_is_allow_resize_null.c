#include "test.h"
#include "vector.h"


void test_impl()
{
  assert_true(!vector_is_allow_resize(NULL));
}


int main()
{
  test_run(test_impl);
}

