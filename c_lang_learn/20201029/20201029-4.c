#include <stdio.h>

int main()
{
    int num;
    printf("Enter number>>");
    scanf("%d", &num);

    int result = 1;

    int i = 0;
    while (i++ < num)
    {
        result *= i;
    }

    printf("Result: %d\n", result);
}