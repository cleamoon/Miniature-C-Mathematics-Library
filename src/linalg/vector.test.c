#include "vector.h"
#include <stdio.h>
#include <assert.h>
#include <math.h>

int main() {
    Vector *v = create_vector(5);
    assert(v != NULL);
    assert(v->size == 5);
    
    for (size_t i = 0; i < v->size; i++) {
        v->data[i] = (double)(i + 1);
    }

    int error = vector_scale(v, 2);
    assert(error == 0);

    for (size_t i = 0; i < v->size; i++) {
        assert(v->data[i] == (double)(i + 1) * 2);
    }
    
    for (size_t i = 0; i < v->size; i++) {
        double expected = (double)(i + 1) * 2;
        double actual = v->data[i];
        assert(fabs(expected - actual) < 1e-6);
    }

    Vector *w = create_vector(5);
    assert(w != NULL);
    assert(w->size == 5);

    for (size_t i = 0; i < w->size; i++) {
        w->data[i] = (double)(i + 1);
    }

    error = vector_add(v, w);
    assert(error == 0);

    for (size_t i = 0; i < v->size; i++) {
        assert(v->data[i] == (double)(i + 1) * 2 + (double)(i + 1));
    }

    double dot = vector_dot(v, w);  // 1 * 3 + 2 * 6 + 3 * 9 + 4 * 12 + 5 * 15 = 165
    assert(fabs(dot - 165) < 1e-6);

    double norm = vector_norm(w);   // sqrt(1^2 + 2^2 + 3^2 + 4^2 + 5^2) = sqrt(55)
    assert(fabs(norm - sqrt(55)) < 1e-6);
    
    destroy_vector(v);
    destroy_vector(w);

    printf("All tests passed!\n");
    return 0;
}
