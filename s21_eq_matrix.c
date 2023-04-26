#include "s21_matrix.h"
#include <math.h>
#define SUCCESS 1
#define FAILURE 0

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int result = 0;
  if (A != NULL && B != NULL && A->rows > 0 && A->columns > 0 && B->rows > 0 &&
      B->columns > 0 ) {
    if (A->rows == B->rows && A->columns == B->columns) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          double value_A = round(A->matrix[i][j]*10000000);
          double value_B = round(B->matrix[i][j]*10000000);
          if (value_A != value_B) {
            i = A->rows;
            result = FAILURE;
            break;
          } else {
            result = SUCCESS;
          }
        }
      }
    }
  } return result;
}