SRC:=Source

all: project

project: main.o table.o
	g++ main.o table.o -o main

main.o: $(SRC)/main.cpp $(SRC)/table.h
	g++ -c $(SRC)/main.cpp

table.o: $(SRC)/table.cpp $(SRC)/table.h
	g++ -c $(SRC)/table.cpp

clean:
	rm -rf *.o
