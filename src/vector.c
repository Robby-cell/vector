
#include "../include/vector.h"
#include <memory.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct Entry new_entry(void *value) {
  struct Entry output = (struct Entry){
      .value = value,
  };
  return output;
}

struct Vector new_vector() {
  struct Vector output = (struct Vector){
      .entries = NULL,
      .length = 0,
      .capacity = 0,
  };

  return output;
}

void push_back(struct Vector *vector, void *value) {
  struct Entry answer;

  if (!(vector->capacity > vector->length)) {
    void *new_allocation = realloc(
        (void *)vector->entries, sizeof(struct Entry) * (vector->capacity + 1));

    if (new_allocation != NULL) {
      vector->capacity += 1;
      vector->entries = (struct Entry *)new_allocation;
    } else {
      fputs("Reallocation failed. could not extend the vector.", stderr);
    }
  };

  answer = new_entry(value);

  vector->entries[vector->length] = answer;
  vector->length += 1;
}

struct Entry pop_back(struct Vector *vector) {
  if (vector->length < 1)
    return (struct Entry){
        .value = NULL,
    };

  struct Entry popped = (struct Entry)vector->entries[vector->length - 1];

  vector->length -= 1;

  return popped;
}

struct Entry *get(struct Vector *vector, size_t index) {
  if (vector->length > index)
    return &vector->entries[index];
  return NULL;
}

void free_entries(struct Vector *vector) {
  if (vector->entries != NULL) {
    free(vector->entries);
  }
}

///
/// applies function 'f' to all elements within
/// the length of the vector
///
void apply_to_all(struct Vector *vector, void (*f)(void *)) {
  for (size_t i = 0; i < vector->length; ++i) {
    struct Entry *current = &vector->entries[i];

    if (current != NULL) {
      (*f)((void *)current);
    }
  }
}
