all: main

SHELL=/bin/bash

CC = g++
CFLAGS = -g -L./include/
MINGW=  -I/C:/MinGW/include
BUILD_DIR=./build
FINAL=idklang

main:
	mkdir -p $(BUILD_DIR)
	$(CC) main.cpp reader.c -o $(BUILD_DIR)/$(FINAL) $(CFLAGS)
mingw:
	mkdir -p .$(BUILD_DIR)
	$(CC) main.cpp reader.c -o $(BUILD_DIR)/$(FINAL) $(CFLAGS) $(MINGW) 
clean:
	rm -r ./build