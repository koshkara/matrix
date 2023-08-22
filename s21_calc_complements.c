#include "s21_matrix.h"
#include <stdio.h>

int s21_calc_complements(matrix_t *A, matrix_t *result)
{
  ERROR = FAIL;
  double value;
  if ( A != NULL && A->rows == A->columns && A->columns > 0) {
    if (result == NULL || result->rows != A->rows || result->columns !=
                                                         A->columns) {
      s21_create_matrix(A->rows, A->columns, result);
    } for (int i = 0; i < result->rows; i++) {
        value = 0;
        s21_determinant(A, &value);
        printf("%f ", value);
        result->matrix[i][i] = pow(-1, i + i) * value;
        ERROR = OK;
    }
  }
  return 0;
}