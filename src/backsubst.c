#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int backsubst(Matrix *x, Matrix *mat, Matrix *b)
    {
    if (mat->r != mat->c) return 2;
    int sum = 0;
    //x->data[x->r][0] = b->data[b->r][0]/mat->data[mat->r][mat->r];
    for (int i = 0; i < x->r; i++)
    {
        sum = b->data[b->r - i][0];
        for (int j = 0; j < i; j++)
        {
            sum -= data[x->r - i][mat->r - j] * x->data[x->r - j][0]; //możliwe ze przy data na odwrot []
        }
        if (mat->data[x->r - i][x->r - i] != 0) x->data[x->r-i] = sum/mat->data[x->r - i][x->r - i];
        else return 1;
    }


    /*int i;
    for (i =0; i < x->r; i++) {
        x->data[i][0] = b->data[i][0];

    }
    */
    return 0;

}


