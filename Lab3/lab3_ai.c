#include <stdio.h>

#define N 3  // Number of rows
#define M 3  // Number of columns

int main() {
    int matrix[N][M] = {
        {1, -2, 3},
        {-4, -5, 6},
        {7, 8, -9}
    };

    int mainDiagonalSum = 0;
    int secondaryDiagonalSum = 0;

    // Calculate sums of negative elements in both diagonals
    for (int i = 0; i < N; i++) {
        // Main diagonal: matrix[i][i]
        if (matrix[i][i] < 0) {
            mainDiagonalSum += matrix[i][i];
        }

        // Secondary diagonal: matrix[i][N-i-1]
        if (matrix[i][N - i - 1] < 0) {
            secondaryDiagonalSum += matrix[i][N - i - 1];
        }
    }

    // Determine the maximum sum
    int maxSum = mainDiagonalSum > secondaryDiagonalSum ? mainDiagonalSum : secondaryDiagonalSum;

    printf("Maximum sum of negative elements in either diagonal: %d\n", maxSum);

    return 0;
}
