.PHONY = all clean

CC = gcc

BINPATH = /usr/local/bin/testing
SRCPATH = src/

all: sigma
sigma:
	@sudo ${CC} -o ${BINPATH} ${SRCPATH}test.c ${SRCPATH}glad.c -lglfw -lGL

clean:
	@sudo rm -r ${BINPATH}
