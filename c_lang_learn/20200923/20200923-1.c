#include <stdio.h>

int main()
{
    int a, b, c, temp;
    printf("Enter number1:");
    scanf("%d", &a);
    printf("Enter number2:");
    scanf("%d", &b);
    printf("Enter number3:");
    scanf("%d", &c);

    if (c > b)
    {
        temp = b;
        b = c;
        c = temp;
    }
    if (b > a)
    {
        temp = a;
        a = b;
        b = temp;
    }

    if (c > b)
    {
        temp = b;
        b = c;
        c = temp;
    }

    printf("%d, %d, %d\n", a, b, c);

    return 0;
}