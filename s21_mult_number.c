#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  ERROR = FAIL;
   if (A != NULL && A->rows > 0 && A->columns > 0) {
     if (result == NULL || result->rows != A->rows ||
         result->columns != A->columns) {
       s21_create_matrix(A->rows, A->columns, result);
     }
     for (int i = 0; i < result->rows; i++) {
       for (int j = 0; j < result->columns; j++) {
         result->matrix[i][j] = A->matrix[i][j] * number;
         ERROR = OK;
       }
     }
   } return ERROR;
}