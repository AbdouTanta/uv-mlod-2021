#include <stdio.h>

struct Matrix
{
    int nombreLignes;
    int nombreColonnes;
    float array[];
};

// nope
typedef struct Matrix MatrixArray[];

MatrixArray *readMatrixArray()
{
    int nombreMatrices;
    int nombreLignes, nombreColonnes;
    struct Matrix matrix;
    MatrixArray matrixArray = malloc(nombreMatrices * size(matrix));
    for (int i = 0; i < nombreMatrices; i++)
    {
        scanf("%d %d", &nombreLignes, &nombreColonnes);
        matrix = readMatrix(nombreLignes, nombreColonnes);
        matrixArray[i] = matrix;
    }
    return matrixArray;
}

struct Matrix readMatrix(int nombreLignes, int nombreColonnes)
{
    struct Matrix matrix;
    matrix.nombreLignes = nombreLignes;
    matrix.nombreColonnes = nombreColonnes;
    float array[nombreColonnes * nombreLignes];
    for (int i; i < nombreLignes; i++)
    {
        for (int j; j < nombreColonnes; j++)
        {
            scanf("%f", &array[i + j]);
        }
    };

    return matrix;
}

void printMatrix(struct Matrix matrix)
{
    for (int i = 0; i < matrix.nombreLignes; i++)
    {
        for (int j = 0; i < matrix.nombreColonnes; j++)
        {
            printf("%f ", &matrix.array[i + j]);
        }
        printf("\n");
    }
    return;
}

void printMatrixArray(MatrixArray matrixArray, int nombreMatrices)
{
    for (int i = 0; i < nombreMatrices; i++)
    {
        printf("%d %d", &matrixArray[i].nombreLignes, &matrixArray[i].nombreColonnes);
        printMatrix(matrixArray[i]);
    }
    return;
}

void printAll(int nombreMatrices, MatrixArray matrixArray)
{
    printf("%d", nombreMatrices);
    printMatrixArray(matrixArray, nombreMatrices);
}

int main(void)
{
    int nombreMatrices;
    scanf("%d", nombreMatrices);

    MatrixArray *matrixArray;

    matrixArray = readMatrixArray(nombreMatrices);
    printAll(nombreMatrices, matrixArray);

    return 0;
}