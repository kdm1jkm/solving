#include <stdio.h>

int main()
{
    float num1 = 1.12345678901234567890123456789;
    double num2 = 1.12345678901234567890123456789;

    printf("float: %f\n", num1);
    printf("double: %lf\n\n", num2);

    // 1.123456이후에는 float의 경우에는 이상한 값들이 나옴
    printf("float: %.15f\n", num1);
    printf("double: %.15lf\n", num2);

    return 0;
}
