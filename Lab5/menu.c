#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "lab5.h"
#include "menu.h"
#include "string.h"

void menu_exit() {
	free(mm->options);
	free(mm);
	exit(0);
}

void menu_wordcount() {
	int count;
	char str[1024];
	
	printf("Input: ");
	fgets(str, 1024, stdin);
	count = word_count(str);

	printf("There are %d words in the string.\n", count);
}

void menu_findchar() {
	int index;
	char str[1024];
	char c[1];
	
	printf("Input: ");
	fgets(str, 1024, stdin);
	printf("Print a character: ");
	scanf("%s", c);
	getchar();

	index = find_char(str, c[0]);

	if (index == -1) {
		printf("The character wasnt found in string.\n");
		return;
	}

	printf("The character was found at index %d\n", index);
}

void menu_reversewords() {

	char buffer[1024], str[1024];
	printf("Input: ");
	fgets(buffer, 1024, stdin);
	reverse_words(str, buffer);

	printf("Reversed: %s\n", str);

}

void menu_strreverse() {

	char buffer[1024], str[1024];

	printf("Input: ");
	fgets(buffer, 1024, stdin);
	{
        int len = strlen(buffer);
        buffer[len-1] = '\0';
    }
	strreverse(str, buffer);
	printf("Reversed: %s\n", str);

}

void menu_changechar() {
	char str[1024], buffer[1024], 
		c1[2], c2[2];

	printf("Input: ");
	fgets(buffer, 1024, stdin);
	str[0] = buffer[0];

	printf("Character from string: ");
	scanf("%s", c1);
	printf("Character to change to: ");
	scanf("%s", c2);

	
	change_char(str, buffer, c1[0], c2[0]);
	printf("Output: %s\n", str);
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

	menuoption_setoption(m, "Word Count", 
		"Counts words from the string", menu_wordcount);
	menuoption_setoption(m, "Find character", 
		"Finds a character in the string", menu_findchar);
	menuoption_setoption(m, "Reverse words", 
		"Reverse the order of words in the string", menu_reversewords);
	menuoption_setoption(m, "Reverse string", 
		"Reverse a string", menu_strreverse);
	menuoption_setoption(m, "Change character", 
		"Change a character", menu_changechar);
	
	menuoption_setoption(m, "Exit", 
		"Exit from the current program", menu_exit);	

	//m->size++;
	return m;
}
