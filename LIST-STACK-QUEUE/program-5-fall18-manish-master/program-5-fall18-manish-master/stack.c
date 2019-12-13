#include "stack.h"
#include <stdlib.h>

void pushStacklist(struct stacklist *sl, Data value) {
    sl->data->insert(sl->data, -1, value);
}

Data popStacklist(struct stacklist *sl) {
    int cnt = 0;
    Data res;
    res.value = -1;
    Node *tmp = sl->data->head;
    while (tmp!=NULL) {
        cnt++;
        tmp = tmp->next;
    }
    if (cnt == 0) {
        return res;
    }
    res = sl->data->tail->data;
    sl->data->remove(sl->data, cnt-1);
    return res;
}

Data peekStacklist(struct stacklist *sl) {
    Data res;
    res.value = -1;
    if (sl->data->tail == NULL) {
        return res;
    }
    return sl->data->tail->data;
}

void clearStacklist(struct stacklist *sl) {
    while (sl->data->head != NULL) {
        sl->data->remove(sl->data, 0);
    }
}

void deleteStacklist(struct stacklist *sl) {
    sl->data->delete(sl->data);
    free(sl);
}

Stacklist * newStacklist() {
    Stacklist *sl = malloc(sizeof(Stacklist));
    sl->data = newList();
    sl->push = pushStacklist;
    sl->pop = popStacklist;
    sl->peek = peekStacklist;
    sl->delete = deleteStacklist;
    sl->clear = clearStacklist;
    return sl;
}

void pushStackvector(struct stackvector *sv, Data value) {
    sv->data->insert(sv->data, sv->data->current_size, value);
}

Data popStackvector(struct stackvector *sv) {
    Data res;
    res.value = -1;
    if (sv->data->current_size == 0) {
        return res;
    }
    res = sv->data->data[sv->data->current_size - 1];
    sv->data->remove(sv->data, sv->data->current_size - 1);
    return res;
}

Data peekStackvector(struct stackvector *sv) {
    Data res;
    res.value = -1;
    if (sv->data->current_size == 0) {
        return res;
    }
    res = sv->data->data[sv->data->current_size - 1];
    return res;
}

void clearStackvector(struct stackvector *sv) {
    sv->data->current_size = 0;
}

void deleteStackvector(struct stackvector *sv) {
    sv->data->delete(sv->data);
    free(sv);
}

Stackvector * newStackvector() {
    Stackvector *sv = malloc(sizeof(Stackvector));
    sv->data = newVector();
    sv->push = pushStackvector;
    sv->pop = popStackvector;
    sv->peek = peekStackvector;
    sv->delete = deleteStackvector;
    sv->clear = clearStackvector;
    return sv;
}
