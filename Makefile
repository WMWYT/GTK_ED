gtk_cflag:=$(shell pkg-config --cflags gtk4)
gtk_libs:=$(shell pkg-config --libs gtk4)
BIN := build/bin
OBJ := build/obj

all: caeser affine des sma rsa ED ui main

caeser: src/caesar_code.c
	gcc -c -o ${OBJ}/caesar_code.o src/caesar_code.c

affine: src/affine.c
	gcc -c -o ${OBJ}/affine.o src/affine.c

des: src/des.c
	gcc -c -o ${OBJ}/des.o src/des.c

sma: src/sma.c
	gcc -c -o ${OBJ}/sma.o src/sma.c

rsa: src/rsa.c
	gcc -c -o ${OBJ}/rsa.o src/rsa.c

ED: src/ED_src.c
	gcc -c -o ${OBJ}/ED_src.o src/ED_src.c

ui: ui/gtk_main.c
	gcc ${gtk_cflag} -c -o ${OBJ}/gtk_main.o ui/gtk_main.c ${gtk_libs}

main: main.c
	gcc ${gtk_cflag} ${OBJ}/*.o main.c -o ${BIN}/main ${gtk_libs}

clean:
	rm build/bin/*
	rm build/obj/*