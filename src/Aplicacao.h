/*
 * Aplicacao.h
 *
 *  Created on: 24/05/2013
 *      Author: anderson
 */

#ifndef APLICACAO_H_
#define APLICACAO_H_

#include "Node.h"

using namespace std;

class Aplicacao {
public:
	Aplicacao();
	void leitor();
	virtual ~Aplicacao();
	vector<vector<vector<double> > > matrizes_d;
	void atualiza_prototipos(Node node);
};

#endif /* APLICACAO_H_ */
