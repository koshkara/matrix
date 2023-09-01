#include "s21_matrix.h"
#include <stdio.h>

int s21_calc_complements(matrix_t *A, matrix_t *result)
{
  ERROR = FAIL;
  matrix_t minor;
  double value;
  s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
  if (A->rows == A->columns && A->columns > 0) {
    if (result == NULL || result->rows != A->rows || result->columns != A->columns) {
      s21_create_matrix(A->rows, A->columns, result);
    }
    for (int k = 0; k < A->rows; k++) {
      for (int m = 0; m < A->columns; m++) {
        for (int i = 0, n = 0; n < minor.rows; i++, n++) {
          for (int j = 0, t = 0; t < minor.columns; j++, t++) {
            if (k == i) {
              i++;
            }
            if (m == j) {
              j++;
            }
            minor.matrix[n][t] = A->matrix[i][j];
          }
        }
        s21_determinant(&minor, &value);
        result->matrix[k][m] = pow(-1, k + m) * value;
      }
    } ERROR = OK;
  }
  return 0;
}