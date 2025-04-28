.PHONY = all clean

CC = gcc

BINPATH = /usr/local/bin/testing
INCPATH = ../dependencies/include/glad
CCFLAGS = -I${INCPATH}

all: compile
install: 
	@cp -f testing ${BINPATH} 

compile :
	@ ${CC} -o -I..../include/glad testing src/* -lglfw -lGL

clean:
	@sudo rm -r ${BINPATH} ./testing

run: compile
	./testing
