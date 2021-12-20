#include <stdio.h>

int main()
{
    int num;
    printf("Enter num>>");
    scanf("%d", &num);

    int a1, a2, a3;
    a1 = a2 = a3 = 1;
    printf("1 1 ");
    for (int i = 2; i < num; i++)
    {
        a3 = a2;
        a2 = a1;
        a1 = a2 + a3;
        printf("%d ", a1);
    }
    printf("\n");
}