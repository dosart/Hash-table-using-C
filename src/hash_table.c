#include "hash_table.h"

void hash_table_init(hash_table_t *table, size_t max_count) {
  if (table) {
    table->data = malloc(max_count*sizeof(node_t *));
    if (table->data) {
      table->max_count = max_count;
      table->count = 0;
      for (size_t i = 0; i < max_count; ++i) {
        table->data[i] = NULL;
      }
    }
  }
}
size_t hash_table_count(hash_table_t *table) {
  if (table) {
    return table->count;
  }
  return 0;
}

size_t hash_table_max_count(hash_table_t *table) {
  if (table) {
    return table->max_count;
  }
  return 0;
}
