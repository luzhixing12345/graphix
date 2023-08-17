
CC       = g++
LIBS     =
SDL2     = D:\SDL2\x86_64-w64-mingw32
LDFLAGS  = -lSDL2main -lSDL2
DEFINES  =
INCLUDE  = -I$(SDL2)/include
LIB      = -L$(SDL2)/lib
CFLAGS   = -Wall
CXXFLAGS = 

SRC_PATH := .
SRC_EXT = cpp

SRC := $(wildcard $(SRC_PATH)/*.cpp)
OBJ = $(SRC:$(SRC_EXT)=o)
HEADER = $(wildcard $(SRC_PATH)/*.hpp)
TARGET = main

RM = rm -f

.PHONY: clean

ifeq ($(OS),Windows_NT)
# Windows 平台
TARGET = main.exe
LDFLAGS = -lmingw32 -lSDL2main -lSDL2
else
# Linux 平台
endif


# ifeq ($(MAKECMDGOALS),debug)
# CFLAGS+=-g
# endif

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ $(LIB) $(LDFLAGS) -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< $(INCLUDE) -o $@


clean:
	$(RM) $(OBJ) $(TARGET)