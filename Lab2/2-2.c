#include<stdio.h>
#include<stdarg.h>

int check_month(int num, int length, ...) {
	va_list args;
	va_start(args, length);

	for(int i=0; i < length; i++) {
		if(va_arg(args, int) == num) {
			va_end(args);
			return 1;
		}
	}
	return 0;

}


int main() {
	int N;
	int result = 0;

	printf("N= ");
	scanf("%d", &N);

	if(check_month(N, 7, 1, 3, 5, 7, 8, 10, 12)) {
		result = 31;
	} else if(check_month(N, 4, 4, 6, 9, 11)) {
                result = 30;
        } else if(check_month(N, 1, 2)) {
                result = 28;
	}

	if (result != 0) {
		printf("The current month has %d days\n", result);
	}

	return 0;
}
