//
// Created by dosart on 6/20/21.
//

#include "tests.h"

void run_tests() {
  test_init_table();
}

void test_init_table() {
  printf("test_init_table()\n");

  hash_table_t table;

  hash_table_init(&table, 31);

  assert(hash_table_count(&table)==0);
  assert(hash_table_max_count(&table)==31);
}
