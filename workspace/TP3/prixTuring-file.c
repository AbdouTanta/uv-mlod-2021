/**
 Compilation
 gcc --std=c99 -W -Wall -o prixTuring prixTuring.c

 Exécution
 ./prixTuring < turingWinners.txt > out.txt

 Tests
 diff out.txt turingWinners.txt

 Détection de fuites mémoires
 valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all --show-reachable=no ./prixTuring < turingWinners.txt > out.txt
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Winner
{
    int year;
    char *name;
    char *description;
};

void readWinners(int nbGagnants, struct Winner winners[50])
{
    for (int i = 0; i < nbGagnants; i++)
    {
        // int year = scanLineAsInt();
        // printf("%d \n", year);
        // winners[i].year = year;
        // char *name = scanLine();
        // printf("%s \n", name);
        // winners[i].name = name;
        // char *description = scanLine();
        // printf("%s \n", description);
        // winners[i].description = description;
    }
}

void printWinners(int nbGagnants, struct Winner winners[50])
{
    for (int i = 0; i < nbGagnants; i++)
    {
        printf("%d \n", winners[i].year);
        printf("%s \n", winners[i].name);
        printf("%s \n", winners[i].description);
    }
}

void infosAnnee(int annee, struct Winner winners[50])
{
    for (int i = 0; i < 50; i++)
    {
        if (winners[i].year == annee)
        {
            printf("L'année %d, le(s) gagnant(s) ont été : %s \nNature des travaux : %s \n", winners[i].year, winners[i].name, winners[i].description);
            return;
        }
    }
}

int main(void)
{
    // print the number of winners
    // int nbGagnants = scanLineAsInt();
    // printf("%d \n", nbGagnants);

    // array of winners
    struct Winner winners[50];

    // reading from the file
    char fileName[] = "turingWinners.txt";
    char *line;
    FILE *f;
    f = fopen(fileName, "r");

    for (int i = 0; i < 3 * 50 + 1; i++)
    {
        fgets(line, 255, f);
        printf("%s", line);
    }

    // readWinners(nbGagnants, winners);
    // printWinners(nbGagnants, winners);

    // infosAnnee(2003, winners);

    return EXIT_SUCCESS;
}
