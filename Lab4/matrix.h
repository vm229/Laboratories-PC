#pragma once

typedef struct Matrix {
	int row, col;
	int** matrix;
} matrix_t;


// functions for matrices
matrix_t *matrix_create(int, int);
matrix_t *matrix_sum(matrix_t*, matrix_t*);
matrix_t *matrix_mul(matrix_t*, matrix_t*);
void matrix_free(matrix_t*);
void matrix_setrand(matrix_t*);
void matrix_print(matrix_t*);


