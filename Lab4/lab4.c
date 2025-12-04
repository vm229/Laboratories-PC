#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "lab4.h"

#include "menu.h"
#include "menu.c"

#include "matrix.h"
#include "matrix.c"

#include "dynamic.h"
#include "dynamic.c"

#include "string.h"
#include "string.c"

void fmt_error(char *f, char *msg) {
	printf("error: [%s] %s\n", f, msg);
	//exit(1);
}

int main() {
	uint32_t i, choice = 0;
	menu_t *main = mainmenu_init();
	if (main == NULL) {
		fmt_error("main", "Couldn't initialize menu");
		exit(1);
	}	
	mm = main;

	printf("%s\n", main->title);
	while(choice < main->size) {
		for (i = 0; i < main->size; i++) {
			printf("%d] %s - %s\n", i+1, 
					main->options[i].name, main->options[i].description);
		}
		do {
			printf("> ");
			scanf("%d", &choice);
		} while (choice > main->size);
		//printf("%d", choice);
		main->options[choice-1].func();
	}

	return 0; 
}
