#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedListOfMusic.h"

// retourne vrai si l est vide et faux sinon
bool estVide(Liste l)
{
    return l == NULL;
}

void detruireElement(Element e){};

bool equalsElement(Element a, Element b)
{
    return true;
}

// créer une liste d'un seul élément contenant la valeur v
Liste creer(Element v)
{
    Liste res;
    res = malloc(sizeof(Cellule));
    res->val = v;
    res->suiv = NULL;
    return res;
}

// ajoute l'élément v en tete de la liste l
Liste ajoutTete(Element v, Liste l)
{
    Liste res = creer(v);
    res->suiv = l;
    return res;
}

void afficheElement(Element e)
{
    printf("%s,", e.name);
    printf("%s,", e.artist);
    printf("%s,", e.album);
    printf("%s,", e.genre);
    printf("%d,", e.discNumber);
    printf("%d,", e.trackNumber);
    printf("%d\n", e.year);
}

// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe affiche_element
// Attention la liste peut être vide !
// version itérative
void afficheListe_i(Liste l)
{
    Liste p = l;

    while (!estVide(p))
    {
        afficheElement(p->val);
        p = p->suiv;
    }
    printf("\n");
}

// version recursive
void afficheListe_r(Liste l)
{
    if (!estVide(l))
    {
        afficheElement(l->val);
        afficheListe_r(l->suiv);
    }
    else
        printf("\n");
}

// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l)
{
    Liste suivant, courant = l;

    while (!estVide(courant))
    {
        suivant = courant->suiv;
        detruireElement(courant->val);
        free(courant);
        courant = suivant;
    }
}

// version récursive
void detruire_r(Liste l)
{
    if (!estVide(l))
    {
        detruire_r(l->suiv);
        detruireElement(l->val);
        free(l);
    }
}

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative
Liste ajoutFin_i(Element v, Liste l)
{
    Liste elem = creer(v);
    Liste p = l;

    if (estVide(p))
        return elem;

    while (!estVide(p->suiv))
        p = p->suiv;
    p->suiv = elem;

    return l;
}

// version recursive
Liste ajoutFin_r(Element v, Liste l)
{
    if (estVide(l))
        return creer(v);
    else
        l->suiv = ajoutFin_r(v, l->suiv);
    return l;
}

// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element v, Liste l)
{
    Liste p = l;

    while (!estVide(p) && !equalsElement(p->val, v))
        p = p->suiv;

    return p;
}

// version récursive
Liste cherche_r(Element v, Liste l)
{
    if (estVide(l) || equalsElement(l->val, v))
        return l;
    else
        return cherche_r(v, l->suiv);
}

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l)
{
    Liste precedent, p;

    if (estVide(l))
        return l;

    if (equalsElement(l->val, v))
    {
        p = l->suiv;
        l->suiv = NULL;
        detruire_r(l);
        return p;
    }

    precedent = l;
    p = l->suiv;
    while (!estVide(p) && !equalsElement(p->val, v))
    {
        precedent = p;
        p = p->suiv;
    }

    if (!estVide(p))
    {
        // on a trouvé v
        precedent->suiv = p->suiv;
        p->suiv = NULL;
        detruire_r(p);
    }

    return l;
}

// version recursive
Liste retirePremier_r(Element v, Liste l)
{
    if (estVide(l))
        return l;

    if (equalsElement(l->val, v))
    {
        Liste p = l->suiv;
        l->suiv = NULL;
        detruire_r(l);
        return p;
    }

    l->suiv = retirePremier_r(v, l->suiv);
    return l;
}

// Affiche la liste l à l'envers i.e. du dernier élément jusqu'au premier
void afficheEnvers_r(Liste l)
{
    if (!estVide(l))
    {
        if (!estVide(l->suiv))
            afficheEnvers_r(l->suiv);
        afficheElement(l->val);
        printf(" ");
    }
}
