#include<stdio.h>
#include<math.h>
// varianta 11
int main() {
	int N;
	int first=0, last=-1;	

	printf("N= ");
	scanf("%d", &N);

	N = abs(N);
	
	first = N;
	while(first / 10 != 0) {
		if(last == -1) { last = N % 10; }
		first /= 10;
	}
	if (last != -1) {
		printf("First and last number are: %d %d\n", first, last);
	} else {
		printf("The first and only number is: %d", first);
	}
	
	return 0;
}
