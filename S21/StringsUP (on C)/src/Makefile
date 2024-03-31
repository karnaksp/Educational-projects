CFLAGS = -Wall -Wextra -Werror -pedantic -std=c11
GCOVFLAGS = -fprofile-arcs -ftest-coverage

FLAGS = -lm -lcheck -lpthread -lrt -lsubunit
LIBS = s21_string.a

HEADERS = string_up/s21_string.h
SOURCES = $(wildcard string_up/*.c)

OBJ_LIBRARY := $(patsubst %.c, %.o, $(SOURCES))

UNAME := $(shell uname -s)

%.o: %.c $(HEADERS)
	gcc $(CFLAGS) -c $< -o $@

all: s21_string.a

s21_string.a: $(OBJ_LIBRARY)
	ar rcs $@ $^
	ranlib $@
	rm -rf s21_string/*.o

test: s21_string.a TESTS/SUITE_main.c
	gcc $(CFLAGS) TESTS/SUITE_main.c $(LIBS) -o test.out $(FLAGS)
	./test.out

string_test: s21_string.a TESTS/string_test.c
	gcc $(CFLAGS) TESTS/string_test.c $(LIBS) -o string_test.out $(FLAGS)
	./string_test.out

personal: s21_string.a TESTS/personal.c
	gcc $(CFLAGS) TESTS/personal.c $(LIBS) -o personal.out -lm
	./personal.out

gcov_report: s21_string.a TESTS/SUITE_main.c
	gcc $(GCOVFLAGS) TESTS/SUITE_main.c $(SOURCES) -o report.out $(LIBS) $(FLAGS)
	./report.out
	gcov -f .
	@command -v lcov >/dev/null 2>&1 || { echo >&2 "lcov not found. Please install lcov."; exit 1; }
	lcov -t "gcov_report" -o Coverage_Report.info -c -d .
	genhtml -o ./report Coverage_Report.info
	rm -f *.gcno *.gcda *.info report.out *.gcov

open_report: 
	xdg-open ./report/index-sort-f.html

check:
	find . -type f -name "*.c *.h" -exec clang-format -style=Google -n {} \;

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
	rm -rf ./report

push: clean
	git add .
	git commit -m 'Abobas'
	git push

.PHONY: all install-dependencies rebuild clean test personal gcov_report open_report check