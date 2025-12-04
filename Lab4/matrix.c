#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "lab4.h"
#include "matrix.h"

//creates an empty matrix
matrix_t *matrix_create(int r, int c) {
	matrix_t *M = (matrix_t *)malloc(sizeof(matrix_t));
	if (M == NULL) {
		fmt_error(__func__, "Couldn't allocate memory for matrix");
		exit(1);
	}

	M->row = r;
	M->col = c;
	
	int **mat = (int **)malloc(sizeof(int *) * M->row);
	if (mat == NULL) {
		fmt_error(__func__, "Couldn't allocate memory for row");
		free(M);
		return NULL;
	}
	
	for (uint32_t i = 0; i < M->row; i++) {
		int *row = (int *)calloc(M->col, sizeof(int) * M->col);	
		if (row == NULL) {
			fmt_error(__func__, "Couldn't allocate memory for col");
			for (uint32_t j = 0; j < i; j++) {
				free(mat[j]);
			}
			free(mat);
			free(M);
			return NULL;
		}
		mat[i] = row;
		/*
		for (uint32_t j = 0; j < M->col; j++) {
			mat[i][j] = rand() % MAX_NUMBER;
		}
		*/
		
	}
	M->matrix = mat;
	return M;
}

matrix_t *matrix_sum(matrix_t *M1, matrix_t *M2) {
	if(M1->row != M2->row || M1->col != M2->col) {
		fmt_error(__func__, "The matrices are of different sizes\n");
		return NULL;
	}
	
	matrix_t *M = matrix_create(M1->row, M2->col);

	for(uint32_t i = 0; i < M1->row; i++) {
		for(uint32_t j = 0; j < M1->col; j++) {
			M->matrix[i][j] = M1->matrix[i][j] + M2->matrix[i][j]; 
		}
	}
	return M;
}

matrix_t *matrix_mul(matrix_t *M1, matrix_t *M2) {
	if(M1->col != M2->row) {
		fmt_error(__func__, "The matrices are of different sizes\n");
	}

	matrix_t *M = matrix_create(M1->row, M2->col);

	int sum;
	for (int i = 0; i < M1->row; i++) {
		sum = 0;
		for (int j = 0; j < M2->col; j++) {
			for (int k = 0; k < M2->row; k++) {
				sum += M1->matrix[i][k] * M2->matrix[k][j]; 		
			}
			M->matrix[i][j] = sum;
		}
	}
	return M;
}

void matrix_free(matrix_t *M) {
	for(uint32_t i = 0; i > M->row; i++) {
		free(M->matrix[i]);
	}
	free(M->matrix);
	free(M);
}

void matrix_setrand(matrix_t *M) {
	for(uint32_t i = 0; i < M->row; i++) {
		for(uint32_t j = 0; j < M->col; j++) { 
			M->matrix[i][j] = rand() % MAX_NUMBER; 
		}
	}
}

void matrix_print(matrix_t *M) {
	uint32_t i;
	
	printf("     |  ");
	for(i = 0; i < M->col; i++) {
		printf("%5d ", i+1);
	}
	printf("\n-----+--");
	for(i = 0; i < M->col; i++) {
		printf("------");
	}
	printf("\n");

	for(i = 0; i < M->row; i++) {
		printf("%3d  |  ", i+1);
		for(uint32_t j = 0; j < M->col; j++) { 
			printf("%5d ", M->matrix[i][j]); 
		}
		printf("\n");
	}
	printf("\n");
}


