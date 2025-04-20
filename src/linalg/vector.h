#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>

typedef struct {
    size_t size;
    double *data;
} Vector;

Vector *create_vector(size_t size);

void destroy_vector(Vector *vector);

int vector_scale(Vector *vector, double scalar);

#endif // VECTOR_H