#include <stdio.h>

int main()
{
    int nums1[2][2] = {{1, 2}, {3, 4}};
    int nums2[2][2] = {{5, 6}, {7, 8}};

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", nums1[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", nums2[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int result[2][2];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            result[i][j] = nums1[i][j] + nums2[i][j];
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}