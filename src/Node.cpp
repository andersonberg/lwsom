/*
 * Node.cpp
 *
 *  Created on: 27/05/2013
 *      Author: anderson
 */

#include "Node.h"

Node::Node(vector<double> pesos, vector<int> coords) {
	this->coords = coords;
	this->pesos = pesos;

}

Node::~Node() {
	// TODO Auto-generated destructor stub
}

