#include <stdio.h>

int main()
{
    int num, x;
    printf("Enter num>>");
    scanf("%d", &num);
    printf("Enter x>>");
    scanf("%d", &x);

    int f = 1;
    int fx = 1;

    double e = 1, ex = 1;
    for (int i = 0; i < num; i++)
    {
        f *= (i + 1);
        fx *= x;
        e += 1.0 / f;
        ex += (float)fx / f;
    }
    printf("e = %lf\n", e);
    printf("e^%d = %lf\n", x, ex);
}