#include "s21_matrix.h"
//#include <stdio.h>
//
//int main()
//{
//  matrix_t A, B, result;
//  s21_create_matrix(2, 2, &A);
//  s21_create_matrix(2, 2, &B);
//  A.matrix[0][0] = 1;
//  A.matrix[0][1] = 2;
//  A.matrix[1][0] = 3;
//  A.matrix[1][1] = 4;
//  B.matrix[0][0] = 5;
//  B.matrix[0][1] = 6;
//  B.matrix[1][0] = 7;
//  B.matrix[1][1] = 8;
//  s21_sum_matrix(&A, &B, &result);
//  for(int i = 0; i < A.rows; i++) {
//    for (int j = 0; j < A.columns; j++) {
//      printf("%f ", A.matrix[i][j]);
//    } puts("");
//  }
//  for(int i = 0; i < B.rows; i++) {
//    for (int j = 0; j < B.columns; j++) {
//      printf("%f ", B.matrix[i][j]);
//    } puts("");
//  }
//  for(int i = 0; i < result.rows; i++) {
//    for (int j = 0; j < result.columns; j++) {
//      printf("%f ", result.matrix[i][j]);
//    } puts("");
//  }
//  return 0;
//}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  ERROR = FAIL;
  if (A != NULL && B != NULL && A->rows > 0 && A->columns > 0 && B->rows > 0 &&
      B->columns > 0) {
    if (A->rows == B->rows && A->columns == B->columns) {
      if (result == NULL || result->rows != A->rows ||
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