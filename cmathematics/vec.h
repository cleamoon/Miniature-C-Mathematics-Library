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

vec allocateVec(unsigned int dim);

vec constructDefaultVector(unsigned int dim, float val);

vec constructEmptyVector(unsigned int dim);

vec newVector(unsigned int dim, ...);

#define vector(...) newVector(NUMARGS(float, __VA_ARGS__), ##__VA_ARGS__)

vec copyVec(vec v);

vec copyVecPtr(vec *v); 

void printVec(vec v);

bool vecIsEquals(vec v1, vec v2);

vec vecScalarMultiplication(vec v, float k);

void vecScalarMultiplicationBy(vec *v, float k);

vec vecScalarDivision(vec v, float k);

void vecScalarDivisionBy(vec *v, float k);

vec vecPower(vec v, float k);

void vecPowerOf(vec *v, float k);

vec vecAdd(vec v1, vec v2);

bool vecAddTo(vec *v1, vec v2);

vec vecSubtract(vec v1, vec v2);

bool vecSubtractFrom(vec *v1, vec v2);

vec vecMultiply(vec v1, vec v2);

bool vecMultiplyTo(vec *v1, vec v2);

vec vecDivide(vec v1, vec v2);

bool vecDivideBy(vec *v1, vec v2);

float vecDotProd(vec v1, vec v2); 

bool vecIsOrthogonal(vec v1, vec v2);

vec vecCrossProd(vec v1, vec v2);

float vecMagnitude(vec v);

float vecMagnitudeSquared(vec v);

vec vecNormalized(vec v);

void vecNormalize(vec *v);

#endif
