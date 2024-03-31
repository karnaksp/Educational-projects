CC=g++
CFLAGS=-Wall -Wextra -Werror -std=c++11 
LDFLAGS=-lgtest -lgtest_main -pthread 
GCOVFLAGS=-fprofile-arcs -ftest-coverage
GCOV_DIR=gcov
GTEST_P_DIR=gtests
OPEN_CMD = open



ifeq ($(shell uname), Linux)
	LDFLAGS += -lsubunit
	OPEN_CMD = xdg-open
endif

TEST_DIR=tests
SRC_TEST_FILES := $(wildcard $(TEST_DIR)/*.cpp)
SRC_FILES := $(wildcard *.cpp)
TEST := tests
TEST_EXECUTABLE := my_tests
LIB = s21_matrix_oop.a

all: s21_matrix_oop.a

test: $(SRC_TEST_FILES) $(SRC_FILES)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) $(GCOVFLAGS) -o $(TEST_EXECUTABLE)
	./$(TEST_EXECUTABLE)

s21_matrix_oop.a:
	$(CC) $(FLAGS) -c $(SRC_FILES)
	ar rc $(LIB) s21_matrix.o
	ranlib $(LIB)

gcov_report: s21_matrix_oop.a $(SRC_TEST_FILES)
	$(CC) $(CFLAGS) $(GCOVFLAGS) $(SRC_TEST_FILES) $(SRC_FILES) -o report.out s21_matrix_oop.a $(LDFLAGS)
	./report.out
	lcov --gcov-tool gcov --capture --directory . --output-file Coverage_Report.info --test-name gcov_report --no-external
	genhtml -o report/ Coverage_Report.info
	rm -f *.gcno *.gcda *.info report.out report_2.out *.gcov
	$(OPEN_CMD) ./report/index.html

clang_n:
	clang-format -n --style=Google *.cpp *.h ./tests/*.cpp ./tests/*.h

clang_i:
	clang-format -i --style=Google *.cpp *.h ./tests/*.cpp ./tests/*.h

clean:
	rm -rf $(TEST_EXECUTABLE)
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf gcov
	rm -rf *.[ao]
	rm -rf ./report