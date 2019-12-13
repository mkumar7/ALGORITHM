#include "list.h"
#include <stdlib.h>

void insertList(List * list, int index, Data value) {
    Node *tmp = list->head;
    while (index != 0 && tmp != NULL) {
        tmp = tmp->next;
        index--;
    }
    Node * node = malloc(sizeof(Node));
    node->next = NULL;
    node->prev = NULL;
    node->data = value;
    // emtpy
    if (list->tail == NULL) {
        list->head = list->tail = node;
        return;
    }
    // insert to head
    if (tmp == list->head) {
        node->next = list->head;
        list->head->prev = node;
        list->head = node;
        return;
    }
    // insert to tail
    if (tmp == NULL) {
        node->prev = list->tail;
        list->tail->next = node;
        list->tail = node;
    }
    else {
        tmp->prev->next = node;
        node->prev = tmp->prev;
        node->next = tmp;
        tmp->prev = node;
    }
}

void removeData(List * list, int index) {
    Node *tmp = list->head;
    while (index > 0 && tmp != NULL) {
        tmp = tmp->next;
        index--;
    }
    if (tmp == NULL) {
        return;
    }
    if (tmp == list->head && tmp == list->tail) {
        list->head = list->tail = NULL;
        free(tmp);
        return;
    }
    if (tmp == list->head) {
        tmp->next->prev = NULL;
        list->head = tmp->next;
        free(tmp);
        return;
    }
    if (tmp == list->tail) {
        tmp->prev->next = NULL;
        list->tail = tmp->prev;
        free(tmp);
        return;
    }
    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;
    free(tmp);
}

Data * readData(List * list, int index) {
    Node *tmp = list->head;
    while (index > 0 && tmp != NULL) {
        tmp = tmp->next;
        index--;
    }
    if(tmp == NULL) {
        return NULL;
    }
    return &(tmp->data);
}

void deleleList(struct list_s *list) {
    while (list->head != NULL) {
        list->remove(list, 0);
    }
    free(list);
}

List * newList() {
    List *res = malloc(sizeof(List));
    res->head = res->tail = NULL;
    res->insert = insertList;
    res->read = readData;
    res->delete = deleleList;
    res->remove = removeData;
    return res;
}
