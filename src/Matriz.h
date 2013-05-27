/*
 * Matriz.h
 *
 *  Created on: 26/05/2013
 *      Author: anderson
 */

#ifndef MATRIZ_H_
#define MATRIZ_H_

class Matriz {
public:
	Matriz();
//	explicit Matriz (unsigned int cols, unsigned int rows);
	virtual ~Matriz();
	double** matriz;
	void print_matriz();
	Matriz clone();

private:
	unsigned int _cols;
	unsigned int _rows;
};

#endif /* MATRIZ_H_ */
