#include <check.h>
#include "s21_matrix.h"
#include <stdio.h>

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
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = 125 + B.columns + i;
      B.matrix[i][j] = 130 + A.rows + j;
    }
  }
  if (s21_sum_matrix(&A, &B, &result) == 0) {
    for (int i = 0; i < result.rows; i++) {
      for (int j = 0; j < result.columns; j++) {
        if (result.matrix[i][j] == 125 + B.columns + i + 130 + A.rows + j) {
          ERROR = OK;
        } else {
          ERROR = FAIL;
        }
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
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      A.matrix[i][j] = 125 + B.columns + i;
      B.matrix[i][j] = 130 + A.rows + j;
    }
  }
  if (s21_sum_matrix(&A, &B, &result) == 0) {
    for (int i = 0; i < result.rows; i++) {
      for (int j = 0; j < result.columns; j++) {
        if (result.matrix[i][j] == 125 + B.columns + i + 130 + A.rows + j) {
          ERROR = OK;
        } else {
          ERROR = FAIL;
        }
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
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = 125 + B.columns + i;
      B.matrix[i][j] = 130 + A.rows + j;
    }
  }
  s21_sub_matrix(&A, &B, &result);
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      if (result.matrix[i][j] == 125 + B.columns + i - 130 - A.rows - j) {
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
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      A.matrix[i][j] = 125 + B.columns + i;
      B.matrix[i][j] = 130 + A.rows + j;
    }
  }
  s21_sub_matrix(&A, &B, &result);
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      if (result.matrix[i][j] == 125 + B.columns + i - 130 - A.rows - j) {
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
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      A.matrix[i][j] = 125 + A.columns + i;
    }
  }
  s21_mult_number(&A, number, &result);
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      if (result.matrix[i][j] == (125 + A.columns + i) * number) {
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
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = 125 + A.columns + i;
    }
  }
  s21_mult_number(&A, number, &result);
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      if (result.matrix[i][j] == (125 + A.columns + i) * number) {
        ERROR = OK;
      } else {
        ERROR = FAIL;
      }
    }
  }
  ck_assert_int_eq(0, ERROR);
}
END_TEST

START_TEST(mult_matrix_1) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = 125 + B.columns + i;
      B.matrix[i][j] = 130 + A.rows + j;
    }
  }
  s21_mult_matrix(&A, &B, &result);
  ERROR = FAIL;
  if (result.matrix[0][0] == 33528) {
    if (result.matrix[0][1] == 33782) {
      if (result.matrix[1][0] == 33792) {
        if (result.matrix[1][1] == 34048) {
          ERROR = OK;
        }
      }
    }
  }
  ck_assert_int_eq (0, ERROR);
}
END_TEST

START_TEST(transpose_1) {
  matrix_t A, result;
  s21_create_matrix(2, 4, &A);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = 125 + A.columns + j;
    }
  }
  s21_transpose(&A, &result);
  ERROR = FAIL;
  if (result.matrix[0][0] == 129) {
    if (result.matrix[0][1] == 129) {
      if (result.matrix[1][0] == 130) {
        if (result.matrix[1][1] == 130) {
          if (result.matrix[2][0] == 131) {
            if (result.matrix[2][1] == 131) {
              if (result.matrix[3][0] == 132) {
                if (result.matrix[3][1] == 132) {
                  ERROR = OK;
                }
              }
            }
          }
        }
      }
    }
  }
  ck_assert_int_eq (0, ERROR);
}
END_TEST

//START_TEST(complements) {
//  matrix_t A, result;
//  s21_create_matrix(4, 4, &A);
//  for (int i = 0; i < A.rows; i++) {
//    for (int j = 0; j < A.columns; j++) {
//      A.matrix[i][j] = 125 + A.columns + j + i;
//      printf("%f ", A.matrix[i][j]);
//    }
//    puts("");
//  }
//  s21_calc_complements(&A, &result);
//  ERROR = FAIL;
//  if (result.matrix[0][0] == 129) {
//    if (result.matrix[0][1] == 129) {
//      if (result.matrix[1][0] == 130) {
//        if (result.matrix[1][1] == 130) {
//          if (result.matrix[2][0] == 131) {
//            if (result.matrix[2][1] == 131) {
//              if (result.matrix[3][0] == 132) {
//                if (result.matrix[3][1] == 132) {
//                  ERROR = OK;
//                }
//              }
//            }
//          }
//        }
//      }
//    }
//  }
//  ck_assert_int_eq (0, ERROR);
//}
//END_TEST

START_TEST(determinant) {
  matrix_t A;
  double result;
  s21_create_matrix(5, 5, &A);
  A.matrix[0][0] = 5;
  A.matrix[0][1] = 15;
  A.matrix[0][2] = 87;
  A.matrix[0][3] = -9;
  A.matrix[0][4] = 9;
  A.matrix[1][0] = 9.3;
  A.matrix[1][1] = -0.7;
  A.matrix[1][2] = -13.56;
  A.matrix[1][3] = 78;
  A.matrix[1][4] = 98;
  A.matrix[2][0] = 23;
  A.matrix[2][1] = -10;
  A.matrix[2][2] = -9.7;
  A.matrix[2][3] = 0.45;
  A.matrix[2][4] = 6.76;
  A.matrix[3][0] = 4.76;
  A.matrix[3][1] = -0.34;
  A.matrix[3][2] = -90;
  A.matrix[3][3] = -56;
  A.matrix[3][4] = 34;
  A.matrix[4][0] = 43;
  A.matrix[4][1] = 23;
  A.matrix[4][2] = 4.5;
  A.matrix[4][3] = 6.2;
  A.matrix[4][4] = 6.2;
  s21_determinant(&A, &result);
  ck_assert_double_eq (1, round(result/-769115573.031481));
}
END_TEST

