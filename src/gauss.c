#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */

int select_max_row(Matrix *mat, int column) {
    double mx = -DBL_MAX;
    int row = column;
    for (int i=column; i<mat->r; ++i) {
		if (mat->data[i][column]>mx) {
			row = i;
			mx = mat->data[i][column];
		} else if (-mat->data[i][column]>mx) {
			row = i;
			mx = -mat->data[i][column];
		}
    }
    return row;
}

void swap_rows(Matrix *mat, int row, Matrix *b) {
	int row_to_swap = select_max_row(mat, row);
	double tmp;
	for (int i=0; i<mat->r; ++i) {
		tmp = mat->data[row][i];
		mat->data[row][i]=mat->data[row_to_swap][i];
		mat->data[row_to_swap][i]=tmp;
	}
	tmp = b->data[row][0];
	b->data[row][0]=b->data[row_to_swap][0];
	b->data[row_to_swap][0]=tmp;
}

int eliminate(Matrix *mat, Matrix *b) {
    int rows=mat->r, columns=mat->c;
    double divider;

    for (int k=0; k<columns; ++k) {
        swap_rows(mat, k, b);
        if (mat->data[k][k] == 0) {
            return 1;
        }
        for (int i=k+1; i<rows; ++i) {
            divider=mat->data[i][k]/mat->data[k][k];
            for (int j=0; j<columns; ++j) {
                mat->data[i][j]-=divider*mat->data[k][j];
            }
            b->data[i][0]-=divider*b->data[k][0];
        }
    }

    return 0;
}

