/*
 * Node.cpp
 *
 *  Created on: 27/05/2013
 *      Author: anderson
 */

#include "Node.h"
#include <cmath>

Node::Node(vector<double> pesos, vector<int> coords) {
	this->coords = coords;
	this->pesos = pesos;

}

float Node::sqeuclidean(Node* node){
	float dist;
	float diff;

	if (this->coords.size() == node->coords.size()){
		for (int i = 0; i < this->coords.size(); i++){
			diff = pow(this->coords[i] - node->coords[i], 2);
			dist += diff;
		}
	}
	return dist;
}

void Node::atualiza_prototipo(vector<double>dissimilaridades, float temperatura){

}

Node::~Node() {
	// TODO Auto-generated destructor stub
}

