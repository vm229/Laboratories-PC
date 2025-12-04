#include <stdio.h>
#include <math.h>

float x;

float equation1(float a, float b, float c) {
    return (sinf(a) + b*x) / fabsf(powf(x, 2) - c);
}
float equation2(float a, float b) {
    return logf(a*x) / (powf(x, 2) + b);
}
float equation3(float a, float b) {
    return (4*sqrtf(x) + 8*cosf(x)) / (powf(a, 2) + b);
}

int main(void) {
    float x1, x2;
    float px;
    float a, b, c;

    printf("* Enter the values for X1, X2 and PX:\n> ");
    scanf("%f %f %f", &x1, &x2, &px);
    printf("* Enter the values for A, B and C:\n> ");
    scanf("%f %f %f", &a, &b, &c);

    for (x = x1; x <= x2; x += px) {
        float result;
        if (x + b < 0 && c == 0)
            result = equation1(a, b, c);
        else if (x + b > 0 && c != 0)
            result = equation2(a, b);
        else
            result = equation3(a, b);
        printf("x = %f, F => %f\n", x, result);
    }
    x = 0;

    return 0;
}
