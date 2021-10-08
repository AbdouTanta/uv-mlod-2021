#include <stdio.h>

void echangeContenu(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void)
{
    int a = 10;
    int b = 20;
    echangeContenu(&a, &b);
    printf("%d %d", a, b);
    return 0;
}