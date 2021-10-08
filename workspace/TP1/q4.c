#include <stdio.h>

typedef short TypeEntier;

TypeEntier factorielle(TypeEntier N)
{
    TypeEntier f = N;
    for (int i = f - 1; i > 0; i--)
    {
        f *= i;
    }
    return f;
}

int main()
{
    printf("%i", factorielle(4));
    return 0;
}