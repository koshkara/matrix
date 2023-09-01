#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  ERROR = FAIL;
  if (A != NULL && B != NULL && A->rows > 0 && A->columns > 0 && B->columns > 0
      && A->columns == B->rows) {
    if (result->rows != A->rows || result->columns != B->columns) {
      s21_create_matrix(A->rows, B->columns, result);
    }
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        for (int n = 0; n < result->columns; n++) {
          result->matrix[i][j] += A->matrix[i][n] * B->matrix[n][j];
          ERROR = OK;
        }
      }
    }
  } return ERROR;
}