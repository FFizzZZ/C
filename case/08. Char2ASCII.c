#include <stdio.h>

int main() {
    char c;
    printf("输入一个字符\n");

    scanf("%c", &c);

    printf("%c 的 ASCII 为 %d\n", c, c);

    return 0;
}