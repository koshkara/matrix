#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  ERROR = FAIL;
  if (A != NULL && B != NULL && A->rows > 0 && A->columns > 0 && B->rows > 0 &&
      B->columns > 0) {
    if (A->rows == B->rows && A->columns == B->columns) {
      if (result->rows != A->rows ||
          result->columns != A->columns) {
        s21_create_matrix(A->rows, A->columns, result);
      }
      for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
          ERROR = OK;
        }
      }
    }
  } return ERROR;
}