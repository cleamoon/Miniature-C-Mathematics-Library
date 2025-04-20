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

mat matScalarAddition(mat m, float k) {
    mat ret = allocateMat(m.rows, m.cols);

    for (unsigned r = 0; r < ret.rows; r++) {
        for (unsigned c = 0; c < ret.cols; c++) {
            ret.elements[r][c] = m.elements[r][c] + k;
        }
    }

    return ret;
}

void matScalarAdditionTo(mat *m, float k) {
    for (unsigned r = 0; r < m->rows; r++) {
        for (unsigned c = 0; c < m->cols; c++) {
            m->elements[r][c] += k;
        }
    }
}

mat matScalarSubtraction(mat m, float k) {
    mat ret = allocateMat(m.rows, m.cols);

    for (unsigned r = 0; r < ret.rows; r++) {
        for (unsigned c = 0; c < ret.cols; c++) {
            ret.elements[r][c] = m.elements[r][c] - k;
        }
    }

    return ret;
}

void matScalarSubtractionTo(mat *m, float k) {
    for (unsigned r = 0; r < m->rows; r++) {
        for (unsigned c = 0; c < m->cols; c++) {
            m->elements[r][c] -= k;
        }
    }
}

mat matScalarMultiplication(mat m, float k) {
    mat ret = allocateMat(m.rows, m.cols);

    for (unsigned r = 0; r < ret.rows; r++) {
        for (unsigned c = 0; c < ret.cols; c++) {
            ret.elements[r][c] = m.elements[r][c] * k;
        }
    }

    return ret;
}

void matScalarMultiplicationTo(mat *m, float k) {
    for (unsigned r = 0; r < m->rows; r++) {
        for (unsigned c = 0; c < m->cols; c++) {
            m->elements[r][c] *= k;
        }
    }
}

mat matScalarDivision(mat m, float k) {
    mat ret = allocateMat(m.rows, m.cols);

    for (unsigned r = 0; r < ret.rows; r++) {
        for (unsigned c = 0; c < ret.cols; c++) {
            ret.elements[r][c] = m.elements[r][c] / k;
        }
    }

    return ret;
}

void matScalarDivisionTo(mat *m, float k) {
    for (unsigned r = 0; r < m->rows; r++) {
        for (unsigned c = 0; c < m->cols; c++) {
            m->elements[r][c] /= k;
        }
    }
}

mat matAdd(mat m1, mat m2) {
    if (m1.rows != m2.rows || m1.cols != m2.cols) {
        return MAT_UNDEFINED;
    }

    mat ret = allocateMat(m1.rows, m1.cols); 

    for (unsigned r = 0; r < ret.rows; r++) {
        for (unsigned c = 0; c < ret.cols; c++) {
            ret.elements[r][c] = m1.elements[r][c] + m2.elements[r][c];
        }
    }

    return ret;
}

bool matAddTo(mat* m1, mat m2) {
    if (m1->rows != m2.rows || m1->cols != m2.cols) {
        return false;
    }

    for (unsigned r = 0; r < m1->rows; r++) {
        for (unsigned c = 0; c < m1->cols; c++) {
            m1->elements[r][c] += m2.elements[r][c];
        }
    }

    return true;
}

mat matSub(mat m1, mat m2) {
    if (m1.rows != m2.rows || m1.cols != m2.cols) {
        return MAT_UNDEFINED;
    }

    mat ret = allocateMat(m1.rows, m1.cols); 

    for (unsigned r = 0; r < ret.rows; r++) {
        for (unsigned c = 0; c < ret.cols; c++) {
            ret.elements[r][c] = m1.elements[r][c] - m2.elements[r][c];
        }
    }

    return ret;
}

bool matSubTo(mat* m1, mat m2) {
    if (m1->rows != m2.rows || m1->cols != m2.cols) {
        return false;
    }

    for (unsigned r = 0; r < m1->rows; r++) {
        for (unsigned c = 0; c < m1->cols; c++) {
            m1->elements[r][c] -= m2.elements[r][c];
        }
    }

    return true;
}

vec matVecMultiplication(mat m, vec v) {
    if (m.cols != v.dim) {
        return VEC_UNDEFINED;
    }

    vec ret = allocateVec(m.rows);

    for (unsigned r = 0; r < m.rows; r++) {
        ret.elements[r] = vecDotProd(v, getMatRow(&m, r + 1));
    }

    return ret;
}

mat matMultiplication(mat m1, mat m2) {
    if (m1.cols != m2.rows) {
        return MAT_UNDEFINED;
    }

    mat ret = allocateMat(m1.rows, m2.cols);

    vec *m1Row = malloc(m1.rows * sizeof(vec));
    vec *m2Col = malloc(m2.cols * sizeof(vec));

    for (unsigned r = 0; r < m1.rows; r++) {
        m1Row[r] = getMatRow(&m1, r + 1);
    }

    for (unsigned c = 0; c < m2.cols; c++) {
        m2Col[c] = getMatCol(&m2, c + 1);
    }

    for (unsigned r = 0; r < m1.rows; r++) {
        for (unsigned c = 0; c < m2.cols; c++) {
            ret.elements[r][c] = vecDotProd(m2Col[c], m1Row[r]);
        }
    }

    return ret;
}

