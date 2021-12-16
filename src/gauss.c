#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b) {
    int rows=mat->r, columns=mat->c;
    double divider;

    for (int k=0; k<columns; ++k) {
        //funkcja porównująca start
        int maks = mat->data[k][k];
        if (maks < 0) maks *= -1;
        int maksC = k;
		for (int j = k; j < columns; j++)
        {
        if (maks < mat->data[j][k] || maks < -1*mat->data[j][k])
        {
            maks = mat->data[j][k];
            maksC = j;
        }
        if (maks < 0) maks *= -1;
        }
        double temp = 0;
        if (maksC != 0) {
            for (int j = 0; j < rows; j++)
            {
            temp = mat->data[k][j];
            mat->data[k][j] = mat->data[maksC][j];
            mat->data[maksC][j] = temp;
            }
        }
        //funkcja porównująca koniec
        printf("zmieniny elemeny glowny \n");
        printToScreen(mat);
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

