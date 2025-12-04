#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "lab4.h"
#include "menu.h"
#include "matrix.h"
#include "string.h"
#include "dynamic.h"


void menu_exit() {
	free(mm->options);
	free(mm);
	exit(0);
}

void menu_M_sum() {
	int m, n;
	
	printf("Type the number of rows and columns: ");
	scanf("%d %d", &m, &n);

	matrix_t *M1 = matrix_create(m, n), 
		 *M2 = matrix_create(m, n);

	matrix_setrand(M1);
	matrix_setrand(M2);

	matrix_t *Msum = matrix_sum(M1, M2);

	printf("Matrix NR.1\n");
	matrix_print(M1);
	printf("Matrix NR.2\n");
	matrix_print(M2);
	printf("Matrix sum\n");
	matrix_print(Msum);

	matrix_free(M1);
	matrix_free(M2);
	matrix_free(Msum);
}

void menu_M_mul() {
	int m, n;
	
	printf("Type the number of rows and columns: ");
	scanf("%d %d", &m, &n);

	matrix_t *M1 = matrix_create(m, n), 
		 *M2 = matrix_create(n, m);

	matrix_setrand(M1);
	matrix_setrand(M2);

	matrix_t *Mmul = matrix_mul(M1, M2);

	printf("Matrix NR.1\n");
	matrix_print(M1);
	printf("Matrix NR.2\n");
	matrix_print(M2);
	printf("Matrix sum\n");
	matrix_print(Mmul);

	matrix_free(M1);
	matrix_free(M2);
	matrix_free(Mmul);
}

void menu_length() {
	char s[BUFFER_SIZE];
	uint32_t count;
	char *c;

	printf("Write a word:");
	//gets(s);
	scanf("%s", s);

	size_t length = strlen(s);

	printf("This is the string: %s\nThis is its length: %zu\n", s, length);

	//free(s);
}
	
void menu_concat() {
	char *s1, *s2 ;
	

	s1 = malloc(sizeof(char)*20);
	s2 = malloc(sizeof(char)*20);
	
	if (s1 == NULL || s2 == NULL) {
		return;
	}

	printf("Write two words:");
	scanf("%s %s", s1, s2);
	
	strcat(&s1, &s2);
	

	printf("The current strings are: %s %s\n", s1, s2);
	free(s1);
	free(s2);
}

void menu_copy() {
	char *s1, *s2;
	
	s1 = (char *)calloc(20, sizeof(char));
	s2 = (char *)calloc(20, sizeof(char));

	if (s1 == NULL || s2 == NULL) {
		fmt_error(__func__, "Couldn't allocate strings");
		return;
	}

	printf("Type two words for strings (according to size): ");
	scanf("%s %s", s1, s2);

	printf("Before copying: %s %s\n", s1, s2);
	strcpy(s1, s2);
	printf("After copying: %s %s\n", s1, s2);

	free(s1);
	free(s2);
}

void menu_compare() {
	char *s1, *s2;
	
	s1 = (char *)calloc(20, sizeof(char));
	s2 = (char *)calloc(20, sizeof(char));

	if (s1 == NULL || s2 == NULL) {
		fmt_error(__func__, "Couldn't allocate strings");
		return;
	}

	printf("Type two words for strings (according to size): ");
	scanf("%s %s", s1, s2);

	printf("The words: %s %s\n", s1, s2);
	int cmp = strcmp(s1, s2);
	
	if (cmp < 0) printf("RESULT: First word is bigger than second word\n");
	else if (cmp > 0) printf("RESULT: First word is lesser than second word\n");
	else printf("RESULT: Both are equal\n");
	
}

void menu_reverse() {
	char *s1, *s2;
	
	s1 = (char *)calloc(20, sizeof(char));
	s2 = (char *)calloc(20, sizeof(char));

	if (s1 == NULL || s2 == NULL) {
		fmt_error(__func__, "Couldn't allocate strings");
		return;
	}

	printf("Type one word for string: ");
	scanf("%s", s1);

	printf("The word before reversing: %s\n", s1);
	strreverse(s2, s1);
	printf("The word after reversing: %s\n", s2);
	
}

void menu_string() {
	string_t *string = alloc_string(20);
	if (string == NULL) {
		fmt_error(__func__, "Couldn't allocate string_t");
		return;
	}
	
	printf("Type one word: ");
	scanf("%s", string->data);
	printf("Allocated string: %s\n", string->data);

	free_string(string);
}

void menu_2dsort() {
	int m, n;
	
	printf("Type the number of rows and columns: ");
	scanf("%d %d", &m, &n);

	matrix_t *M1 = matrix_create(m, n); 

	matrix_setrand(M1);
	
	printf("Matrix before sorting: \n");
	matrix_print(M1);

	sort_2darray(M1);
	printf("Matrix after sorting: \n");
	matrix_print(M1);
	
	matrix_free(M1);
}

void menu_elements() {
	int choice = 0;
	int pos;
	char c[1];

	string_t *string = alloc_string(20);
	if (string == NULL) {
		fmt_error(__func__, "Couldn't allocate string_t");
		return;
	}

	while(choice > -1 && choice < 3) {
		print_elements(string); printf("\n");
		printf("1) Enter a value.\n2) Erase a value.\nOther) Exit.\n>");
		scanf("%d", &choice);
		if (choice == 1) {
			printf("What do you want to enter: "); 
			scanf("%s", c);
			printf("At what position: "); 
			scanf("%d", &pos);
			insert_element(string, c[0], pos);
			choice = 0;
		} else if (choice == 2) {
			printf("What element do you want to erase (write the index): "); scanf("%d", &pos);
			delete_element(string, pos);
			choice = 0;
		}
	}

	free_string(string);
}

void menuoption_setoption(menu_t *m, char *name, char *desc, void (*func)()) {
	m->options[m->size].name = name;
	m->options[m->size].description = desc;
	m->options[m->size].func = func;
	m->size++;
}

menu_t *mainmenu_init() {
	menu_t *m = (menu_t *)malloc(sizeof(menu_t));
	if (m == NULL) {
		return NULL;
	}

	m->title = "Main menu";
	m->size = 0;
	m->options = (menu_option_t *)malloc(sizeof(menu_option_t) * m->size);
	
	if (m->options == NULL) {
		free(m);
		return NULL;
	}
	menuoption_setoption(m, "Matrices sum", 
			"Sum two matrices with random generated numbers", menu_M_sum);
	menuoption_setoption(m, "Matrices mul", 
			"Mulitply two matrices with random generated numbers", menu_M_mul);
	menuoption_setoption(m, "String length", 
			"Get the length of the string that is typed", menu_length);
	menuoption_setoption(m, "String concatination", 
			"Append two strings togheter and from the input", menu_concat);
	menuoption_setoption(m, "String copying", 
			"Copy one string into another", menu_copy);
	menuoption_setoption(m, "String comparing", 
			"Compare to strings", menu_compare);
	menuoption_setoption(m, "String reversing", 
			"Reverse a string", menu_reverse);
	menuoption_setoption(m, "String initialization", 
			"Self explanatory", menu_string);
	menuoption_setoption(m, "Matrix sort", 
			"Sorts the matrix' rows", menu_2dsort);
	menuoption_setoption(m, "String manipulation", 
			"Insert or delete data from the string", menu_elements);
	
	
	menuoption_setoption(m, "Exit", 
			"Exit from the current program", menu_exit);	

	//m->size++;
	return m;
}
