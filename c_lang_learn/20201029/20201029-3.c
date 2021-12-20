#include <stdio.h>

int main()
{
    int num;
    printf("Enter number>>");
    scanf("%d", &num);

    int sum = 0;

    int i = 0;
    while (i++ < num)
    {
        if (i % 2 == 0)
        {
            printf("- %d ", i);
            sum -= i;
        }
        else
        {
            printf("+ %d ", i);
            sum += i;
        }
    }

    printf(" = %d\n", sum);
}