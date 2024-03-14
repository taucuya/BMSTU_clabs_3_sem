CC := gcc
CFLAGS = -Wall -Werror

all: lib/lib.so

lib/lib.so: ./lib/lib.c ./lib/lib.h
	$(CC) $(CFLAGS) -fPIC -shared -o $@ ./lib/lib.c -lc

SRC_DIR = unit_tests lib
SRCS = $(foreach dir, $(SRC_DIR), $(wildcard $(dir)/*.c))
HEADERS = $(foreach dir, $(SRC_DIR), $(wildcard $(dir)/*.h))

unit_tests.exe: $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) -o $@ $(SRCS) -lcheck -lsubunit -lm

vg_units: unit_tests.exe
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file="unit_vglog.out" -v ./unit_tests.exe 

.PHONY: clean
clean:
	rm ./lib/*.so
