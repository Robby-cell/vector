
#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <stdbool.h>
#include <stddef.h>

struct Entry {
  void *value;
};

struct Vector {
  struct Entry *entries;
  size_t length;
  size_t capacity;
};

/// creates an entry with the contents provided
///   ;
///   void* gettingAdded = malloc(sizeof(ContentsOfEntry));
///   new_entry(gettingAdded);
///
struct Entry new_entry(void *);

///
/// creates a new vector
///   ;
///   struct Vector vector = new_vector();
///
struct Vector new_vector();

///
/// pushes a value to the to back, wrapped in the entry struct
///   ;
///   void *pushedBack = malloc(sizeof(const char*));
///   (const char*)*pushedBack = "hello world";
///   push_back(&vector, pushedBack);
///
void push_back(struct Vector *, void *);

///
/// gets an entry at a particular index, NULL if
/// it does not exist
///   ;
///   struct Entry* retrieved = get(&vector, 99);
///   if (retrieved != NULL) {
///     printf("%s\n", *(const char**)retrieved->value);
///   }
///
struct Entry *get(struct Vector *, size_t);

/// frees the memory allocated on the heap...
void free_entries(struct Vector *);

/// applies a function to all entries
///   ;
///   void func(void* void_entry) {
///     struct Entry* entry = (struct Entry*)void_entry;
///
///     if (entry != NULL && entry->value != NULL) {
///       printf("%s\n", *(const char**)entry->value);
///     }
///   }
///
///   apply_to_all(&vector, &func);
///   // expected output: print all values as a c string
///
void apply_to_all(struct Vector *, void (*)(void *));

#endif
