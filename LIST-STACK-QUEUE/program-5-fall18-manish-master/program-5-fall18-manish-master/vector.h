#ifndef VECTOR_H
#define VECTOR_H

#include "data.h"

typedef struct vector_s {
  Data *data;
  int current_size;
  int max_size;
  // Insert - inserts an element at the specified index.
// Use the 2n+1 geometric expansion formula to increase
// the size of your list if the index is out of the current bounds.
  void (*insert)(struct vector_s *, int, Data);
// deletes an element from the list at the specified index
  void (*remove)(struct vector_s *, int);
  void (*delete)(struct vector_s *);
// return the pointer to the data struct from the specified index,
// return NULL if the index is out of bounds, and a data struct with
// the value set to -1 if the index has not been initialized
  Data *(*read)(struct vector_s * array, int index);
} Vector;

Vector * newVector();

#endif
