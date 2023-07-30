#include "../include/vector.h"

#include <stddef.h>
#include <stdio.h>

void mutate(void *input) {
  struct Entry *entry = (struct Entry *)input;

  *(int *)entry->value += 10;
}

void show(void *input) {
  struct Entry *entry = (struct Entry *)input;

  printf("\t%d", *(int *)entry->value);
}

int main(int argc, char **argv) {
  struct Vector vector = new_vector();

  int a = 7;
  push_back(&vector, &a);
  int b = 87;
  push_back(&vector, &b);

  apply_to_all(&vector, &mutate);

  apply_to_all(&vector, &show);

  free_entries(&vector);

  return 0;
}
