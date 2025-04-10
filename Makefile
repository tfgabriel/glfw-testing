.PHONY = all clean

CC = gcc

BINPATH = /usr/local/bin/test
SRCPATH = src/
DEP = glfw3

all: sigma
sigma:
	@sudo ${CC} -o ${BINPATH} ${SRCPATH}test.c ${SRCPATH}glad.c -lglfw -lGL

clean:
	@sudo rm -r ${BINPATH}
