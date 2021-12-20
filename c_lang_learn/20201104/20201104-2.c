#include <stdio.h>

int main()
{
    int n, r;
    printf("Enter >>");
    scanf("%d %d", &n, &r);

    int result = 1;
    for (int i = 0; i < r; i++)
    {
        printf("%d ", n - i);
        result *= (n - i);
        if (i + 1 < r)
        {
            printf("* ");
        }
    }

    for (int i = 0; i < r; i++)
    {
        printf("/ %d ", r - i);
        result /= (r - i);
    }

    printf("= %d\n", result);
}