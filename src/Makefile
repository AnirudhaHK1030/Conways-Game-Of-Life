all:gol

gol: main.o GraphicsClient.o CellularAutomaton.o
	g++ main.o GraphicsClient.o CellularAutomaton.o -o gol

main.o: main.cpp GraphicsClient.h CellularAutomaton.h
	g++ -g -c main.cpp

GraphicsClient.o: GraphicsClient.cpp GraphicsClient.h
	g++ -g -c GraphicsClient.cpp	

CellularAutomaton.o:CellularAutomaton.cpp CellularAutomaton.h
	g++ -g -c CellularAutomaton.cpp

clean: 
	rm -f *.o
