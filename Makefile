
GCC = g++
CLEAN = del

.PHONY: clean

all:
	$(GCC) -I src/include -L src/lib -o main main.cpp -lmingw32 -lSDL2main -lSDL2

clean:
	del main.exe