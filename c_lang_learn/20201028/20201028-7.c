#include <stdio.h>
// 미완성

int main()
{
    int majorAxis, minorAxis;
    printf("Enter major axis>>");
    scanf("%d", &majorAxis);
    printf("Enter minor axis>>");
    scanf("%d", &minorAxis);

    for (int i = 0; i < minorAxis; i++)
    {
        int temp = i * majorAxis / minorAxis;

        int blankLimit1 = majorAxis / 2 - temp - 1;
        int blankLimit2 = -majorAxis / 2 + temp - 1;
        int blankLimit = (blankLimit1 > blankLimit2) ? blankLimit1 : blankLimit2;

        int numLimit1 = majorAxis / 2 + temp;
        int numLimit2 = majorAxis * 3 / 2 - temp;
        // int numLimit = (numLimit1 < numLimit2) ? numLimit1 : numLimit2;
        int numLimit = majorAxis - blankLimit;

        int j;
        for (j = 0; j < blankLimit; j++)
        {
            printf("  ");
        }
        for (; j < numLimit; j++)
        {
            printf("%02d", j);
        }
        printf("\n");
    }
}