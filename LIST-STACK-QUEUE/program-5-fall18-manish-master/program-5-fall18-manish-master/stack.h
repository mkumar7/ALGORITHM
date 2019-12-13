#ifndef STACK_H
#define STACK_H

#include "list.h"
#include "vector.h"

typedef struct stacklist {
  List * data;
  Data (*peek)(struct stacklist *);
  Data (*pop)(struct stacklist *);
  void (*push)(struct stacklist *, Data);
  void (*clear)(struct stacklist *);
  void (*delete)(struct stacklist *);
} Stacklist;

Stacklist * newStacklist();

typedef struct stackvector {
  Vector * data;
  Data (*peek)(struct stackvector *);
  Data (*pop)(struct stackvector *);
  void (*push)(struct stackvector *, Data);
  void (*clear)(struct stackvector *);
  void (*delete)(struct stackvector *);
} Stackvector;

Stackvector * newStackvector();

#endif //
