#include <stdio.h>
#include <stdbool.h>

bool estParfait(int nombre)
{
    int somme_des_diviseurs = 0;
    for (int i = 1; i < nombre; i++)
    {
        if (nombre % i == 0)
        {
            somme_des_diviseurs++;
        }
    }
    return (somme_des_diviseurs == nombre);
}

int main(void)
{
    int N = 100;
    for (int i = 1; i < N + 1; i++)
    {
        if (estParfait(i))
        {
            printf("%d \n", i);
        }
    }
    return 0;
}