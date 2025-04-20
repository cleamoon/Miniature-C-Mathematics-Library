#include "vector.h"
#include <stdlib.h>
#include <string.h>

Vector* create_vector(size_t size) {
    Vector* v = malloc(sizeof(Vector));
    if (!v) return NULL;

    v->size = size;
    v->data = malloc(size * sizeof(double));
    if (!v->data) {
        free(v);
        return NULL;
    }
    memset(v->data, 0, size * sizeof(double));
    return v;
}

void destroy_vector(Vector* v) {
    if (v) {
        if (v->data) {
            free(v->data);
        }
        free(v);
    }
}

int vector_scale(Vector* v, double scalar) {
    if (!v || !v->data) return -1;

    for (size_t i = 0; i < v->size; ++i) {
        v->data[i] *= scalar;
    }
    return 0;
}

