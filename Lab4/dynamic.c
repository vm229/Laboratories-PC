#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "lab4.h"
#include "dynamic.h"


string_t *alloc_string(size_t n) {
	string_t *string = (string_t*)malloc(sizeof(string_t));
	if (string == NULL) {
		return NULL;
	}

	char *str = (char*)calloc(n, sizeof(char));	
	if (str == NULL) {
		free(string);
		return NULL;
	}
	string->length = n;
	string->data = str;
	return string; 
}

void free_string(string_t *string) {
	free(string->data);
}

void sort_2darray(matrix_t *M) {
	int sum;
	median_array_t medarr;
	
	medarr.length = M->row;
	medarr.med = (median_t*) calloc(M->row, sizeof(median_t));	
	if (medarr.med == NULL) return;

	for (uint16_t i = 0; i < medarr.length; i++) {
		sum = 0;
		for (uint16_t j = 0; j < M->col; j++) {
			sum += M->matrix[i][j];
		}
		medarr.med[i].medsum = (float) sum / (float) M->col;
	}

	for (uint16_t i = 0; i < medarr.length; i++) {
		uint16_t j = i;
		while (j > 0 && medarr.med[j-1].medsum > medarr.med[j].medsum) {
			median_t t1 = medarr.med[j];
			medarr.med[j] = medarr.med[j-1];
			medarr.med[j-1] = t1;
			
			int *t2 = M->matrix[j];
			M->matrix[j] = M->matrix[j-1];
			M->matrix[j-1] = t2;
			j--;	
		}
	}	
}

// Mostly it will be for strings only

void insert_element(string_t *str, char e, int pos) {
	if (pos > str->length) { return; }
	str->data[pos] = e;
}

void delete_element(string_t *str, int pos) {
	if (pos > str->length) { return; }
	str->data[pos] = 0;
}

void print_elements(string_t *str) {
	char output[BUFFER_SIZE];
	
	for (uint16_t i = 0; i < str->length; i++) {
		if (str->data[i] == 0) output[i] = '_';		
		else output[i] = str->data[i];
	}
	printf("String structure: %s\n", output);
}


