#include <stdio.h>
#include <math.h>

int main()
{
    int x1, x2, y1, y2;
    printf("Enter x1,y1 >> ");
    scanf("%d %d", &x1, &y1);
    printf("Enter x2,y2 >> ");
    scanf("%d %d", &x2, &y2);

    printf("Result: %f\n", sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}