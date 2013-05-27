/*
 * Matriz.cpp
 *
 *  Created on: 26/05/2013
 *      Author: anderson
 */

#include "Matriz.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

Matriz::Matriz() :
	_cols (1),
	_rows (1) {

	this->matriz = new double*;
}

//Matriz::Matriz(unsigned int cols, unsigned int rows) :
//	_cols (cols),
//	_rows (rows) {
//
//	this->matriz = new double*;
//
//}

void Matriz::print_matriz(){
	int i, j;
	for (i = 0; i < 150; i++){
		for (j = 0; j < 150; j++){
			cout << this->matriz[i][j] << " ";
		}

		cout << endl;

	}
	cout << endl;
}

Matriz::~Matriz() {

	delete this->matriz;
	this->matriz = NULL;

}

Matriz Matriz::clone() {
//	Matriz * m = new Matriz (this->_cols, this->_rows);
	Matriz *m = new Matriz();
	unsigned int i,j;

	for (i = 0; i < this->_cols; i++)
		for (j = 0; j < this->_rows; j++)
			m->matriz[i][j] = this->matriz[i][j];

	return *m;
}
