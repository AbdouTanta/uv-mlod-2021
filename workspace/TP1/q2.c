#include <stdio.h>

int main(void)
{
    int N = 4;
    int number = 0;
    for (int i = 1; i < 7; i++)
    {
        for (int j = 1; j < 7; j++)
        {
            for (int k = 1; k < 7; k++)
            {
                if (i + j + k == N)
                {
                    number++;
                    printf("%d%d%d\n", i, j, k);
                }
            }
        }
    }
    printf("%d", number);
    return 0;
}