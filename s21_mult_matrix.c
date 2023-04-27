#include "s21_matrix.h"

int s21_mult_mutrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  ERROR = FAIL;
  if (A != NULL && B != NULL && A->rows > 0 && A->columns > 0 && B->columns > 0
      && A->columns == B->rows) {
    if (result == NULL || result->rows )
  }
}