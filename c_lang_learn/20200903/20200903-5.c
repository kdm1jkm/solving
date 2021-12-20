#include <stdio.h>

int main()
{
    int width, height;
    printf("Enter width: ");
    scanf("%d", &width);
    printf("Enter height: ");
    scanf("%d", &height);

    printf("area: %f", width * height / 2.0);

    return 0;
}
