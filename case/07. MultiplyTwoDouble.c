#include <stdio.h>

int main() {
    double first, second, product;
    printf("输入两个浮点数\n");

    scanf("%lf %lf", &first, &second);

    product = first * second;

    printf("result = %.2lf", product);

    return 0;
}