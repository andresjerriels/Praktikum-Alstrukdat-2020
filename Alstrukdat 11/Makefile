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

listrek.o:  $(SRC_FILES) $(addprefix $(SRC_DIR)/, listrek.h)
	$(CC) $(CFLAGS) $(PROFILE_FLAGS) $(SRC_FILES) 

check_listrek.o: $(TST_FILES)
	$(CC) $(CFLAGS) $(PROFILE_FLAGS)  $(TST_FILES) 

check_listrek_test: listrek.o check_listrek.o
	$(CC) listrek.o check_listrek.o $(TST_LIBS) $(COV_LIBS) -o check_listrek_test

test: check_listrek_test
	./check_listrek_test

coverage: test
	$(GCOV) $(GCONV_FLAGS)

coverage_report.html: test
	$(GCOV) $(GCONV_FLAGS) -o coverage_report.html

.PHONY: clean all

clean:
	-rm *.o *.html *.gcda *.gcno check_listrek_test