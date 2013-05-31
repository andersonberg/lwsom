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
	float dist = 0;
	float diff;

	if (this->coords.size() == node->coords.size()){
		for (int i = 0; i < (int)this->coords.size(); i++){
			diff = this->coords[i] - node->coords[i];
			dist += pow(diff, 2);
		}
	}
	return dist;
}

void Node::atualiza_prototipo(vector<double>dissimilaridades, float temperatura){

}

Node::~Node() {
	// TODO Auto-generated destructor stub
}

