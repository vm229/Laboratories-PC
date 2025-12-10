#include <string.h>
#include <stdio.h>

int word_count(char* str) {
    int count = 0;
    char delimeter[] = " ";
    char *token = strtok(str, delimeter);

    while(token) {
        count++;
        token = strtok(NULL, delimeter);
    }

    return count;
}

void reverse_words(char* str1, char* str2) {
    int length = 0;
    char delimeter[] = " ";
    char *token = strtok(str2, delimeter);
    char *words[64];
    
    while (token) {
        words[length] = token;
        token = strtok(NULL, delimeter);
        length++;
    }
    {
        int len = strlen(words[length-1]);
        words[length-1][len-1] = '\0';
    }
    for (int i = length -1; i >=0; i--) {
        strcat(str1, words[i]);
        strcat(str1, " ");
    }
}

void strreverse(char *dst, const char *src) {
	size_t len1 = strlen(src);

	for (int i = 0; i < len1; i++) {
		dst[i] = src[len1 - i -1];
	}
}

int find_char(char str[], const char c) {
    int i = 1;
    while (str[i] != '\0') {
        if (str[i] == c) {
            return i;
        }
        i++;
    }
    printf("%s", str);
    return -1;
}

void change_char(char str[], char buffer[], char c1, char c2) {
    int i = 1;
     
    while (buffer[i] != '\0') {
        if (buffer[i] == c1) {
            str[i] = c2;
        } else {
            str[i] = buffer[i];
        }
        i++;
    }
}

void get_words(char dst[]) {
    printf("Type END to end the string.\n");
    char buffer[1024];
    while (1) {
        scanf("%s", buffer);
        if (strcmp(buffer, "END") == 0) {
            return;
        }
        strcat(buffer, " ");
        strcat(dst, buffer);
    }
}