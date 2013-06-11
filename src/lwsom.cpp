//============================================================================
// Name        : lwsom.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Aplicacao.h"
using namespace std;

int main(void) {
//	puts("Hello World!!!");

	Aplicacao app;
	app.leitor();
	app.inicializa_clusters(3,3, app.matrizes_d.size());
	app.atualiza_particao(0.3);
	app.atualiza_prototipos(app.clusters[0], 0.3);
//	cout << app.clusters.size() << endl;
//	for (int i = 0; i < (int)app.clusters.size(); i++){
//		app.atualiza_prototipos(app.clusters[i], 8);
//	}
	return EXIT_SUCCESS;
}
