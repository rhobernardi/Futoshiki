CC=g++
CFLAGS=-c

all: ./game

game: FutoshikiSolver.o FutoshikiBoard.o BoardSlot.o main.cpp
	@$(CC) -o game FutoshikiSolver.o FutoshikiBoard.o BoardSlot.o main.cpp

FutoshikiSolver.o: FutoshikiSolver.h FutoshikiSolver.cpp
	@$(CC) FutoshikiSolver.h FutoshikiSolver.cpp $(CFLAGS)

FutoshikiBoard.o: FutoshikiBoard.h FutoshikiBoard.cpp
	@$(CC) FutoshikiBoard.h FutoshikiBoard.cpp $(CFLAGS)

BoardSlot.o: BoardSlot.h BoardSlot.cpp
	@$(CC) BoardSlot.h BoardSlot.cpp $(CFLAGS)

clean:
	@rm -rf *.o *gch game

zip: clean
	@zip Projeto1.zip *.h *.cpp Makefile README.txt futoshiki.dat Projeto1.pdf

run:
	@./game 1 < futoshiki.dat
