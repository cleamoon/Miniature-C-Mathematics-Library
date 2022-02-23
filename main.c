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
    mat m = identityMatrix(3);
    printMat(m);

    mat m2 = zeroMatrix(5, 3);
    printMat(m2);

    printMat(newMatrix(3, 3, 9, 1., 2., 3., 4., 5., 6., 7., 8., 9.));

    mat m3 = copyPtrMat(&m);
    printMat(m3);

    printVec(getMatRow(&m, 3));
    printVec(getMatCol(&m, 1));

    vec v = vector(1., 3.14, 2.72);

    printMat(toRowVec(&v));
    printMat(toColVec(&v));
    #endif
    
    return 0;
}
