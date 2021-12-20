#include <stdio.h>

#define INCH_PER_CENTIMETER 2.54

int main()
{
    int inch;
    printf("Enter inch: ");
    scanf("%d", &inch);

    printf("Centimeter: %f", inch * INCH_PER_CENTIMETER);

    return 0;
}
