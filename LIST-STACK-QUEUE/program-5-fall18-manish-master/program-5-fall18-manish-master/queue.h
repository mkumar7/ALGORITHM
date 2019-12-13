
#ifndef QUEUE_H
#define QUEUE_H

#include "vector.h"
#include "list.h"

typedef struct queuelist {
  List * data;
  Data (*peek)(struct queuelist *);
  Data (*dequeue)(struct queuelist *);
  void (*enqueue)(struct queuelist *, Data);
  void (*clear)(struct queuelist *);
  void (*delete)(struct queuelist * s);
} Queuelist;

Queuelist * newQueuelist();


typedef struct queuevector {
  Vector * data;
  Data (*peek)(struct queuevector *);
  Data (*dequeue)(struct queuevector *);
  void (*enqueue)(struct queuevector *, Data);
  void (*clear)(struct queuevector *);
  void (*delete)(struct queuevector * s);
} Queuevector;

Queuevector * newQueuevector();


#endif //
