#include <stdio.h>

int main(void)
{
    int prix_plein_tarif = 50;
    int age = 52;
    if (age < 2)
    {
        printf("%f", 0.1 * prix_plein_tarif);
        return 0;
    }
    else if (age < 12)
    {
        printf("%f", 0.5 * prix_plein_tarif);
        return 0;
    }
    printf("%d", prix_plein_tarif);
    return 0;
}