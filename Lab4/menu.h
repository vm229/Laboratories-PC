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
void menu_exit();
void menu_M_sum();
void menu_m_mul();
void menu_length();
void menu_concat();
void menu_copy();
void menu_compare();
void menu_reverse();
void menu_string();
void menu_2dsort();
void menu_elements();

// functions for creating menu and options for it
void menuoptions_setoption(menu_t*, char*, char*, void (*func)());
menu_t *mainmenu_init();

menu_t *mm;

