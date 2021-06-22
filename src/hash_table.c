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

void hash_table_free(hash_table_t *table) {
  if (table) {
    for (size_t i = 0; i < table->max_count; ++i) {
      node_t *node = table->data[i];
      node_t *next = NULL;
      while (node) {
        next = node->next;
        free(node);
        node = next;
      }
    }
    free(table->data);
  }
}

unsigned long elf_hash(const unsigned char *s, size_t max_size) {
  unsigned long h = 0;
  unsigned long high = 0;
  while (*s) {
    h = (h << 4) + *s++;
    if ((high = h & 0xF0000000))
      h ^= high >> 24;
    h &= ~high;
  }
  return h%max_size;
}

void hash_table_add(hash_table_t *table, char *key, int value) {
  if (table) {
    node_t *node = malloc(sizeof(node_t));
    node->key = key;
    node->value = value;

    size_t index = elf_hash((unsigned char *) key, table->max_count);
    node->next = table->data[index];
    table->data[index] = node;

    ++table->count;
  }
}

unsigned short hash_table_is_exist(hash_table_t *table, char *key) {
  int *result = hash_table_is_get(table, key);
  return result!=NULL ? 1 : 0;
}

int *hash_table_is_get(hash_table_t *table, char *key) {
  if (table) {
    size_t index = elf_hash((unsigned char *) key, table->max_count);
    for (node_t *cur = table->data[index]; cur; cur = cur->next) {
      if (strcmp(cur->key, key)==0)
        return &cur->value;
    }
  }
  return NULL;
}

void hash_table_remove(hash_table_t *table, char *key) {
  if (table) {
    size_t index = elf_hash((unsigned char *) key, table->max_count);
    node_t *prev = NULL;
    for (node_t *cur = table->data[index]; cur; cur = cur->next) {
      if (strcmp(cur->key, key)==0) {
        if (prev) {
          prev->next = cur->next;
        } else {
          table->data[index] = cur->next;
        }
        free(cur);
        --table->count;
        return;
      }
    }
  }
}
