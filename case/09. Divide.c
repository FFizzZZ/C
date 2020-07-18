#include <stdio.h>

int main() {
    int dividend, divisor, quotient, remainder;

    printf("输入被除数\n");
    scanf("%d", &dividend);

    printf("输入除数\n");
    scanf("%d", &divisor);

    quotient = dividend / divisor;

    remainder = dividend % divisor;

    printf("quotient = %d\n", quotient);
    printf("remainder = %d\n", remainder);

    return 0;
}