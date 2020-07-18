#include <stdio.h>

int main() {
    int first, second, sum;

    printf("输入两个整数\n");

    scanf("%d %d", &first, &second);

    sum = first + second;

    printf("%d + %d = %d\n", first, second, sum);

    return 0;
}