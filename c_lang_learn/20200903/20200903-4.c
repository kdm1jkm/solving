#include <stdio.h>

#define PI 3.141592

int main()
{
    int radius;
    printf("Enter radius: ");
    scanf("%d", &radius);

    printf("area: %f", PI * radius * radius);

    return 0;
}
