#include <stdio.h>

int a, b;

void swap();

int main()
{
    printf("a>>");
    scanf("%d", &a);
    printf("b>>");
    scanf("%d", &b);

    swap(a, b);

    printf("%d %d\n", a, b);
}

void swap()
{
    int temp = a;
    a = b;
    b = temp;
}