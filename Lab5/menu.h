#pragma once

typedef struct MenuOption {
	char *name;
	char *description;
	void (*func)();
} menu_option_t;

typedef struct Menu {
	menu_option_t *options;
	int size;
	char *title;
} menu_t;

// functions used for menu options

// functions for creating menu and options for it
void menuoptions_setoption(menu_t*, char*, char*, void (*func)());
menu_t *mainmenu_init();

menu_t *mm;

