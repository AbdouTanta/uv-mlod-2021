#include "arbre-bin-recherche.h"
#include <stdlib.h>
#include <stdbool.h>

// retourne TRUE si a est l'arbre vide et FALSE sinon
bool estVide(ArbreBinaire a)
{
	return (a == NULL);
}

// initialise l'arbre a à l'arbre vide
void initialiser(ArbreBinaire *a)
{
	*a = NULL;
}

// créer un arbre contenant un seul noeud ayant la valeur e
ArbreBinaire creer(Element e)
{
	ArbreBinaire a = (ArbreBinaire)malloc(sizeof(ArbreBinaire));
	Noeud *n = malloc(sizeof(Noeud));
	n->val = e;
	a = n;
	return a;
}

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version itérative
ArbreBinaire insere_i(ArbreBinaire a, Element e)
{
	ArbreBinaire b = a;

	// cherche si a existe deja ici

	if (!estVide(b))
	{
		while (b->val != a)
		{
			if (b > b->val)
			{
				if (!estVide(b->filsDroit))
				{
					initialiser(b->filsDroit);
					b->filsDroit = creer(e);
				}
				else
				{
					b = b->filsDroit;
				}
			}
			else
			{
				if (!estVide(b->filsGauche))
				{
					initialiser(b->filsGauche);
					b->filsGauche = creer(e);
				}
				else
				{
					b = b->filsGauche;
				}
			}
		}
	}
	else
	{
		b = creer(e);
	}

	return b;
}

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version récursive
ArbreBinaire insere_r(ArbreBinaire a, Element e)
{
	if (estVide(a))
	{
		a = creer(e);
	}
	else
	{
		if (e > a->val)
		{
			a->filsDroit = insere_r(a->filsDroit, e);
		}
		if (e < a->val)
		{
			a->filsGauche = insere_r(a->filsGauche, e);
		}
		if (e == a->val)
		{
			return a;
		}
	}
	return a;
}

// retourne le nombre de noeud contenus dans l'arbre a
int nombreDeNoeud(ArbreBinaire a)
{
	if (estVide(a))
	{
		return 0;
	}
	else
	{
		return nombreDeNoeud(a->filsDroit) + nombreDeNoeud(a->filsGauche) + 1;
	}
}

// retourne la profondeur du noeud ayant la valeur e dans a
// retourne -1 si a est vide ou si e n'est pas dans a
int profondeur(ArbreBinaire a, Element e)
{
	ArbreBinaire b = a;
	int profondeur = 0;
	if (!estVide(b))
	{
		while (!estVide(b) && (b->val != e))
		{
			if (e > b->val)
			{
				b = b->filsDroit;
			}
			else
			{
				b = b->filsGauche;
			}
			profondeur = profondeur + 1;
		}
	}
	return profondeur;
}

// retourne la hauteur de l'arbre a
int hauteur(ArbreBinaire a)
{
	return 0;
}

// retourne le pere de elem dans l'arbre a ou NULL s'il n'existe pas
ArbreBinaire pere(ArbreBinaire a, Element elem)
{

	return NULL;
}

void afficheRGD_r(ArbreBinaire a)
{
	if (!estVide(a))
	{
		printf("%d ", a->val);

		afficheRGD_r(a->filsGauche);
		afficheRGD_r(a->filsDroit);
	}
}

void afficheGRD_r(ArbreBinaire a)
{
	if (!estVide(a))
	{
		printf("%d ", a->val);

		afficheGRD_r(a->filsDroit);
		afficheGRD_r(a->filsGauche);
	}
}

void afficheGDR_r(ArbreBinaire a)
{
	if (!estVide(a))
	{

		afficheGDR_r(a->filsDroit);
		printf("%d ", a->val);
		afficheGDR_r(a->filsGauche);
	}
}

// retourne le noeud dont la valeur est minimum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire min(ArbreBinaire a)
{
	return NULL;
}

// retourne le noeud dont la valeur est maximum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire max(ArbreBinaire a)
{
	return NULL;
}

// retourne l'arbre dont la valeur de la racine est elem et NULL si elem n'existe dans a
// version récursive
ArbreBinaire recherche_r(ArbreBinaire a, Element elem)
{
	if (estVide(a) || (elem == a->val))
	{
		return a;
	}
	else
	{
		if (elem < a->val)
		{
			return recherche_r(a->filsGauche, elem);
		}
		else
		{
			return recherche_r(a->filsDroit, elem);
		}
	}
	return NULL;
}

// suppime x de a
ArbreBinaire supprimer_r(ArbreBinaire a, Element x)
{

	return NULL;
}

void detruire_r(ArbreBinaire a)
{
}
