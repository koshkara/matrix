#include <check.h>
#include "s21_matrix.h"
#include "stdio.h"

START_TEST(create_matrix_1) {
  int rows = 5;
  int columns = 500;
  matrix_t result;
  ck_assert_int_eq(0, s21_create_matrix(rows,columns,&result));
}
END_TEST

START_TEST(create_matrix_2) {
  int rows = 0;
  int columns = 0;
  matrix_t result;
  ck_assert_int_eq(1, s21_create_matrix(rows,columns,&result));
}
END_TEST

START_TEST(create_matrix_3) {
  int rows = -100;
  int columns = -200;
  matrix_t matrix;
  ck_assert_int_eq(1, s21_create_matrix(rows,columns,&matrix));
}
END_TEST

START_TEST(remove_matrix_1) {
  matrix_t matrix;
  s21_create_matrix(7, 8, &matrix);
  s21_remove_matrix(&matrix);
  ck_assert_int_eq(0, matrix.columns);
  ck_assert_int_eq(0, matrix.rows);
  ck_assert_ptr_null(matrix.matrix[0]);
  ck_assert_int_eq(0, ERROR);
}
END_TEST

START_TEST(eq_matrix_1) {
  matrix_t A, B;
  s21_create_matrix(7, 8, &A);
  s21_create_matrix(7, 8, &B);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = A.rows + A.columns + i + j * 0.0001;
      B.matrix[i][j] = A.matrix[i][j];
    }
  }
  ck_assert_int_eq(1, s21_eq_matrix(&A, &B));
}
END_TEST

START_TEST(eq_matrix_2) {
  matrix_t A, B;
  s21_create_matrix(15, 16, &A);
  s21_create_matrix(15, 16, &B);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = A.rows + A.columns + i + j * 0.0001;
      B.matrix[i][j] = A.matrix[i][j] + 0.3;
    }
  }
  ck_assert_int_eq(0, s21_eq_matrix(&A, &B));
}
END_TEST

START_TEST(sum_matrix_0) {
  matrix_t A, B, result;
  s21_create_matrix(1, 2, &A);
  s21_create_matrix(1, 2, &B);
  s21_create_matrix(1, 1, &result);
  s21_sum_matrix(&A, &B, &result);
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      if (result.matrix[i][j] == A.matrix[i][j] + B.matrix[i][j]) {
        ERROR = OK;
      } else {
        ERROR = FAIL;
      }
    }
  }
  ck_assert_int_eq(0, ERROR);
}
END_TEST

START_TEST(sum_matrix_1) {
  matrix_t A, B, result;
  s21_create_matrix(1, 2, &A);
  s21_create_matrix(1, 2, &B);
  s21_create_matrix(1, 2, &result);
  s21_sum_matrix(&A, &B, &result);
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      if (result.matrix[i][j] == A.matrix[i][j] + B.matrix[i][j]) {
        ERROR = OK;
      } else {
        ERROR = FAIL;
      }
    }
  }
  ck_assert_int_eq(0, ERROR);
}
END_TEST

START_TEST(sub_matrix_0) {
  matrix_t A, B, result;
  s21_create_matrix(1, 2, &A);
  s21_create_matrix(1, 2, &B);
  s21_create_matrix(1, 1, &result);
  s21_sub_matrix(&A, &B, &result);
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      if (result.matrix[i][j] == A.matrix[i][j] - B.matrix[i][j]) {
        ERROR = OK;
      } else {
        ERROR = FAIL;
      }
    }
  }
  ck_assert_int_eq(0, ERROR);
}
END_TEST

START_TEST(sub_matrix_1) {
  matrix_t A, B, result;
  s21_create_matrix(1, 2, &A);
  s21_create_matrix(1, 2, &B);
  s21_create_matrix(1, 2, &result);
  s21_sub_matrix(&A, &B, &result);
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      if (result.matrix[i][j] == A.matrix[i][j] - B.matrix[i][j]) {
        ERROR = OK;
      } else {
        ERROR = FAIL;
      }
    }
  }
  ck_assert_int_eq(0, ERROR);
}
END_TEST

START_TEST(mult_number_matrix_0) {
  matrix_t A, result;
  double number = 9.938575839;
  s21_create_matrix(1, 2, &A);
  s21_create_matrix(1, 2, &result);
  s21_mult_number(&A, number, &result);
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      if (result.matrix[i][j] == A.matrix[i][j] * number) {
        ERROR = OK;
      } else {
        ERROR = FAIL;
      }
    }
  }
  ck_assert_int_eq(0, ERROR);
}
END_TEST

START_TEST(mult_number_matrix_1) {
  matrix_t A, result;
  double number = 9.938575839;
  s21_create_matrix(1, 2, &A);
  s21_create_matrix(1, 1, &result);
  s21_mult_number(&A, number, &result);
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      if (result.matrix[i][j] == A.matrix[i][j] * number) {
        ERROR = OK;
      } else {
        ERROR = FAIL;
      }
    }
  }
  ck_assert_int_eq(0, ERROR);
}
END_TEST

Suite *s21_matrix_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("s21_matrix");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, create_matrix_1);
  tcase_add_test(tc_core, create_matrix_2);
  tcase_add_test(tc_core, create_matrix_3);
  tcase_add_test(tc_core, remove_matrix_1);
  tcase_add_test(tc_core, eq_matrix_1);
  tcase_add_test(tc_core, eq_matrix_2);
  tcase_add_test(tc_core, sum_matrix_0);
  tcase_add_test(tc_core, sum_matrix_1);
  tcase_add_test(tc_core, sub_matrix_0);
  tcase_add_test(tc_core, sub_matrix_1);
  tcase_add_test(tc_core, mult_number_matrix_0);
  tcase_add_test(tc_core, mult_number_matrix_1);

  suite_add_tcase(s, tc_core);

  return s;
}

int main(void) {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = s21_matrix_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_SILENT);
  srunner_run_all(sr,CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}