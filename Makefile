all: main

SHELL=/bin/bash

CXX = g++
CFLAGS = -g -L./include/

main:
	mkdir -p ./target
	$(CXX) main.cpp reader.c -o ./target/idklang $(CFLAGS)
mingw:
	mkdir -p ./target
	$(CXX) main.cpp reader.c -o ./target/idklang $(CFLAGS) -I/C:/MinGW/include
clean:
	rm -f ./target/idklang*