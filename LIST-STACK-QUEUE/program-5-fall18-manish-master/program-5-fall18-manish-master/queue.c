#include "queue.h"
#include <stdlib.h>

void enqueueQueuelist(struct queuelist *ql, Data data) {
    ql->data->insert(ql->data, -1, data);
}

Data dequeueQueuelist(struct queuelist *ql) {
    Data res;
    res.value = -1;
    while (ql->data->head == NULL) {
        return res;
    }
    res = ql->data->head->data;
    ql->data->remove(ql->data, 0);
    return res;
}

Data peekQueuelist(struct queuelist *ql) {
    Data res;
    res.value = -1;
    while (ql->data->head == NULL) {
        return res;
    }
    res = ql->data->head->data;
    return res;
}

void clearQueuelist(struct queuelist *ql) {
    while (ql->data->head != NULL) {
        ql->data->remove(ql->data, 0);
    }
}

void deleteQueuelist(struct queuelist *ql) {
    ql->data->delete(ql->data);
    free(ql);
}

Queuelist * newQueuelist() {
    Queuelist *res = malloc(sizeof(Queuelist));
    res->data = newList();
    res->delete = deleteQueuelist;
    res->peek = peekQueuelist;
    res->enqueue = enqueueQueuelist;
    res->dequeue = dequeueQueuelist;
    res->clear = clearQueuelist;
    return res;
}

void pushQueuevector(struct queuevector *qv, Data value) {
    qv->data->insert(qv->data, qv->data->current_size, value);
}

Data popQueuevector(struct queuevector *qv) {
    Data res;
    res.value = -1;
    if (qv->data->current_size == 0) {
        return res;
    }
    res = qv->data->data[0];
    qv->data->remove(qv->data, 0);
    return res;
}

Data peekQueuevector(struct queuevector * qv) {
    Data res;
    res.value = -1;
    if (qv->data->current_size == 0) {
        return res;
    }
    res = qv->data->data[0];
    return res;
}

void clearQueuevector(struct queuevector *qv) {
    qv->data->current_size = 0;
}

void deleteQueuevector(struct queuevector *qv) {
    qv->data->delete(qv->data);
    free(qv);
}

Queuevector * newQueuevector() {
    Queuevector *res = malloc(sizeof(Queuevector));
    res->data = newVector();
    res->delete = deleteQueuevector;
    res->peek = peekQueuevector;
    res->enqueue = pushQueuevector;
    res->dequeue = popQueuevector;
    res->clear = clearQueuevector;
    return res;
}
