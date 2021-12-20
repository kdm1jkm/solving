#include <stdio.h>

int max(int num1, int num2);

int main()
{
    int a, b;
    printf("a>>");
    scanf("%d", &a);
    printf("b>>");
    scanf("%d", &b);

    printf("max : %d\n", max(a, b));
}

int max(int num1, int num2)
{
    return num1 > num2 ? num1 : num2;
}