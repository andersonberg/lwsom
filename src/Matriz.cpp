/*
 * Matriz.cpp
 *
 *  Created on: 26/05/2013
 *      Author: anderson
 */

#include "Matriz.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

Matriz::Matriz() {
	// TODO Auto-generated constructor stub

}

void Matriz::print_matriz(){
	int i, j;
	for (i = 0; i < 150; i++){
		for (j = 0; j < 150; j++){
			cout << this->matriz[i][j] << "\n";
		}
	}
	cout << "\n";
}

Matriz::~Matriz() {
	// TODO Auto-generated destructor stub
}