mat transposeMatrix(mat *m) {
    mat ret = allocateMat(m->cols, m->rows);

    for (unsigned r = 0; r < ret.rows; r++) {
        for (unsigned c = 0; c < ret.cols; c++) {
            ret.elements[r][c] = m->elements[c][r];
        }
    }

    return ret;
}

bool swapRows(mat *m, unsigned r1, unsigned r2) {
    if (r1 >= m->rows || r2 >= m->rows || r1 == r2) {
        return false;
    }
    float *tmp = m->elements[r1];
    m->elements[r1] = m->elements[r2];
    m->elements[r2] = tmp;

    return true;
}

bool addRows(mat *m, unsigned r1, unsigned r2) {
    if (r1 >= m->rows || r2 >= m->rows || r1 == r2) {
        return false;
    }

    for (unsigned c = 0; c < m->cols; c++) {
        m->elements[r1][c] += m->elements[r2][c];
    }

    return true;
}

bool multiplyRow(mat *m, unsigned r, float k) {
    if (r >= m->rows || k == 0.0f) {
        return false;
    }

    for (unsigned c = 0; c < m->cols; c++) {
        m->elements[r][c] *= k;
    }
    return true;
}

bool addMultiple(mat *m, unsigned r1, unsigned r2, float k) {
    if (r1 >= m->rows || r2 >= m->rows || k == 0.0f || r1 == r2) {
        return false;
    }

    for (unsigned c = 0; c < m->cols; c++) {
        m->elements[r1][c] += k * m->elements[r2][c];
    }

    return true;
}

void refMat(mat *m) {
    unsigned currentRow = 0;
    for (unsigned c = 0; c < m->cols; c++) {
        unsigned r = currentRow;
        if (r >= m->rows) {
            break;
        }

        for (; r < m->rows; r++) {
	    if (m->elements[r][c] != 0.0f) {
		break;
	    }
	}

	if (r == m->rows) {
	    continue;
	}

	swapRows(m, currentRow, r);

	float factor = 1 / m->elements[currentRow][c];
	for (unsigned col = c; col < m->cols; col++) {
	    m->elements[currentRow][col] *= factor;
	}

	for (r = 0; r < m->rows; r++) {
	    if (r == currentRow) {
		continue;
	    }
	    addMultiple(m, r, currentRow, - m->elements[r][c]);
	}

	currentRow++;
    }
}
            
mat augmentVec(mat *m, vec *v) {
    if (m->rows != v->dim) {
	return MAT_UNDEFINED;
    }

    mat ret = allocateMat(m->rows, m->cols + 1);

    for (unsigned r = 0; r < m->rows; r++) {
	unsigned c = 0;
	for (; c < m->cols; c++) {
	    ret.elements[r][c] = m->elements[r][c];
	}

	ret.elements[r][c] = v->elements[r];
    }

    return ret;
}

mat augmentMat(mat *m, mat *m2) {
    if (m->rows != m2->rows) {
	return MAT_UNDEFINED;
    }

    mat ret = allocateMat(m->rows, m->cols + m2->cols); 

    for (unsigned r = 0; r < m->rows; r++) {
	unsigned c = 0;
	for (; c < m->cols; c++) {
	    ret.elements[r][c] = m->elements[r][c];
	}

	for (; c < ret.cols; c++) {
	    ret.elements[r][c] = m2->elements[r][c - m->cols];
	}
    }

    return ret;    
}

mat spliceMat(mat *m, unsigned exclRow, unsigned exclCol) {
    mat ret = allocateMat(m->rows-1, m->cols-1);

    unsigned rowOffset = 0;

    for(unsigned r = 0; r < ret.rows; r++) {
	unsigned colOffset = 0;

	if (r == exclRow) {
	    rowOffset++;
	}

	for(unsigned c = 0; c < ret.cols; c++) {
	    if (c == exclCol) {
		colOffset++;
	    }

	    ret.elements[r][c] = m->elements[r + rowOffset][c + colOffset];
	}
    }

    return ret;
}
		
float determinant(mat m) {
    if (m.rows != m.cols) {
	return 0.0;
    }

    if (m.rows == 1) {
	return m.elements[0][0];
    }

    char cofactorSign = 1;
    float ret = 0.0f;

    for (unsigned c = 0; c < m.cols; c++) {
	ret += cofactorSign * m.elements[0][c] * determinant(spliceMat(&m, 0, c));
	cofactorSign = -cofactorSign;
    }

    return ret;
}
