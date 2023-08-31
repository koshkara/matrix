#include "s21_matrix.h"
#include <stdio.h>

int s21_determinant(matrix_t *A, double *result)
{
  ERROR = FAIL;
  *result = 1;
  matrix_t temp;
  s21_create_matrix(A->rows, A->columns, &temp);
  for (int i = 0; i < temp.rows; i++) {
    for (int j = 0; j < temp.columns; j++) {
      temp.matrix[i][j] = A->matrix[i][j];
    }
  }
  if (A != NULL && A->rows == A->columns && A->columns > 0)
  {
    if (A->rows == 2) {
        *result = A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] *
                                                       A->matrix[1][0];
    }
    if (A->rows == 3) {
        *result = A->matrix[0][0] * A->matrix[1][1] * A->matrix[2][2] +
                  A->matrix[0][1] * A->matrix[1][2] * A->matrix[2][0] +
                  A->matrix[1][0] * A->matrix[2][1] * A->matrix[0][2] -
                  A->matrix[0][2] * A->matrix[1][1] * A->matrix[2][0] -
                  A->matrix[0][1] * A->matrix[1][0] * A->matrix[2][2] -
                  A->matrix[1][2] * A->matrix[2][1] * A->matrix[0][0];
    }
    if (A->rows > 3) {
        for (int n = 0; n < temp.rows - 1; n++) {
          for (int i = n + 1; i < temp.rows; i++) {
            double value;
            value = -temp.matrix[i][n] / temp.matrix[n][n];
            for (int j = 0; j < temp.columns; j++) {
              temp.matrix[i][j] += temp.matrix[n][j] * value;
            }
          }
        }
        for (int i = 0; i < temp.rows; i++) {
          *result *= temp.matrix[i][i];
        }
    }
  } ERROR = OK;
  return 0;
}