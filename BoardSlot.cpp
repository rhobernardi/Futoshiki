#include "BoardSlot.h"
#include <iostream>

using namespace std;

BoardSlot::BoardSlot(){
	num=0;
}

void BoardSlot::setNumber(int numero){
	num = numero;
}

int BoardSlot::getNumber(){
	return num;
}