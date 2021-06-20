//
// Created by dosart on 6/20/21.
//

#include "tests.h"

void run_tests() {
  test_init_table();

  test_add1();
  test_add2();
}

void test_init_table() {
  printf("test_init_table()\n");

  hash_table_t table;

  hash_table_init(&table, 31);

  assert(hash_table_count(&table)==0);
  assert(hash_table_max_count(&table)==31);

  hash_table_free(&table);
}

void test_add1() {
  printf("est_add1()\n");

  hash_table_t table;
  hash_table_init(&table, 31);

  char *name = "Dosart";
  hash_table_add(&table, name, 27);

  assert(hash_table_count(&table)==1);

  hash_table_free(&table);
}
void test_add2() {
  printf("test_add2()\n");
}
