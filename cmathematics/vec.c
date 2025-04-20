#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "vec.h"

const vec VEC_UNDEFINED = {0, NULL};

vec allocateVec(unsigned int dim) {
    vec ret;

    ret.dim = dim;
    ret.elements = malloc(dim * sizeof(float));

    return ret;
}

vec constructDefaultVector(unsigned int dim, float val) {
    vec ret = allocateVec(dim);

    for (unsigned int i = 0; i < dim; i++) {
        ret.elements[i] = val;
    }

    return ret;
}

vec constructEmptyVector(unsigned int dim) {
    return constructDefaultVector(dim, 0.0f);
}

vec newVector(unsigned int dim, ...) {
    vec ret = allocateVec(dim);

    va_list list;
    va_start(list, dim);

    for (int i = 0; i < dim; i++) {
        ret.elements[i] = va_arg(list, double);
    }

    va_end(list);

    return ret;
}

vec copyVec(vec v) {
    return v;
}

vec copyPtrVec(vec *v) {
    vec ret;
    memcpy(&ret, v, sizeof(vec));
    return ret;
}

void printVec(vec v) {
    printf("[ ");
    for (unsigned int i = 0; i < v.dim; i++) {
        printf("%f", v.elements[i]);

        if (i < v.dim - 1) {
            printf(", ");
        } else {
            printf(" ");
        }
    }
    printf("]\n");
}

bool vecIsEquals(vec v1, vec v2) {
    if(v1.dim == v2.dim) {
        for (unsigned int i = 0; i < v1.dim; i++) {
            if (v1.elements[i] != v2.elements[i]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

vec vecScalarMultiplication(vec v, float k) {
    vec ret = allocateVec(v.dim);

    for (unsigned int i = 0; i < ret.dim; i++) {
        ret.elements[i] = v.elements[i] * k;
    }

    return ret;
}

void vecScalarMultiplicationBy(vec *v, float k) {
    for (unsigned int i = 0; i < v->dim; i++) {
        v->elements[i] *= k;
    }
}

vec vecScalarDivision(vec v, float k) {
    vec ret = allocateVec(v.dim);

    for (unsigned int i = 0; i < ret.dim; i++) {
        ret.elements[i] = v.elements[i] / k;
    }

    return ret;
}

void vecScalarDivisionBy(vec *v, float k) {
    for (unsigned int i = 0; i < v->dim; i++) {
        v->elements[i] /= k;
    }
}

vec vecPower(vec v, float k) {
    vec ret = allocateVec(v.dim);

    for (unsigned int i = 0; i < ret.dim; i++) {
        ret.elements[i] = powf(v.elements[i], k);
    }

    return ret;
}

void vecPowerOf(vec *v, float k)  {
    for (unsigned int i = 0; i < v->dim; i++) {
        v->elements[i] = powf(v->elements[i], k);
    }
}

vec vecAdd(vec v1, vec v2) {
    if (v1.dim != v2.dim) {
        return VEC_UNDEFINED;
    }

    vec ret = allocateVec(v1.dim);

    for(unsigned int i = 0; i < ret.dim; i++) {
        ret.elements[i] = v1.elements[i] + v2.elements[i];
    }

    return ret;
}

bool vecAddTo(vec *v1, vec v2) {
    if (v1->dim != v2.dim) {
        return false;
    }

    for(unsigned int i = 0; i < v1->dim; i++) {
        v1->elements[i] += v2.elements[i];
    }

    return true;
}

vec vecSubtract(vec v1, vec v2) {
    if (v1.dim != v2.dim) {
        return VEC_UNDEFINED;
    }

    vec ret = allocateVec(v1.dim);

    for(unsigned int i = 0; i < ret.dim; i++) {
        ret.elements[i] = v1.elements[i] - v2.elements[i];
    }

    return ret;
}

bool vecSubtractFrom(vec *v1, vec v2) {
    if (v1->dim != v2.dim) {
        return false;
    }

    for(unsigned int i = 0; i < v1->dim; i++) {
        v1->elements[i] -= v2.elements[i];
    }

    return true;
}

vec vecMultiply(vec v1, vec v2) {
    if (v1.dim != v2.dim) {
        return VEC_UNDEFINED;
    }

    vec ret = allocateVec(v1.dim);

    for(unsigned int i = 0; i < ret.dim; i++) {
        ret.elements[i] = v1.elements[i] * v2.elements[i];
    }

    return ret;
}

bool vecMultiplyTo(vec *v1, vec v2) {
    if (v1->dim != v2.dim) {
        return false;
    }

    for(unsigned int i = 0; i < v1->dim; i++) {
        v1->elements[i] *= v2.elements[i];
    }

    return true;
}

vec vecDivide(vec v1, vec v2) {
    if (v1.dim != v2.dim) {
        return VEC_UNDEFINED;
    }

    vec ret = allocateVec(v1.dim);

    for(unsigned int i = 0; i < ret.dim; i++) {
        ret.elements[i] = v1.elements[i] / v2.elements[i];
    }

    return ret;
}

bool vecDivideBy(vec *v1, vec v2) {
    if (v1->dim != v2.dim) {
        return false;
    }

    for(unsigned int i = 0; i < v1->dim; i++) {
        v1->elements[i] /= v2.elements[i];
    }

    return true;
}

float vecDotProd(vec v1, vec v2) {
    float ret = 0.0f;

    if (v1.dim == v2.dim) {
        for (unsigned int i = 0; i < v1.dim; i++) {
            ret += v1.elements[i] * v2.elements[i];
        }
    }

    return ret;
}

bool vecIsOrthogonal(vec v1, vec v2) {
    return v1.dim == v2.dim ? vecDotProd(v1, v2) == 0.0f : false;
}

vec vecCrossProd(vec v1, vec v2) {
    if (v1.dim != 3 || v2.dim != 3) {
        return VEC_UNDEFINED;
    }
    
    vec ret = allocateVec(3);

    ret.elements[0] = (v1.elements[1] * v2.elements[2]) - (v1.elements[2] * v2.elements[1]);
    ret.elements[1] = (v1.elements[2] * v2.elements[0]) - (v1.elements[0] * v2.elements[2]);
    ret.elements[2] = (v1.elements[0] * v2.elements[1]) - (v1.elements[1] * v2.elements[0]);
    
    return ret;
}

float vecMagnitude(vec v) {
    return sqrt(vecMagnitudeSquared(v));
}

float vecMagnitudeSquared(vec v) {
    float ret = 0.0f;

    for (unsigned int i = 0; i < v.dim; i++) {
        ret += v.elements[i] * v.elements[i];
    }

    return ret;
}

vec vecNormalized(vec v) {
    vec ret = allocateVec(v.dim);
    float mag = vecMagnitude(v);

    for (unsigned int i = 0; i < ret.dim; i++) {
        ret.elements[i] = v.elements[i] / mag;
    }

    return ret;
}

void vecNormalize(vec *v) {
    float mag = vecMagnitude(*v);
    
    for(unsigned int i = 0; i < v->dim; i++) {
        v->elements[i] /= mag;
    }
}
