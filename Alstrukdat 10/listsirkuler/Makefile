CC = gcc
CFLAGS = -c -Wall
PROFILE_FLAGS = -fprofile-arcs -ftest-coverage
TST_LIBS = -lcheck -lm -lpthread
COV_LIBS = -coverage
SRC_DIR= src
TST_DIR= test
SRC_FILES = $(addprefix $(SRC_DIR)/, *.c) 
TST_FILES = $(addprefix $(TST_DIR)/, *.c)
GCOV = gcovr 
GCONV_FLAGS = -s -d


all: coverage

listsirkuler.o:  $(SRC_FILES) $(addprefix $(SRC_DIR)/, listsirkuler.h)
	$(CC) $(CFLAGS) $(PROFILE_FLAGS) $(SRC_FILES) 

check_listsirkuler.o: $(TST_FILES)
	$(CC) $(CFLAGS) $(PROFILE_FLAGS)  $(TST_FILES) 

check_listsirkuler_test: listsirkuler.o check_listsirkuler.o
	$(CC) listsirkuler.o check_listsirkuler.o $(TST_LIBS) $(COV_LIBS) -o check_listsirkuler_test

test: check_listsirkuler_test
	./check_listsirkuler_test

coverage: test
	$(GCOV) $(GCONV_FLAGS)

coverage_report.html: test
	$(GCOV) $(GCONV_FLAGS) -o coverage_report.html

.PHONY: clean all

clean:
	-rm *.o *.html *.gcda *.gcno check_listsirkuler_test