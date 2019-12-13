#include <stdlib.h>
#include "vector.h"



void insertVector(Vector *vector, int index, Data data) {
    Data *new_data = NULL;
    int i=0;
    // malloc the 2n+1 geometric expansion array
    if (index>=vector->max_size) {
        int new_size = 2 * index + 1;
        new_data = malloc(sizeof(Data) * new_size);
        for(;i<vector->current_size;i++) {
            new_data[i] = vector->data[i];
        }
        // unititialized vector index
        for(i=vector->current_size;i<new_size;i++) {
            new_data[i].value = -1;
        }
        free(vector->data);
        vector->max_size = new_size;
        vector->data = new_data;
    }
    if (index >= vector->current_size) {
        vector->current_size = index + 1;
    }
    vector->data[index] = data;
}

void removeVector(Vector *vector, int idx) {
    int i = idx;
    if (idx >= vector->current_size) {
        return;
    }
    for(;i<vector->current_size-1;i++) {
        vector->data[i] = vector->data[i+1];
    }
    vector->current_size--;
}

Data * readVector(Vector * array, int index) {
    if (index >= array->max_size) {
        return NULL;
    }
    return &array->data[index];
}

void deleteVector(Vector *vector) {
    if (vector != NULL) {
        if (vector->data != NULL) {
            free(vector->data);
        }
        free(vector);
    }
}

Vector * newVector() {
    Vector *res = malloc(sizeof(Vector));
    res->current_size = 0;
    res->data = NULL;
    res->max_size = 0;
    res->insert = insertVector;
    res->read = readVector;
    res->delete = deleteVector;
    res->remove = removeVector;
    return res;
}
