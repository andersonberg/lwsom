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
	float matriz[150][150];
	int i = 0;
	float num;
	int j;

	cout << "Iniciando...\n";

	if(!arquivo.is_open()){
		cout << "Nao foi possivel abrir o arquivo.\n";
		arquivo.clear();
	}

	while(arquivo.getline(matriz_linha, 5000)){
		string linha = matriz_linha;
		istringstream iss(linha);

		char a[1];
		a[0] = '#';
		if (matriz_linha[0] == a[0]){
			cout << "\nIniciando nova matriz...\n";
			i = 0;
		}
		else{
			j = 0;
			do{
				string sub;
				iss >> sub;
				num = atof(sub.c_str());
				matriz[i][j] = num;
//				cout << sub << endl;
//				cout << num << endl;
				j++;
			}while (iss);
		}
		i++;
	}
	arquivo.close();
}

Aplicacao::~Aplicacao() {
	// TODO Auto-generated destructor stub
}
