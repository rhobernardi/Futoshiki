#/****************************************************************#
#*        Projeto 1 - Algoritmos Avançados e Aplicações          *#
#*             Futoshiki - Backtracking solution                 *#
#*																 *#
#*         Rodrigo das Neves Bernardi    - 8066395               *#
#*                                                               *#
#****************************************************************/#

BIN = futoshiki
SOURCE = main.cpp
IN = futoshiki.dat


all: compile bt

compile: $(SOURCE) $(IN)
	@g++ -o $(BIN) $(SOURCE)

zip:
	@rm -rf *~ *.o
	@rm -rf *.zip
	@zip -r Projeto1.zip $(SOURCE) $(IN) Makefile

bt:
	@./futoshiki 0 0

va:
	@./futoshiki 1 0

mvr:
	@./futoshiki 1 1