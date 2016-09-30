BIN = solve
SOURCE = main.cpp
IN = futoshiki.dat


all: compile run

compile: $(SOURCE) $(IN)
	g++ -o $(BIN) $(SOURCE)

zip:
	@rm -rf *~ *.o
	@rm -rf *.zip
	@zip -r exercicio5.zip $(SOURCE) $(IN) Makefile

run:
	./solve < $(IN)