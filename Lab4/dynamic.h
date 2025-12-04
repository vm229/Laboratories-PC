#include <stdlib.h>
#include "matrix.h"

#pragma once

typedef struct String {
	int length;
	char* data;
} string_t;

typedef struct Median {
	float medsum;
	int pos;
} median_t;

typedef struct MedianArray {
	median_t *med;
	int length;
} median_array_t;


// functions for dynamic allocation
string_t *alloc_string(size_t);
void free_string(string_t*);
void sort_2darray(matrix_t*);
void insert_element(string_t*, char, int);
void delete_element(string_t*, int);
void print_elements(string_t*);


