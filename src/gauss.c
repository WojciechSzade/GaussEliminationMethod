#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b) {
    int rows=mat->r, columns=mat->c;
    double divider;

    for (int k=0; k<columns; ++k) {
		// tu bedzie funkcja do wyboru elementu glownego 
		if (mat->data[k][k] == 0) {
			return 1;
        }
        for (int i=k+1; i<rows; ++i) {
            divider=mat->data[i][k]/mat->data[k][k];
            for (int j=0; j<columns; ++j) {
				mat->data[i][j]-=divider*mat->data[k][j];
            }
        }
    }

    return 0;
}

