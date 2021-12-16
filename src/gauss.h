#ifndef _GAUSS_H
#define _GAUSS_H

#include "mat_io.h"
#include <float.h>

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b);

void swap_rows(Matrix *mat, int row, Matrix *b);

int select_max_row(Matrix *mat, int column);

#endif
