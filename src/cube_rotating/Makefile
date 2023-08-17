
CC      := g++
LIBS    :=
LDFLAGS := -lSDL2main -lSDL2
DEFINES :=
INCLUDE := 
CFLAGS  := -Wall
CXXFLAGS:= 

SRC_PATH := .
SRC_EXT = cpp

SRC := $(wildcard $(SRC_PATH)/*.cpp)
OBJ = $(SRC:$(SRC_EXT)=o)
HEADER = $(wildcard $(SRC_PATH)/*.hpp)
TARGET = main

.PHONY: clean

# ifeq ($(MAKECMDGOALS),debug)
# CFLAGS+=-g
# endif

main: $(OBJ)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm $(OBJ) $(TARGET)