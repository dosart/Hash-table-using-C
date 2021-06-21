/*!
@file
@brief  Header file for hash table
This file contains the definition of the data structure hash table
*/
#ifndef HASH_TABLE_INCLUDE_HASH_TABLE_H_
#define HASH_TABLE_INCLUDE_HASH_TABLE_H_

#include <stddef.h>
#include <malloc.h>
#include <string.h>

/**
 * @defgroup hash_table(chaining)
 *
 * @brief Item of hash table
 *
 * @warning This structure created only for educational goals
 */
typedef struct hash_table_node_t {
  char *key;
  int value;

  struct hash_table_node_t *next;
} node_t;

/**
 * @ingroup hash_table(chaining)
 *
 * @brief Hash table data structure

 * @warning This structure created only for educational goals
 */
typedef struct hash_table_t {
  node_t **data;
  size_t max_count; ///< max count elements of table
  size_t count; ///< current count elements of table
} hash_table_t;

/**
 * @ingroup hash_table(chaining)
 *
 * @brief Init hash table data structure.
 *
 * @param table Pointer to hash table data structure.
 * @param max_count Max count elements of hash table
 */
void hash_table_init(hash_table_t *table, size_t max_count);

/**
 * @ingroup hash_table(chaining)
 *
 * @brief Returns count elements of hash table.
 *
 * @param table Pointer to hash table data structure.
 *
 * @returns count elements of hash table.
 */
size_t hash_table_count(hash_table_t *table);

/**
 * @ingroup hash_table(chaining)
 *
 * @brief Returns max count elements of hash table.
 *
 * @param table Pointer to hash table data structure.
 *
 * @returns max count elements of hash table.
 */
size_t hash_table_max_count(hash_table_t *table);

/**
 * @ingroup hash_table(chaining)
 *
 * @brief Frees memory in data structure.
 *
 * @param table Pointer to hash table data structure.
 */
void hash_table_free(hash_table_t *table);

/**
 * @ingroup hash_table(chaining)
 *
 * @brief Frees memory in data structure.
 *
 * @param table Pointer to hash table data structure.
 */
unsigned long elf_hash(const unsigned char *s, size_t max_size);

/**
 * @ingroup hash_table(chaining)
 *
 * @brief Add the given key and object to hash table. If key exists, update the value.
 *
 * @param table Pointer to hash table data structure.
 * @param key Key for value.
 * @param value Value by key.
 */
void hash_table_add(hash_table_t *table, char *key, int value);

/**
 * @ingroup hash_table(chaining)
 *
 * @brief Returns true if the given key exists in the table.
 *
 * @param table Pointer to hash table data structure.
 * @param key Key for search.
 */
unsigned short hash_table_is_exist(hash_table_t *table, char *key);

/**
 * @ingroup hash_table(chaining)
 *
 * @brief Removes the value associated with key from the table.
 *
 * @param table Pointer to hash table data structure.
 * @param key Key for remove.
 */
void hash_table_remove(hash_table_t *table, char *key);

#endif //HASH_TABLE_INCLUDE_HASH_TABLE_H_
