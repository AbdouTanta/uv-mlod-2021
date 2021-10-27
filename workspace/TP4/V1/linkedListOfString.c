// gcc -W -Wall -std=c99 linkedList.c linkedListOfString.c -o linkedListOfString

// valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all --show-reachable=no ./linkedListOfString

#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// ============
// Definitions of external functions
// ============

void afficheElement(Element e)
{
	printf("%s ", (char *)e);
}

void detruireElement(Element e) {}

// compare deux elements
bool equalsElement(Element e1, Element e2)
{
	return strcmp((char *)e1, (char *)e2) == 0;
}

// ============
// main
// ============

int main(void)
{
	Liste l;

	l = NULL;
	printf("estVide(l) = %s\n", estVide(l) ? "TRUE" : "FALSE");

	l = ajoutTete("!", l);
	l = ajoutTete("!", l);
	l = ajoutTete("!", l);
	l = ajoutTete("Jedi", l);
	l = ajoutTete("est", l);
	l = ajoutTete("un", l);
	l = ajoutTete("Luke", l);

	afficheListe_i(l);

	detruire_r(l);

	return EXIT_SUCCESS;
}