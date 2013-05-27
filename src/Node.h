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
	vector<double> pesos;
	vector<int> coords;
};

#endif /* NODE_H_ */
