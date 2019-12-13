#ifndef LIST_H
#define LIST_H

#include "data.h"

typedef struct node_s{
  Data data;
  // A pointer to the next and previous nodes
  struct node_s *prev;
  struct node_s *next;
} Node;

typedef struct list_s {
  Node * head;
  Node *tail; //A pointer to nodes at the head and tail
  void (*insert)(struct list_s *, int, Data); //a function pointer to an insert function
  Data * (*read)(struct list_s *, int); //a function pointer to a read function
  void (*remove)(struct list_s *, int); //a function pointer to an delete function
  void (*delete)(struct list_s *); //a function pointer to a destructor
} List;

List * newList();


#endif //
