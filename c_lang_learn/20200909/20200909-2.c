#include <stdio.h>

/* - -> 왼쪽 정렬
 * + -> 숫자에 부호
 * 0 -> 빈칸을 0으로 채움
 *
 * %nd -> n자리만큼 확보
 */

int main()
{
    int number = 358;

    printf("|%d|\n", number);
    printf("|%5d|\n", number);
    printf("|%+5d|\n", number);
    printf("|%+5d|\n", -number);
    printf("|%-5d|\n", number);
    printf("|%05d|\n", number);

    return 0;
}
