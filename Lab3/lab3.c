#include<stdio.h>
#include<stdbool.h>
#include<math.h>
//Variant 11 

#define DEBUG false
#define MAGIC_NUMBER 0.2

int main() {
	unsigned int n, m;	
	unsigned int unit, mod;
	int max;

	struct { 
		int first, second;
		unsigned int slope;
	       	unsigned int r, c;
		bool isAlt;
	} diag;
	
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
		int a, b;
		// for first diagonal
		for(int j = i * diag.slope; j < (i+1)*diag.slope + unit && j < diag.c; j++) {
			if (!diag.isAlt) { 
				a = j; b = i;
			} else { 
				a = i; b = j;
			}
			if (arr[a][b] < 0) 
				diag.first+=arr[a][b]; 
		}
		// for second diagonal
		for(int j = diag.c - i * diag.slope-1; j > diag.c - (i+1)*diag.slope-unit-1 && j >= 0; j--) {
			if (!diag.isAlt) { 
				a = j; b = i; 
			} else { 
				a = i; b = j; 
			}
			if (arr[a][b] < 0) 
				diag.second+=arr[a][b]; 
		}
		
	}
	
	max = diag.first > diag.second ? diag.first : diag.second;
	printf("The maximal negative number = %d\n", max);
	return 0;
}
