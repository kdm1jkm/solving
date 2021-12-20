#include <stdio.h>

int main()
{
    int nums[6];
    for (int i = 0; i < 6; i++)
    {
        printf("Enter number#%d>>", i + 1);
        scanf("%d", nums + i);
    }

    printf("Before sorting: ");
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6 - i - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
    printf("After sorting: ");
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
}