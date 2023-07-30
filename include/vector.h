
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

struct Entry new_entry(void *);

struct Vector new_vector();

void push_back(struct Vector *, void *);

struct Entry *get(struct Vector *, size_t);

void free_entries(struct Vector *);

void apply_to_all(struct Vector *, void (*)(void *));

#endif
