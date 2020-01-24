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
	${CC} -c main.c
lib.o: lib.h lib.c
	${CC} -c lib.c
file_manager.o: file_manager.h lib.h lib.c file_manager.c
	${CC} -c lib.c file_manager.c
caroGames:
	${CC} ${COMPILER_FLAGS} -c $(SOURCES_FILE) ${CFLAGS}
	${CC} ${COMPILER_FLAGS} -o $@ ${patsubst %.c, %.o, $(SOURCES_FILE)} ${CFLAGS}
	@./$@.exe
clean:
	rm -f *.exe
	rm -f *.o
