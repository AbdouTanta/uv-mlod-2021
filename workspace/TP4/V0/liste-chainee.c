#include "liste-chainee.h"
#include <stdlib.h>
#include <stdio.h>

#define TODO NULL;

// retourne vrai si l est vide et faux sinon
bool estVide(Liste l)
{
	return l == NULL;
}

// créer une liste d'un seul élément contenant la valeur v
Liste creer(Element v)
{
	Liste l = (Liste)malloc(sizeof(Cellule));
	l->val = v;
	l->suiv = NULL;
	return l;
}

// ajoute l'élément v en tete de la liste l
Liste ajoutTete(Element v, Liste l)
{
	Liste n = creer(v);
	n->suiv = l;
	return n;
}

void afficheElement(Element e)
{
	printf("%i ", e);
}

// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe affiche_element
// Attention la liste peut être vide !
// version itérative
void afficheListe_i(Liste l)
{
	Liste p = l;
	if (!estVide(p))
	{
		printf("Liste ===>  ");
		while (!estVide(p))
		{
			afficheElement(p->val);
			p = p->suiv;
		};
		printf("\n");
	}
	else
	{
		printf("Liste vide!\n");
	}
}

// version recursive
void afficheListe_r(Liste l)
{
	return TODO;
}

void detruireElement(Element e)
{
	return TODO;
}

// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l)
{
	Liste p = l;
	if (!estVide(p))
	{
		while (p->suiv != NULL)
		{
			Liste m = p;
			p = p->suiv;
			free(m);
		}
		l->suiv = NULL;
		free(l);
	}
}

// version récursive
void detruire_r(Liste l)
{
	TODO;
}

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative
Liste ajoutFin_i(Element v, Liste l)
{
	Liste m = l;
	if (!estVide(m))
	{
		while (m->suiv != NULL)
		{
			m = m->suiv;
		}
		m->suiv = creer(v);
	}
	else
	{
		l = creer(v);
	}
	return l;
}

// version recursive
Liste ajoutFin_r(Element v, Liste l)
{
	return TODO;
}

// compare deux elements
bool equalsElement(Element e1, Element e2)
{
	return e1 == e2;
}

// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element v, Liste l)
{
	Liste m = l;
	if (!estVide(l))
	{
		while (m->val != v && m->suiv != NULL)
		{
			m = m->suiv;
		}
		if (m->val == v)
		{
			return m;
		}
		else
		{
			return NULL;
		}
	}
}

// version récursive
Liste cherche_r(Element v, Liste l)
{
	return TODO;
}

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l)
{
	return TODO;
}

// version recursive
Liste retirePremier_r(Element v, Liste l)
{
	return TODO;
}

void afficheEnvers_r(Liste l)
{
	TODO;
}
