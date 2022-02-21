#include <stdarg.h>
#include <stdio.h>
#include "cmathematics.h"

#ifndef VEC_H
#define VEC_H

typedef struct {
    unsigned int dim;
    float* elements;
} vec;

extern const vec VEC_UNDEFINED;

vec allocate(unsigned int dim);

vec constructDefaultVector(unsigned int dim, float val);

vec constructEmptyVector(unsigned int dim);

vec newVector(unsigned int dim, ...);

#define vector(...) newVector(NUMARGS(float, __VA_ARGS__), ##__VA_ARGS__)

vec copy(vec v);

vec copyPtr(vec *v); 

void print(vec v);

bool equals(vec v1, vec v2);

vec scalarMultiplication(vec v, float k);

void scalarMultiplicationBy(vec *v, float k);

vec scalarDivision(vec v, float k);

void scalarDivisionBy(vec *v, float k);

vec power(vec v, float k);

void powerOf(vec *v, float k);

vec add(vec v1, vec v2);

bool addTo(vec *v1, vec v2);

vec subtract(vec v1, vec v2);

bool subtractFrom(vec *v1, vec v2);

vec multiply(vec v1, vec v2);

bool multiplyTo(vec *v1, vec v2);

vec divide(vec v1, vec v2);

bool divideBy(vec *v1, vec v2);

float dot(vec v1, vec v2); 

bool orthogonal(vec v1, vec v2);

vec cross(vec v1, vec v2);

float magnitude(vec v);

float magnitudeSquared(vec v);

vec normalized(vec v);

void normalize(vec *v);

#endif