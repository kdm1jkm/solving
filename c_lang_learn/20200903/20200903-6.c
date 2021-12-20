#include <stdio.h>

int main()
{
    int korean, english, math;
    printf("Enter Korean Score: ");
    scanf("%d", &korean);
    printf("Enter English score: ");
    scanf("%d", &english);
    printf("Enter Math score: ");
    scanf("%d", &math);

    printf("Sum: %d\n", korean + english + math);
    printf("Average: %f\n", (korean + english + math) / 3.0);

    return 0;
}
