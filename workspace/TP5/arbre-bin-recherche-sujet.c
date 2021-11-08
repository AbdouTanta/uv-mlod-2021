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
	ArbreBinaire init = a;
	if (estVide(a))
		return creer(e);
	else
	{
		while (!estVide(a))
		{
			ArbreBinaire p = a;
			if (a->val == e)
			{
				return init;
			}
			if (e > a->val)
			{
				a = a->filsDroit;
				if (estVide(a))
				{
					p->filsDroit = creer(e);
				}
			}
			else
			{
				a = a->filsGauche;
				if (estVide(a))
				{
					p->filsGauche = creer(e);
				}
			}
		}
	}
	return init;
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
	while (!estVide(b))
	{
		if (e > b->val)
		{
			b = b->filsDroit;
		}
		else if (e < b->val)
		{
			b = b->filsGauche;
		}
		else if (e == b->val)
		{
			return profondeur + 1;
		}
		profondeur = profondeur + 1;
	}

	return -1;
}

// retourne la hauteur de l'arbre a
int hauteur(ArbreBinaire a)
{
	if (!estVide(a))
	{
		int hauteurG = hauteur(a->filsGauche);
		int hauteurD = hauteur(a->filsDroit);
		if (hauteurG >= hauteurD)
			return hauteurG + 1;
		else
			return hauteurD + 1;
	}
	else
	{
		return 0;
	};
}

// retourne le pere de elem dans l'arbre a ou NULL s'il n'existe pas
ArbreBinaire pere(ArbreBinaire a, Element elem)
{
	if (estVide(a))
	{
		return NULL;
	}
	else
	{
		ArbreBinaire pere = a;
		while (!estVide(a) && (a->val != elem))
		{
			pere = a;
			if (elem > a->val)
			{
				a = a->filsDroit;
			}
			else
			{
				a = a->filsGauche;
			}
		}
		if (estVide(a))
		{
			return NULL;
		}
		else
		{
			return pere;
		}
	}
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
		afficheGRD_r(a->filsGauche);
		printf("%d ", a->val);
		afficheGRD_r(a->filsDroit);
	}
}

void afficheGDR_r(ArbreBinaire a)
{
	if (!estVide(a))
	{
		afficheGDR_r(a->filsGauche);
		afficheGDR_r(a->filsDroit);
		printf("%d ", a->val);
	}
}

// retourne le noeud dont la valeur est minimum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire min(ArbreBinaire a)
{
	ArbreBinaire p = a;
	while (!estVide(a))
	{
		p = a;
		a = a->filsGauche;
	}
	return p;
}

// retourne le noeud dont la valeur est maximum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire max(ArbreBinaire a)
{
	ArbreBinaire p = a;
	while (!estVide(a))
	{
		p = a;
		a = a->filsDroit;
	}
	return p;
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
	if (estVide(a))
	{
		return;
	}
	else
	{
		detruire_r(a->filsDroit);
		detruire_r(a->filsGauche);
		free(a);
	}
}
