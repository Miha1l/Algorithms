SRC:=Sources

all: main.o Graph.o
	g++ main.o Graph.o

main.o: $(SRC)/main.cpp $(SRC)/Graph.h
	g++ -c $(SRC)/main.cpp

Graph.o: $(SRC)/Graph.cpp $(SRC)/Graph.h
	g++ -c $(SRC)/Graph.cpp

clean:
	rm *.o