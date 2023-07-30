#include "../include/vector.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void mutate(void *input) {
  struct Entry *entry = (struct Entry *)input;

  *(int *)entry->value += 10;
}

void show(void *input) {
  struct Entry *entry = (struct Entry *)input;

  printf("\t%d", *(int *)entry->value);
}

// another idea...
void *create_ptr(int value) {
  void *ptr = malloc(sizeof(value));
  *(int *)ptr = value;
  return ptr;
}

// and ofc...
void free_ptr(void *input) {
  struct Entry *entry = (struct Entry *)input;

  if (input != NULL && entry->value != NULL)
    free(entry->value);
}

int main(int argc, char **argv) {
  struct Vector vector = new_vector();

  push_back(&vector, create_ptr(89));
  push_back(&vector, create_ptr(44));

  apply_to_all(&vector, &mutate);

  apply_to_all(&vector, &show);

  apply_to_all(&vector, &free_ptr);

  free_entries(&vector);

  return 0;
}
