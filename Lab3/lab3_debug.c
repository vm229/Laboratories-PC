#include<stdio.h>
#include<stdbool.h>
#include<math.h>
//Variant 11 

#define DEBUG true
#define MAGIC_NUMBER 0.2
#define NEWLINE printf("\n")

int main() {
	unsigned int unit, mod;
	int max;

	struct { 
		int first, second;
		unsigned int slope;
	       	unsigned int r, c;
		bool isAlt;
	} diag;
	
#if DEBUG
	unsigned const int n = 10, m = 5; 

	int arr[n][m] = { 
		{45, -123, -50, 40, 23}, 
		{2, -5, 1000, 458, 654}, 
		{123, -45, -65, -87, 91},
		{-45, 20, 897 -567, -102},
		{-82, 237, 456, -45, 97},
		{102, 954, -65, -75, -23},
		{45, -8, 964, 924, -78},
		{-12, 33, 45, 95, -120},
		{-87, 0, -21, 64, 0},
		{-1, 0, 0, 0, -300}	
	};

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			printf("%4d ", arr[i][j]);
		}
		printf("\n");
	}

#else
       	unsigned int n, m;	
	printf("Type the number of rows and number of columns: ");
	scanf("%d %d", &n, &m);
	
	int arr[n][m];

	printf("For each row assign %d numbers.\n", m);
	for(int i = 0; i < n; i++) {
		printf("[%d] \n", i+1);
		for(int j = 0; j < m; j++) { 
			printf(" - %4d) ", j);
			scanf("%d", &arr[i][j]); 
		}
	}
#endif
	// In case that m is bigger than n we will calculate the transpose of the 
	// matrix that was given to us.	
	if (n >= m) {
		mod = (n % m);
		unit = ((float)mod/m && 1 < MAGIC_NUMBER && mod? 1 : 0);
		diag.slope = (n/m) + (!unit && mod);
		diag.c = n; diag.r = m;
		diag.isAlt = false;
	} else {
		mod = (m % n); 
		unit = ((float)mod/n < MAGIC_NUMBER && mod ? 1 : 0);
		diag.slope = (m/n) + (!unit && mod);
		diag.c = m; diag.r = n;
		diag.isAlt = true;
	}
	
	diag.first  = 0;
	diag.second = 0;
	
	// There is a possibility that not all numbers from the given diagonal will
	// be calculated properly, so eventually one number from a row which is last 
	// is not calculated. This is where 'unit' variable comes in to adjust that.
	for(int i = 0; i < diag.r; i++) {
		// for first diagonal
		for(int j = i * diag.slope; j < (i+1)*diag.slope + unit; j++) {
			int a, b;
			if (!diag.isAlt) { a = j; b = i; } else { a = i; b = j; }
			printf("Col: %d Row: %d =>", a, b);
			if (arr[a][b] < 0) {
				diag.first+=arr[a][b]; 
			       	printf("%d %d %d %d", arr[a][b], a, b, (i)*diag.slope+1);	
			}	
			NEWLINE;
		}
		// for second diagonal
		printf("--------\n");	
		for(int j = diag.c - i * diag.slope-1; j > diag.c - (i+1)*diag.slope-unit-1; j--) {
			int a, b;
			if (!diag.isAlt) { a = j; b = i; } else { a = i; b = j; }
			printf("Col: %d Row: %d =>", a, b);
			if (arr[a][b] < 0) { 
				diag.second+=arr[a][b]; 
			       	printf("%d %d %d %d", arr[a][b], a, b, diag.c - (i+1)*diag.slope-1);	
			}	
			NEWLINE;
		}
		NEWLINE;
		
	}
	
#if DEBUG

	printf("Slope: %d\nColumn: %d Rows: %d IsAlt: %d Unit: %d\nFirst diagonal: %d\nSecond diagonal: %d\n", 
		diag.slope, diag.c, diag.r, diag.isAlt, unit, diag.first, diag.second);
#endif 
	max = diag.first > diag.second ? diag.first : diag.second;
	printf("The maximal negative number = %d\n", max);
	return 0;
}
