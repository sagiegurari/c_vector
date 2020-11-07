#include "test.h"
#include "vector.h"
#include <stdlib.h>

enum Type
{
  PREPEND,
  PUSH,
  INSERT,
  SET,
};

struct Item
{
  enum  Type type;
};


void test_impl()
{
  struct Vector *vector = vector_new_with_options(2, true);

  size_t        loops = 100;

  for (size_t index = 0; index < loops; index++)
  {
    struct Item *item = malloc(sizeof(struct Item));
    item->type = PUSH;
    assert_true(vector_push(vector, item));

    item       = malloc(sizeof(struct Item));
    item->type = PREPEND;
    assert_true(vector_prepend(vector, item));

    item       = malloc(sizeof(struct Item));
    item->type = INSERT;
    assert_true(vector_insert(vector, vector_size(vector), item));

    item       = malloc(sizeof(struct Item));
    item->type = SET;
    item       = (struct Item *)vector_set(vector, vector_size(vector) - 1, item);
    assert_true(item->type == INSERT);

    item = (struct Item *)vector_remove(vector, 0);
    assert_true(item->type == PREPEND);

    vector_shrink(vector);
  }

  void   **array = vector_to_array(vector);
  size_t size    = vector_size(vector);
  assert_num_equal(size, loops * 2);

  vector_clear(vector);
  size = vector_size(vector);
  assert_num_equal(size, 0);
  assert_true(vector_is_empty(vector));

  vector_release(vector);
  free_deep(array, size);
} /* test_impl */


int main()
{
  test_run(test_impl);
}

