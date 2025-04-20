#include "vector.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

int vector_add(Vector* dest, const Vector* src) {
    if (!dest || !src || dest->size != src->size) return -1;

    for (size_t i = 0; i < dest->size; ++i) {
        dest->data[i] += src->data[i];
    }
    return 0;
}

double vector_dot(const Vector* a, const Vector* b) {
    if (!a || !b || a->size != b->size) return -1;

    double result = 0.0;
    for (size_t i = 0; i < a->size; ++i) {
        result += a->data[i] * b->data[i];
    }
    return result;
}

double vector_norm(const Vector* v) {
    if (!v || !v->data) return -1;

    double sum = 0.0;
    for (size_t i = 0; i < v->size; ++i) {
        sum += v->data[i] * v->data[i];
    }
    return sqrt(sum);
}

