#include <stdio.h>

int sum(int num1, int num2);

int main()
{
    int a = 10, b = 20, c;

    c = sum(a, b);

    printf("%d + %d = %d\n", a, b, c);
}

int sum(int num1, int num2)
{
    return num1 + num2;
}