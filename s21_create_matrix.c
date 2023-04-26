#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  ERROR = FAIL;
  if (result != NULL) {
    if (rows > 0 && columns > 0) {
      result->matrix = calloc(rows, sizeof(double));
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = calloc(columns, sizeof(double));
      }
      result->rows = rows;
      result->columns = columns;
      ERROR = OK;
    }
  }
  return ERROR;
}