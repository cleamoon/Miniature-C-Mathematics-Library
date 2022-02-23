#include <stdarg.h>
#include <stdio.h>

#include "cmathematics.h"
#include "vec.h"

#ifndef MATRIX_H
#define MATRIX_H

typedef struct {
    unsigned int rows;
    unsigned int cols;
    float **elements;
} mat;

extern const mat MAT_UNDEFINED;

mat allocateMat(unsigned int rows, unsigned int cols);

mat identityMatrix(unsigned int dim);

mat zeroMatrix(unsigned int rows, unsigned int cols);

mat newMatrix(unsigned int rows, unsigned int cols, unsigned int size,...);

mat copyMat(mat m);

mat copyPtrMat(mat *m);

void printMat(mat m);

vec getMatRow(mat *m, unsigned row);

vec getMatCol(mat *m, unsigned col);

mat toRowVec(vec *v);

mat toColVec(vec *v);

mat matScalarAddition(mat m, float k);

void matScalarAdditionTo(mat *m, float k);

mat matScalarSubtraction(mat m, float k);

void matScalarSubtractionTo(mat *m, float k);

mat matScalarMultiplication(mat m, float k);

void matScalarMultiplicationTo(mat *m, float k);

mat matScalarDivision(mat m, float k);

void matScalarDivisionTo(mat *m, float k);

mat matAdd(mat m1, mat m2);

bool matAddTo(mat* m1, mat m2);

mat matSub(mat m1, mat m2);

bool matSubTo(mat* m1, mat m2);

vec matVecMultiplication(mat m, vec v);

mat matMultiplication(mat m1, mat m2);

#endif
