SRC:=Sources
TST:=Tests
BLD:=Build

$(shell  mkdir -p $(BLD))

all: kmp cycle

kmp: main_kmp.o KMP.o
	g++ $(BLD)/main_kmp.o $(BLD)/KMP.o -o $(BLD)/kmp

tests: test_kmp test_cycle

test_kmp: KMP.o
	g++ $(TST)/kmp_test.cpp $(BLD)/KMP.o -o $(BLD)/test_kmp

test_cycle: CycleShift.o
	g++ $(TST)/cycle_test.cpp $(BLD)/CycleShift.o -o $(BLD)/test_cycle

main_kmp.o: $(SRC)/main_kmp.cpp $(SRC)/KMP.h
	g++ -c $(SRC)/main_kmp.cpp -o $(BLD)/main_kmp.o

KMP.o: $(SRC)/KMP.cpp $(SRC)/KMP.h
	g++ -c $(SRC)/KMP.cpp -o $(BLD)/KMP.o

cycle: main_cycle.o CycleShift.o
	g++ $(BLD)/main_cycle.o $(BLD)/CycleShift.o -o $(BLD)/cycle

main_cycle.o: $(SRC)/main_cycle.cpp $(SRC)/CycleShift.h
	g++ -c $(SRC)/main_cycle.cpp -o $(BLD)/main_cycle.o

CycleShift.o: $(SRC)/CycleShift.cpp $(SRC)/CycleShift.h
	g++ -c $(SRC)/CycleShift.cpp -o $(BLD)/CycleShift.o

clean:
	rm -rf $(BLD)