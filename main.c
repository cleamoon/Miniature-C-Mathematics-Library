#include <stdio.h>
#include <stdlib.h>

#include "cmathematics/cmathematics.h"
#include "cmathematics/vec.h"
#include "cmathematics/matrix.h"

#define VEC_TEST
#define MAT_TEST

int main() {
    printf("Hello world\n");

    #ifdef VEC_TEST
    vec v1 = vector(1., 2., 3.);
    printVec(v1);
    printf("Mag: %f\n", vecMagnitude(v1));
    printVec(vecNormalized(v1));

    vecScalarMultiplicationBy(&v1, 2.0);
    printVec(v1);

    vec v2 = vecPower(v1, 3.0);
    printVec(v2);

    vec v3 = vecSubtract(v1, v2);

    printVec(v3);

    printf("Dot: %f\n", vecDotProd(v1, v2));

    printf("Ortho: %d\n", vecIsOrthogonal(vector(4., 1., 2.), vector(1., 0., -2.)));

    printVec(vecCrossProd(vector(2., -3., 1.), vector(-2., 1., 1.)));
    #endif

    #ifdef MAT_TEST
    mat m1 = identityMatrix(3);
    printMat(m1);

    mat m2 = zeroMatrix(5, 3);
    printMat(m2);

    mat m3 = newMatrix(3, 3, 9, 1., 2., 3., 4., 5., 6., 7., 8., 9.);
    printMat(m3);
    printMat(transposeMatrix(&m3));
    swapRows(&m3, 1, 2);        
    printMat(m3);
    addRows(&m3, 1, 2);
    printMat(m3);
    multiplyRow(&m3, 1, 2.0f);
    printMat(m3);
    addMultiple(&m3, 1, 2, 2.0f);
    printMat(m3);

    mat m4 = copyPtrMat(&m1);
    printMat(m4);

    printVec(getMatRow(&m3, 2));
    printVec(getMatCol(&m3, 0));

    vec v = vector(1., 2., 3.);

    printMat(toRowVec(&v));
    printMat(toColVec(&v));

    printVec(matVecMultiplication(m3, v));

    mat m5 = newMatrix(2, 3, 6, 2., 1., 4., 0., 1., 1.);
    mat m6 = newMatrix(3, 4, 12, 6., 3., -1., 0., 1., 1., 0., 4., -2., 5., 0., 2.);
    printMat(matMultiplication(m5, m6));
    
    mat m7 = matrix(3, 4, 1., 2., 1., 3., 3., -1., -3., -1., 2., 3., 1., 4.);
    printMat(m7);
    refMat(&m7);
    printMat(m7);

    printMat(augmentVec(&m7, &v));
    printMat(augmentMat(&m7, &m3));

    printMat(m3);
    printMat(spliceMat(&m3, 1, 1));

    mat m8 = matrix(3, 3, 7., 2., 0., 3., -15., 0., 6., -4., 2.);
    printf("%f\n", determinant(m8));

    #endif
    
    return 0;
}
