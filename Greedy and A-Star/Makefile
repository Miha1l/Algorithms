SRC:=Sources

greedy: main_greedy.o Greedy.o
	g++ main_greedy.o Greedy.o -o greedy

main_greedy.o: $(SRC)/main_greedy.cpp $(SRC)/Greedy.h
	g++ -c $(SRC)/main_greedy.cpp

Greedy.o: $(SRC)/Greedy.cpp $(SRC)/Greedy.h
	g++ -c $(SRC)/Greedy.cpp

a-star: main_a_star.o A-Star.o
	g++ main_a_star.o A-Star.o -o a-star

main_a_star.o: $(SRC)/main_a_star.cpp $(SRC)/A-Star.h
	g++ -c $(SRC)/main_a_star.cpp

A-Star.o: $(SRC)/A-Star.cpp $(SRC)/A-Star.h
	g++ -c $(SRC)/A-Star.cpp

clean:
	rm -rf *.o