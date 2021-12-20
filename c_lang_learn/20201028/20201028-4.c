#include <stdio.h>

int main()
{
    int num;
    printf("Enter number>>");
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num - 1 - i; j++)
        {
            printf("  ");
        }

        for (int j = 0; j < i + 1; j++)
        {
            printf("%d ", j + 1);
        }
        printf("\n");
    }
}