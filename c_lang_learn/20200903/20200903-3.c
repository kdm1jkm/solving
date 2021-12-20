#include <stdio.h>

int main()
{
    int width, height, area;

    scanf("%d %d", &width, &height);
    area = (width * height) / 2;
    printf("width: %d, height: %d, area: %d\n", width, height, area);

    return 0;
}
