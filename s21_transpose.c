#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result)
{
  ERROR = FAIL;
  if (A != NULL && A->rows > 0 && A->columns > 0)
  {
    if (result->rows != A->columns || result->columns != A->rows)
    {
      s21_create_matrix(A->columns, A->rows, result);
    }
    for (int i = 0; i < result->rows; i++)
    {
      for (int j = 0; j < result->columns; j++)
      {
        result->matrix[i][j] = A->matrix[j][i];
        ERROR = OK;
      }
    }
  } return ERROR;
}