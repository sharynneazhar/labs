#######################################################################
# General Makefile for compiling c++ programs
# Author : Sharynne Azhar
#######################################################################

# Specify the lab number
LAB_NUM=11

# Specify the folder name pattern
FOLDER_NAME := Azhar_Lab$(LAB_NUM)

# Specify a name for the executable
PROG_NAME	:= lab$(LAB_NUM)

# Compilation settings
CC := g++ -std=c++11
CFLAGS := -g

# Specify the files needed for compilation
SRC = ./
INCLUDES = EdgeNode/EdgeNode.h DisjointSet/DisjointSet.h Timer/Timer.h MinSpanTree.h

all: clean $(PROG_NAME)
	./$(PROG_NAME)

# A generalized rule for compiling the executable object
$(PROG_NAME): main.o
	$(CC) $(CFLAGS) main.o -o $(PROG_NAME)

# A generalized rule for compiling c++ source files
main.o: main.cpp $(INCLUDES)
	$(CC) $(CFLAGS) -c main.cpp

# Target for cleaning the generated files
clean:
	@rm -rf *.o $(PROG_NAME)

# Target for compressing the files into archive
zip: clean
	zip -r $(FOLDER_NAME).zip $(SRC)


.PHONY: clean zip
