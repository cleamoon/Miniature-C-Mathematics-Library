#include "matrix.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

const mat MAT_UNDEFINED = {0, 0, NULL};

mat allocateMat(unsigned int rows, unsigned int cols) {
    mat ret;

    ret.rows = rows;
    ret.cols = cols;

    ret.elements = malloc(rows * sizeof(float*));
    for (unsigned int i = 0; i < rows; i++) {
	    ret.elements[i] = malloc(cols * sizeof(float));
    }

    return ret;
}

mat identityMatrix(unsigned int dim) {
    mat ret = allocateMat(dim, dim);

    for (unsigned int r = 0; r < dim; r++) {
	memset(ret.elements[r], 0.0f, dim);
	ret.elements[r][r] = 1.0f;
    }

    return ret;
}

mat zeroMatrix(unsigned int rows, unsigned int cols) {
    mat ret = allocateMat(rows, cols);

    for (unsigned int r = 0; r < rows; r++) {
	memset(ret.elements[r], 0.0f, cols);
    }

    return ret;
}

mat newMatrix(unsigned int rows, unsigned int cols, unsigned size, ...) {
    mat ret = allocateMat(rows, cols);

    va_list list;
    va_start(list, size);

    for(unsigned int r = 0; r < rows; r++) {
	for (unsigned int c = 0; c < cols; c++) {
	    ret.elements[r][c] = va_arg(list, double);
	}
    }

    va_end(list);

    return ret;
}

mat copyMat(mat m) {
    return m;
}

mat copyPtrMat(mat *m) {
    mat ret = allocateMat(m->rows, m->cols);
    memcpy(&ret, m, sizeof ret);
    return ret;
}

void printMat(mat m) {
    printf("\n");
    for (unsigned int r = 0; r < m.rows; r++) {
	printf("|");
	for(unsigned int c = 0; c < m.cols; c++) {
	    printf(" %f", m.elements[r][c]);
	}
	printf("|\n");
    }
}

vec getMatRow(mat *m, unsigned row) {
    row--;
    if (row < 0 || row >= m->rows) {
        return VEC_UNDEFINED;
    }

    vec ret = allocateVec(m->cols);

    for (unsigned i = 0; i < ret.dim; i++) {
        ret.elements[i] = m->elements[row][i];
    }

    return ret;
}

vec getMatCol(mat *m, unsigned col) {
    col--;
    if (col < 0 || col >= m->cols) {
        return VEC_UNDEFINED;
    }

    vec ret = allocateVec(m->rows);

    for (unsigned i = 0; i < ret.dim; i++) {
        ret.elements[i] = m->elements[i][col];
    }

    return ret;
}

mat toRowVec(vec *v) {
    mat ret = allocateMat(1, v->dim);

    for (unsigned i = 0; i < v->dim; i++) {
        ret.elements[0][i] = v->elements[i];
    }

    return ret;
}

mat toColVec(vec *v) {
    mat ret = allocateMat(v->dim, 1);

    for (unsigned i = 0; i < v->dim; i++) {
        ret.elements[i][0] = v->elements[i];
    }

    return ret;
}