CFLAGS = -Wall -Wextra -Werror -pedantic -std=c11
GCOVFLAGS = -fprofile-arcs -ftest-coverage

FLAGS = -lcheck -lm -lpthread -lrt -lsubunit
LIBS = s21_decimal.a

HEADERS = s21_decimal.h
SOURCES = $(wildcard *.c ./BIG_DECIMAL/*.c)

OBJ_LIBRARY := $(patsubst %.c, %.o, $(SOURCES))

UNAME := $(shell uname -s)

%.o: %.c $(HEADERS)
	gcc $(CFLAGS) -c $< -o $@

all: s21_decimal.a

s21_decimal.a: $(OBJ_LIBRARY)
	ar rcs $@ $^
	ranlib $@
	rm -rf *.o

test: s21_decimal.a TEST/test.c
	gcc $(CFLAGS) TEST/test.c $(LIBS) -o test.out $(FLAGS)
	./test.out

test_set_bit: s21_decimal.a TEST/test_set_bit.c
	gcc $(CFLAGS) TEST/test_set_bit.c $(LIBS) -o test.out $(FLAGS)
	./test.out

test2: 
	$(MAKE) s21_decimal.a
	checkmk TEST/decimal_tests.check > TEST/decimal_tests.c 
	gcc $(CFLAGS) TEST/decimal_tests.c $(LIBS) -o test.out $(FLAGS)
	./test.out

gcov_report: $(LIBS) TEST/test.c
	gcc $(GCOVFLAGS) TEST/test.c $(SOURCES) -o report.out $(LIBS) $(FLAGS)
	./report.out
	checkmk TEST/decimal_tests.check > TEST/decimal_tests.c
	gcc $(GCOVFLAGS) TEST/decimal_tests.c $(SOURCES) -o report_2.out $(LIBS) $(FLAGS)
	./report_2.out
	lcov -c -d . -o s21_combined_test.info
	genhtml s21_combined_test.info --output-directory report
	rm -rf *.gcno *.gcda *.info report.out report_2.out

open_report: 
	open ./report/index-sort-f.html

check:
	clang-format -style=Google -n */*.c */*.h

clang-format:
	clang-format -style=Google -i */*.c */*.h

leaks:
	if [ "$(UNAME)" = "Linux" ]; then \
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes --log-file=valgrind.log ./test.out; grep "ERROR SUMMARY" valgrind.log; \
	fi
	if [ "$(UNAME)" = "Darwin" ]; then \
	leaks -atExit -- ./main.out | grep LEAK:; \
	fi

install_dependencies:
	if [ "$(UNAME)" = "Linux" ]; then \
		sudo apt-get update && \
		sudo apt-get install -y check libsubunit-dev lcov valgrind; \
	fi
	if [ "$(UNAME)" = "Darwin" ]; then \
		brew install check lcov valgrind; \
	fi

rebuild: clean all test gcov_report check leaks

clean:
	rm -f *.o *.a *.gcno *.gcda *.info *.out *.gcov *.log
	rm -f ./BIG_DECIMAL/*.o
	rm -rf ./report
	rm -rf ./TEST/decimal_tests.c

push: clean
	git add .
	git commit -m 'Abobas'
	git push

.PHONY: all install-dependencies rebuild clean test personal gcov_report open_report check