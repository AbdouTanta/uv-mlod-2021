#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void mult_matrice(int64_t matriceResultat[5][5], int64_t matrice1[5][5], int64_t matrice2[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int somme = 0;
            for (int k = 0; k < 5; k++)
            {
                matriceResultat[i][j] = somme + matrice1[i][k] * matrice2[k][j];
            }
        }
    }
}

void affiche_matrice(int64_t matriceResultat[5][5])
{
    printf("=============MATRICE=============\n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d  ", matriceResultat[i][j]);
        }
        printf("\n\n");
    }
    printf("=============MATRICE=============\n");
}

int main(void)
{
    //matrices en ligne * colonne
    int64_t matrice1[5][5] = {{1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}};
    int64_t matrice2[5][5] = {{6, 7, 8, 9, 10}, {6, 7, 8, 9, 10}, {6, 7, 8, 9, 10}, {6, 7, 8, 9, 10}, {6, 7, 8, 9, 10}};
    int64_t matriceResultat[5][5];
    mult_matrice(matriceResultat, matrice1, matrice2);
    affiche_matrice(matriceResultat);
    return EXIT_SUCCESS;
}
