#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

enum Mois
{
    janvier,
    fevrier,
    mars,
    avril,
    mai,
    juin,
    juillet,
    aout,
    septembre,
    octobre,
    novembre,
    decembre
};

struct Date
{
    /* data */
    int jour;
    enum Mois mois;
    int annee;
};

void initialiseDate(struct Date *d)
{
    int jour;
    enum Mois mois;
    int annee;
    printf("Donnez le jour: ");
    scanf("%d", &d->jour);
    printf("Donnez le mois: ");
    scanf("%d", (int *)&d->mois);
    printf("Donnez l'année: ");
    scanf("%d", &d->annee);
}

afficheDate(struct Date *d)
{
}

int main(void)
{
    struct Date d;
    initialiseDate(&d);
    afficheDate(&d);
    return 0;
}