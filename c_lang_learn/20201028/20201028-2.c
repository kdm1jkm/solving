#include <stdio.h>

int main()
{
    int num;
    printf("Enter number>>");
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            printf("%d ", j + 1);
        }
        printf(": sum of line %d is %d\n", i + 1, (i + 1) * (i + 2) / 2);
    }
}