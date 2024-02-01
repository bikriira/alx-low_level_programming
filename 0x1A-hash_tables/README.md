# 0x1A. C - Hash tables
- C, Algorithm, Data structure

# Learning Objectives
At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

## General
- What is a hash function
- What makes a good hash function
- What is a hash table, how do they work and how to use them
- What is a collision and what are the main ways of dealing with collisions in the context of a hash table
- What are the advantages and drawbacks of using hash tables
- What are the most common use cases of hash tables
- Copyright - Plagiarism
- You are tasked to come up with solutions for the tasks below yourself to meet with the above learning objectives.
- You will not be able to meet the objectives of this or any following project by copying and pasting someone else’s work.
- You are not allowed to publish any content of this project.
- Any form of plagiarism is strictly forbidden and will result in removal from the program.
# Requirements
## General
- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
- All your files should end with a new line
- A README.md file, at the root of the folder of the project is mandatory
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- You are not allowed to use global variables
- No more than 5 functions per file
- You are allowed to use the C standard library
- The prototypes of all your functions should be included in your header file called hash_tables.h
- Don’t forget to push your header file
- All your header files should be include guarded
# More Info
## Data Structures
- Please use these data structures for this project:
```
/**
 * struct hash_node_s - Node of a hash table
 *
 * @key: The key, string
 * The key is unique in the HashTable
 * @value: The value corresponding to a key
 * @next: A pointer to the next node of the List
 */
typedef struct hash_node_s
{
     char *key;
     char *value;
     struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - Hash table data structure
 *
 * @size: The size of the array
 * @array: An array of size @size
 * Each cell of this array is a pointer to the first node of a linked list,
 * because we want our HashTable to use a Chaining collision handling
 */
typedef struct hash_table_s
{
     unsigned long int size;
     hash_node_t **array;
} hash_table_t;
```

# Tests
We strongly encourage you to work all together on a set of tests

## Tasks

### [0-hash_table_create](0-hash_table_create.c)

This function will create a new hash table

* Prototype: `hash_table_t *hash_table_create(unsigned long int size);`
	* where `size` is the size of the array
* Returns a pointer to the newly created hash table
* If something went wrong, your function should return `NULL`

### [1-djb2](1-djb2.c)

This implements the djb2 algorithum hash function.

* Prototype: `unsigned long int hash_djb2(const unsigned char *str);`
* You are allowed to copy and paste the function from [this page](http://www.cse.yorku.ca/~oz/hash.html)


### [2-key_index](2-key_index.c)

 function that gives you the index of a key.


 * Prototype: `unsigned long int key_index(const unsigned char *key, unsigned long int size);`
 	* where `key` is the key
 	* and `size` is the size of the array of the hash table
  * This function should use the `hash_djb2` function that you wrote
 earlier
 * Returns the index at which the key/value pair should be stored in the array
 of the hash table
 * You will have to use this hash function for all the next tasks

### [3-hash_table_set](3-hash_table_set.c)

 function that adds an element to the hash table.

 * Prototype: `int hash_table_set(hash_table_t *ht, const char *key,
		 const char *value);`
  * Where `ht` is the hash table you want to add or update the key/value to
  * `key` is the key. `key` can not be an empty string
  * and `value` is the value associated with the key. `value` must be duplicated. `value` can be an empty
 string
 * Returns: `1` if it succeeded, `0` otherwise
 * In case of collision, add the new node at the beginning of the list

### [4-hash_table_get](4-hash_table_get.c)

 function that retrieves a value associated with a key.


 * Prototype: `char *hash_table_get(const hash_table_t *ht, const char *key);`
  * where `ht` is the hash table you want to look into
  * and `key` is the key you are looking for
 * Returns the value associated with the element, or `NULL` if `key` couldn't be found

### [5-hash_table_print](5-hash_table_print.c)

 function that prints a hash table.


* Prototype: `void hash_table_print(const hash_table_t *ht);`
 * where `ht` is the hash table
 * You should print the key/value in the order that they appear in the array of hash table

* Order: array, list

 * Format: see example
 * If `ht` is NULL, don't print anything

### [6-hash_table_delete](6-hash_table_delete.c)

 function that deletes a hash table.

* Prototype: `void hash_table_delete(hash_table_t *ht);`
 * where `ht` is the hash table


