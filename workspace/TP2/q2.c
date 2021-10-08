#include <stdio.h>
#include <stdbool.h>

bool estConvexe(bool tab[], int length)
{
    int number_of_switches = 0;
    bool true_exists = false;
    for (int i = 0; i < length - 1; i++)
    {
        if (tab[i + 1] == !tab[i])
        {
            number_of_switches++;
        }
    }
    return (true_exists && number_of_switches <= 2);
}

int main()
{
    bool tab[5] = {false, false, false, false, true};
    printf("%d", estConvexe(tab, 5));
    return 0;
}