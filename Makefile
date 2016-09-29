BIN = solve
SOURCE = main.cpp
IN = futoshiki.dat


all: compile run

compile:
	g++ -o $(BIN) $(SOURCE)

zip:
	

run:
	./solve $(IN)