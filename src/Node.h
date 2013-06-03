/*
 * Node.h
 *
 *  Created on: 27/05/2013
 *      Author: anderson
 */

#ifndef NODE_H_
#define NODE_H_
#include <vector>

using namespace std;

class Node {
public:
	Node(vector<double> pesos, vector<int> coords);
	virtual ~Node();
	float sqeuclidean(Node* node);
	void atualiza_prototipo(vector<double>dissimilaridades, float temperatura);
	vector<double> pesos;
	vector<int> coords;
	vector<int> prototipos;
	vector<int> elementos;
};

#endif /* NODE_H_ */
