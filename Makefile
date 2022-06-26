
GCC = g++
CLEAN = del

.PHONY: clean

all: main.cpp transform.cpp screen.cpp
	$(GCC) -I src/include -L src/lib -o main main.cpp transform.cpp screen.cpp -lmingw32 -lSDL2main -lSDL2

clean:
	del main.exe