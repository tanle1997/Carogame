.PHONY: caroGames

CC=gcc
CFLAGS=-I.
COMPILER_FLAGS+= -Wall -Werror -Wextra -Wunused -Wcast-align -Wconversion \
				-Wpointer-arith -Wcast-qual -Wmissing-prototypes \
				-Wno-missing-braces
SOURCES_FILE+=  file_manager.c \
				lib.c \
				main.c
all: caroGames
main.o: main.c
	${CC} ${COMPILER_FLAGS} -c main.c ${CFLAGS}
lib.o: lib.h lib.c
	${CC} ${COMPILER_FLAGS} -c lib.c ${CFLAGS}
file_manager.o: file_manager.h lib.h lib.c file_manager.c
	${CC} ${COMPILER_FLAGS} -c lib.c file_manager.c ${CFLAGS}
caroGames: main.o lib.o file_manager.o
	${CC} ${COMPILER_FLAGS} -o $@ ${patsubst %.c, %.o, $(SOURCES_FILE)} ${CFLAGS}
	@./$@.exe
clean:
	rm -f *.exe
	rm -f *.o
