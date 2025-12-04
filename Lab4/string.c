#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "lab4.h"
#include "string.h"

void swap(char *s1, char *s2) {
	char *t = s1;
	s2 = s1;
	s1 = s2;
}

size_t strlen(const char *s1) {
	if (s1 == NULL) {
		return 0;
	}
	size_t count;
	char *c;
	for(count = 0; ; count++) {
		c = s1 + count;
		if (*c == '\0') {
			break;
		}	
	}
	return count;
}

void strcat(char **s1, char **s2) {
	int i;
	size_t len1 = strlen(*s1),
	       len2 = strlen(*s2);
	char *p;
	
	p = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (p == NULL) {
		printf("Allocation was not succesfull\n");
		return;
	}
	for (i = 0; i < len1; i++) {
		p[i] = (*s1)[i];
	}

	for (i = 0; i <=len2; i++) {
		p[len1 + i] = (*s2)[i];
	}
	
	printf("%s\n", p);
	s1 = &p;
}	

void strcpy(char *s1, const char *s2) {
	size_t len1 = strlen(s1),
	       len2 = strlen(s2);
	
	if (len1 < len2) {
		len2 = len1;
	}
	
	for(uint16_t i = 0; i < len2; i++) {
		(s1)[i] = (s2)[i];	
	}
	(s1)[len2] = '\0';
}

int strcmp(const char *s1, const char *s2) {
	size_t len1 = strlen(s1),
	       len2 = strlen(s2);

	if (len1 > len2) {
		return -1;
	} else if (len1 < len2) {
		return 1;
	}

	for (int i = 0; i < len1; i++) {
		if (s1[i] > s2[i]) {
			return -1;
		} else if (s1[i] < s2[i]) {
			return 1;
		}
	}
	return 0;
}

void strreverse(char *dst, const char *src) {
	size_t len1 = strlen(src);

	for (int i = 0; i < len1; i++) {
		dst[i] = src[len1 - i -1];
	}
}


