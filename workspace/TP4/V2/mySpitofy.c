#include "linkedListOfMusic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Récupérer une musique depuis une ligne du fichier
Element *getMusicFromLine(char *line)
{
    // Allocation de mémoire pour un élément Music
    Element *music = malloc(sizeof(Element));

    // récupération des infos séparés par la virgule
    music->name = strsep(&line, ",");
    music->artist = strsep(&line, ",");
    music->album = strsep(&line, ",");
    music->genre = strsep(&line, ",");
    music->discNumber = atoi(strsep(&line, ","));
    music->trackNumber = atoi(strsep(&line, ","));
    music->year = atoi(strsep(&line, ","));

    return music;
}

int main()
{
    // read music.csv file
    char filename[] = "music.csv";
    FILE *f;
    f = fopen(filename, "r");
    char *firstline = malloc(255 * sizeof(char));

    // skip la premiere ligne du tableau
    fgets(firstline, 255, f);
    printf("%s", firstline);

    Liste musicList = NULL;
    Element *music;

    // pour chaque ligne du fichier, stocker les infos music et les ajouter dans la liste
    while (fgets(firstline, 255, f))
    {
        char *line = strdup(firstline);
        music = getMusicFromLine(line);
        musicList = ajoutFin_r(*music, musicList);
        free(music);
        free(line);
    }

    // afficher la liste de music
    afficheListe_r(musicList);
    
    // afficher liste triée
    // musicList = trierListe(musicList);
    // afficheListe_r(musicList);

    fclose(f);

    detruire_r(musicList);
    free(firstline);

    return 0;
}
