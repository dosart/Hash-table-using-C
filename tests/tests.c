#include "tests.h"

void run_tests() {
  test_init_table();

  test_add1();
  test_add2();

  test_exist1();
  test_exist2();
  test_exist3();

  test_remove1();
  test_remove2();
  test_remove3();
  test_remove4();
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

  char *names[] = {"Dosart", "Ololo"};

  hash_table_t table;
  hash_table_init(&table, 31);

  hash_table_add(&table, names[0], 10);
  hash_table_add(&table, names[1], 20);

  assert(hash_table_count(&table)==2);
  hash_table_free(&table);
}

void test_exist1() {
  printf("test_exist1()\n");

  char *names[] = {"Dosart", "Ololo"};

  hash_table_t table;
  hash_table_init(&table, 31);
  hash_table_add(&table, names[0], 10);
  hash_table_add(&table, names[1], 20);

  assert(hash_table_is_exist(&table, names[0])==1);
  assert(hash_table_is_exist(&table, names[1])==1);

  hash_table_free(&table);
}

void test_exist2() {
  printf("test_exist2()\n");

  char *names[] = {"Dosart", "Ololo"};

  hash_table_t table;
  hash_table_init(&table, 31);
  hash_table_add(&table, names[0], 10);

  assert(hash_table_is_exist(&table, names[0])==1);
  assert(hash_table_is_exist(&table, names[1])==0);

  hash_table_free(&table);
}

void test_exist3() {
  printf("test_exist3()\n");

  char *names[] = {"Dosart", "Ololo"};
  hash_table_t table;
  hash_table_init(&table, 31);

  assert(hash_table_is_exist(&table, names[0])==0);
  assert(hash_table_is_exist(&table, names[1])==0);

  hash_table_free(&table);
}

void test_remove1() {
  printf("test_remove1()\n");

  char *names[] = {"Dosart", "Ololo"};
  hash_table_t table;
  hash_table_init(&table, 31);
  hash_table_add(&table, names[0], 10);
  hash_table_add(&table, names[1], 20);

  hash_table_remove(&table, names[0]);

  assert(hash_table_is_exist(&table, names[0])==0);
  assert(hash_table_is_exist(&table, names[1])==1);
  assert(hash_table_count(&table)==1);

  hash_table_free(&table);
}

void test_remove2() {
  printf("test_remove2()\n");

  char *names[] = {"Dosart", "Ololo"};
  hash_table_t table;
  hash_table_init(&table, 31);
  hash_table_add(&table, names[0], 10);
  hash_table_add(&table, names[1], 20);

  hash_table_remove(&table, names[0]);
  hash_table_remove(&table, names[1]);

  assert(hash_table_is_exist(&table, names[0])==0);
  assert(hash_table_is_exist(&table, names[1])==0);
  assert(hash_table_count(&table)==0);

  hash_table_free(&table);
}

void test_remove3() {
  printf("test_remove3()\n");

  char *names[] = {"Dosart", "Ololo"};
  hash_table_t table;
  hash_table_init(&table, 31);
  hash_table_add(&table, names[0], 10);
  hash_table_add(&table, names[1], 20);

  hash_table_remove(&table, "Hello");

  hash_table_free(&table);
}

void test_remove4() {
  printf("test_remove4()\n");

  hash_table_t table;
  hash_table_init(&table, 31);

  hash_table_remove(&table, "Hello");

  assert(hash_table_count(&table)==0);

  hash_table_free(&table);
}
