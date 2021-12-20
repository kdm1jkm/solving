#include <stdio.h>

/* - -> 왼쪽 정렬
 * + -> 숫자에 부호
 * 0 -> 빈칸을 0으로 채움
 *
 * %n.mF -> n자리만큼 확보, m자리만큼 소수점 출력
 */

int main()
{
    double number = 358.123000;

    printf("|%.6f|\n", number);
    printf("|%.2f|\n", number);
    printf("|%7.1f|\n", number);
    printf("|%7.1f|\n", -number);
    printf("|%-7.1f|\n", number);
    printf("|%010.3f|\n", number);

    return 0;
}
