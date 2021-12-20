#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793

int main()
{
    double x;
    scanf("%lf", &x);

    printf("%lf\n", sin(x * PI / 180.0));
}