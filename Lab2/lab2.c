#include <stdio.h>

int main() {
    int N;
    float minP = 0, maxN = 0;
    int p1, p2;

    printf("N = ");
    scanf("%d", &N);

    float array[N];

    for (int i = 0; i < N; i++) {
        printf("%d) x =", i+1);
        scanf("%f", &array[i]);
    }

    for (int i = 0; i < N; i++) {
        if(array[N-i-1] < maxN && maxN == 0) {
            maxN = array[N - i -1];
            p2 = N-i-i;
        }
        if(array[i] > minP && minP == 0) {
            minP = array[i];
            p1 = i;
        }
    }

    printf("Results:\n");
    for (int i = 0; i < N; i++) {
        printf("%d) %f\n", i+1, array[i]);
    }
    printf("First minimal positive number: position = %d, nr = %f\n", p1, minP);
    printf("Last maximal negative number: position = %d, nr = %f\n", p2, maxN);


    return 0;
}