#include <stdio.h>

int main()
{
    int n, r;
    printf("Enter >>");
    scanf("%dP%d", &n, &r);

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

    printf("= %d\n", result);
}