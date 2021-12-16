#include "backsubst.h"

/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int backsubst(Matrix *x, Matrix *mat, Matrix *b)
{
    if (mat->r != mat->c) return 2;
    double sum = 0;
    for (int i = 0; i < x->r; i++)
    {
        sum = b->data[b->r - i - 1][0];
        for (int j = 0; j < i; j++)
        {
            sum -= mat->data[x->r - i - 1][mat->r - j - 1] * x->data[x->r - j - 1][0];
        }
        if (mat->data[x->r - i - 1][x->r - i - 1] != 0) x->data[x->r - i - 1][0] = sum/mat->data[x->r - i - 1][x->r - i - 1];
        else return 1;
    }

    return 0;

}


