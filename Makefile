FLAGS = -Wall -Wextra -Werror -std=c11
MATRIX_C = s21_calc_complements.c s21_create_matrix.c s21_determinant.c s21_eq_matrix.c s21_inverse_matrix.c \
	s21_mult_matrix.c s21_mult_number.c s21_remove_matrix.c s21_sub_matrix.c s21_sum_matrix.c s21_transpose.c
MATRIX_O = s21_calc_complements.o s21_create_matrix.o s21_determinant.o s21_eq_matrix.o s21_inverse_matrix.o \
	s21_mult_matrix.o s21_mult_number.o s21_remove_matrix.o s21_sub_matrix.o s21_sum_matrix.o s21_transpose.o

all: gcov_report
clean:
	rm -rf *.o *.out out *.info *.gcda *.gcno *.gcov *.gch *.a test
test: clean
	gcc $(FLAGS) -I../../../../opt/homebrew/include -fprofile-arcs -ftest-coverage $(MATRIX_C) -o test s21_test.c \
	-L../../../../opt/homebrew/Cellar/check/0.15.2/lib -lcheck
	./test
s21_matrix.a: s21_matrix.o
	ar rc s21_decimal a $(MATRIX_O)
	ranlib s21_matrix.a
s21_matrix.o:
	gcc $(FLAGS) -c $(MATRIX_C)
gcov_report: test
	gcov s21_test.c
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory out

rebuild: clean all
clang:
	cp ../materials/linters/.clang-format ./
	clang-fornat -n *.c *.h
leaks:
	leaks -atExit -- ./test | grep LEAK
valgrind:
	valgrind --leak-check=full \
		--show-leak-kinds=all \
		--track-origins=yes \
		--verbose \
		--log-file=valgrind-out.txt \
		./test exampleParam1
cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem ./
docker:
	cd ../materials/build/
	bash run.sh