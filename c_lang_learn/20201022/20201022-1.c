#include <stdio.h>

int main()
{
    int num;
    printf("Enter number>>");
    scanf("%d", &num);

    for (int i = 0; i < 9; i++)
    {
        printf("%d * %d = %2d\n", num, (i + 1), num * (i + 1));
    }

    return 0;
}