/*
 * Aplicacao.cpp
 *
 *  Created on: 24/05/2013
 *      Author: anderson
 */

#include "Aplicacao.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <string>

using namespace std;

Aplicacao::Aplicacao() {

}

void Aplicacao::leitor(){
	ifstream arquivo;
	arquivo.open("iris.data");
	char matriz_linha[5000];
	float matriz[150][5000];
	int i = 0;
	unsigned int j = 0;

	cout << "Iniciando...\n";

	if(!arquivo.is_open()){
		cout << "Nao foi possivel abrir o arquivo.\n";
		arquivo.clear();
	}

	while(arquivo.getline(matriz_linha, 5000)){
		string linha = matriz_linha;
		istringstream iss(linha);

		do{
			string sub;
			iss >> sub;
			cout << sub << endl;
		}while (iss);

		char a[1];
		a[0] = '#';
		if (matriz_linha[0] == a[0]){
			cout << "\nIniciando nova matriz...\n";
			i = 0;
		}
		else{
			cout << "Linha: " << i << endl;

		}
		cout << matriz_linha << "\n";
		i++;
	}
	arquivo.close();
}

Aplicacao::~Aplicacao() {
	// TODO Auto-generated destructor stub
}
