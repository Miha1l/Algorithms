SRC:=Sources

all: axo joker

axo: main_axo.o Axo.o
	g++ main_axo.o Axo.o -o axo

main_axo.o: $(SRC)/main_axo.cpp $(SRC)/Axo.h
	g++ -c $(SRC)/main_axo.cpp

Axo.o: $(SRC)/Axo.cpp $(SRC)/Axo.h
	g++ -c $(SRC)/Axo.cpp

joker: main_joker.o Joker.o
	g++ main_joker.o Joker.o -o joker

main_joker.o: $(SRC)/main_joker.cpp $(SRC)/Joker.h
	g++ -c $(SRC)/main_joker.cpp

Joker.o: $(SRC)/Joker.cpp $(SRC)/Joker.h
	g++ -c $(SRC)/Joker.cpp

clean:
	rm -rf *.o