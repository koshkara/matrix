#include "s21_matrix.h"
#include <stdio.h>

int s21_inverse_matrix (matrix_t *A, matrix_t *result) {
  ERROR = FAIL;
  double determinant;
  matrix_t minor;
  s21_create_matrix(A->rows, A->columns, &minor);
  if (A != NULL && A->rows == A->columns && A->columns > 0) {
    if (result == NULL || result->rows != A->rows || result->columns !=
                                                         A->columns) {
      s21_create_matrix(A->rows, A->columns, result);
    }
    if (s21_determinant(A, &determinant) == 0) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
        }
      }
      s21_calc_complements(A, &minor);
      for (int i = 0; i < minor.rows; i++) {
        for (int j = 0; j < minor.columns; j++) {
        }
      }
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = minor.matrix[j][i];
          result->matrix[i][j] *= 1 / determinant;
        }
      } ERROR = OK;
    }
  } return 0;
}