START_TEST(determinant1) {
  matrix_t A;
  double result;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 5;
  A.matrix[0][1] = 15;
  A.matrix[0][2] = 87;
  A.matrix[1][0] = 9.3;
  A.matrix[1][1] = -0.7;
  A.matrix[1][2] = -13.56;
  A.matrix[2][0] = 23;
  A.matrix[2][1] = -10;
  A.matrix[2][2] = -9.7;
  s21_determinant(&A, &result);
  ck_assert_double_eq (1, round(result/-10659.4));
}
END_TEST

START_TEST(determinant2) {
  matrix_t A;
  double result;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 5;
  A.matrix[0][1] = 15;
  A.matrix[1][0] = 9.3;
  A.matrix[1][1] = -0.7;
  s21_determinant(&A, &result);
  ck_assert_double_eq (1, round(result/-143));
}
END_TEST

START_TEST(complements) {
  matrix_t a, b;
  s21_create_matrix(4,4,&a);
  s21_create_matrix(2,3, &b);
  a.matrix[0][0] = 3;
  a.matrix[0][1] = 5;
  a.matrix[0][2] = 3;
  a.matrix[0][3] = 2;
  a.matrix[1][0] = -4;
  a.matrix[1][1] = 5;
  a.matrix[1][2] = 3;
  a.matrix[1][3] = -4;
  a.matrix[2][0] = 4;
  a.matrix[2][1] = 6;
  a.matrix[2][2] = 7;
  a.matrix[2][3] = 4;
  a.matrix[3][0] = 8;
  a.matrix[3][1] = 7;
  a.matrix[3][2] = -3;
  a.matrix[3][3] = -4;
  s21_calc_complements(&a, &b);
  ck_assert_int_eq (344, b.matrix[0][0]);
  ck_assert_int_eq (-480, b.matrix[0][1]);
  ck_assert_int_eq (528, b.matrix[0][2]);
  ck_assert_int_eq (-548, b.matrix[0][3]);
  ck_assert_int_eq (58, b.matrix[1][0]);
  ck_assert_int_eq (-40, b.matrix[1][1]);
  ck_assert_int_eq (-44, b.matrix[1][2]);
  ck_assert_int_eq (79, b.matrix[1][3]);
  ck_assert_int_eq (-216, b.matrix[2][0]);
  ck_assert_int_eq (240, b.matrix[2][1]);
  ck_assert_int_eq (-352, b.matrix[2][2]);
  ck_assert_int_eq (252, b.matrix[2][3]);
  ck_assert_int_eq (-102, b.matrix[3][0]);
  ck_assert_int_eq (40, b.matrix[3][1]);
  ck_assert_int_eq (-44, b.matrix[3][2]);
  ck_assert_int_eq (119, b.matrix[3][3]);
}
END_TEST

START_TEST(inverse) {
  matrix_t a, b;
  s21_create_matrix(4,4,&a);
  s21_create_matrix(2,3, &b);
  a.matrix[0][0] = 3;
  a.matrix[0][1] = 5;
  a.matrix[0][2] = 3;
  a.matrix[0][3] = 2;
  a.matrix[1][0] = -4;
  a.matrix[1][1] = 5;
  a.matrix[1][2] = 3;
  a.matrix[1][3] = -4;
  a.matrix[2][0] = 4;
  a.matrix[2][1] = 6;
  a.matrix[2][2] = 7;
  a.matrix[2][3] = 4;
  a.matrix[3][0] = 8;
  a.matrix[3][1] = 7;
  a.matrix[3][2] = -3;
  a.matrix[3][3] = -4;
//  for (int i = 0; i < a.rows; i++) {
//    for (int j = 0; j < a.columns; j++) {
//      printf("%f ", a.matrix[i][j]);
//    } puts("");
//  }
  s21_inverse_matrix(&a, &b);
  ck_assert_int_eq (-43, b.matrix[0][0]*110);
  ck_assert_int_eq (-29, b.matrix[0][1]*440);
  ck_assert_int_eq (27, b.matrix[0][2]*110);
  ck_assert_int_eq (51, b.matrix[0][3]*440);
  ck_assert_int_eq (6, b.matrix[1][0]*11);
  ck_assert_int_eq (1, b.matrix[1][1]*22);
  ck_assert_int_eq (-3, b.matrix[1][2]*11);
  ck_assert_int_eq (-1, b.matrix[1][3]*22);
  ck_assert_int_eq (-3, b.matrix[2][0]*5);
  ck_assert_int_eq (1, b.matrix[2][1]*20);
  ck_assert_int_eq (2, b.matrix[2][2]*5);
  ck_assert_int_eq (1, b.matrix[2][3]*20);
  ck_assert_int_eq (137, b.matrix[3][0]*220);
  ck_assert_int_eq (-63, b.matrix[3][2]*220);
  ck_assert_int_eq (-119, b.matrix[3][3]*880);
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
  tcase_add_test(tc_core, mult_matrix_1);
  tcase_add_test(tc_core, transpose_1);
  tcase_add_test(tc_core, complements);
  tcase_add_test(tc_core, determinant);
  tcase_add_test(tc_core, determinant1);
  tcase_add_test(tc_core, determinant2);
  tcase_add_test(tc_core, inverse);
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