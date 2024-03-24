KBUILD_CFLAGS += -w
GCC = gcc
FLAG_GCOV = --coverage
FLAGS = -Wall -Werror -Wextra
TESTFILE = test/s21_SmartCalc
DIST_DIR=s21_SmartCalc-1.0
WORK_DIR=smart_calc
INST_DIR=~/SmartCalc-1.0

PATH_PROJECT = $(shell pwd)
OS = $(shell uname -s)
ifeq ($(OS), Linux) 
	LIBS_OS_CHECK = -lcheck -lsubunit -lm -lpthread -lrt
	OSLINUX = 1
else
	LIBS_OS_CHECK = -lcheck -lm -lpthread
	OSLINUX = 0
endif

all: clean dist install gcov_report 

test: clean
	cp s21*.c test/
	cp s21*.h test/
	bash test/check_test.sh $(GCC) "$(FLAGS)" "$(LIBS_OS_CHECK)" $(FLAG_GCOV)

leak_test: clean
	cp s21*.c test/
	cp s21*.h test/
	bash test/leaks_test.sh $(GCC) "$(FLAGS)" "$(LIBS_OS_CHECK)" $(FLAG_GCOV) "$(OSLINUX)"

gcov_report: test
	bash test/gcov_print.sh
	@gcov test/s21_*.gcda > gcov_test_log.txt
	@lcov -t "s21_SmartCalc" -o $(TESTFILE).info -c -d . > gcov_test_log.txt
	genhtml -o report $(TESTFILE).info
	@-rm -rf test/*.gcda test/*.info test/*.gcno

open_report:
	open $(PATH_PROJECT)/report/index.html

check:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -n --style=Google *.h *.c
	clang-format -n *.h
	clang-format -n *.c
	clang-format -n --style=Google smart_calc/*.cpp
	clang-format -n --style=Google smart_calc/*.h
	-rm -rf .clang-format

clean: uninstall
	-rm -rf *.o *.html *.gcda *.gcno *.css *.a *.gcov *.info *.out *.cfg *.txt a.out.dSYM tests main 
	-rm -rf test/*.gcda test/*.info test/*.gcno test/*.c test/*.o test/*.h
	-rm -rf report
	-rm -rf smart_calc/*.txt
	-rm -rf $(WORK_DIR)/smart_calc
	-rm -rf *.tar
	-rm -rf manual

install:
	@echo "\033[34m===>    Installation has started     <===\033[0m"
	@cd $(WORK_DIR) && exec qmake $(WORK_DIR).pro > /dev/null 2>&1
	@cd $(WORK_DIR) && exec make > /dev/null 2>&1 & \
	pid=$$!; \
	while ps -p $$pid > /dev/null; do \
		echo -n "."; \
		sleep 0.5; \
	done
	@echo ""
	@echo "\033[34m===>    Installation has ended       <===\033[0m"
	@cd $(WORK_DIR) && exec make clean > /dev/null 2>&1
	@cd $(WORK_DIR) && exec rm -rf Makefile > /dev/null 2>&1
	@cd $(WORK_DIR) && exec rm -rf .qmake.stash > /dev/null 2>&1
	@mkdir $(INST_DIR) > /dev/null 2>&1
	@cd $(WORK_DIR) && exec mv smart_calc $(INST_DIR)/s21_smart_calc > /dev/null 2>&1


uninstall:
	-rm -rf $(INST_DIR)

dist:
	-mkdir $(DIST_DIR)
	-mkdir $(DIST_DIR)/$(WORK_DIR)
	cp *.c *.h Makefile $(DIST_DIR)
	cp -R $(WORK_DIR) $(DIST_DIR)
	tar --totals -cvf $(DIST_DIR).tar $(DIST_DIR)
	-rm -rf $(DIST_DIR)

run: install
	$(INST_DIR)/./s21_smart_calc

dvi:
	sudo apt-get install texinfo
	makeinfo ./manual.texi --html
	open ./manual/index.html