#include <stdio.h>

int main()
{
    int num;
    printf("Enter number>>");
    scanf("%d", &num);

    int sum = 0;
    int i = 0;
    while (i < 100)
    {
        sum += ++i;
    }
    printf("Sum : %d\n", sum);
}