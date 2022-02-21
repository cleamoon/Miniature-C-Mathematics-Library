#include <stdio.h>
#include <stdlib.h>

#include "cmathematics/cmathematics.h"
#include "cmathematics/vec.h"

int main() {
    printf("Hello world\n");

    vec v1 = vector(1., 2., 3.);
    print(v1);
    printf("Mag: %f\n", magnitude(v1));
    print(normalized(v1));

    scalarMultiplicationBy(&v1, 2.0);
    print(v1);

    vec v2 = power(v1, 3.0);
    print(v2);

    vec v3 = subtract(v1, v2);
    print(v3);

    printf("Dot: %f\n", dot(v1, v2));

    printf("Ortho: %d\n", orthogonal(vector(4., 1., 2.), vector(1., 0., -2.)));

    print(cross(vector(2., -3., 1.), vector(-2., 1., 1.)));

    return 0;
}