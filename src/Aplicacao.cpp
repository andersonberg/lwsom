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
#include <vector>

#define ROWS 150
#define COLS 150
#define NUM_MAT 4

using namespace std;

Aplicacao::Aplicacao() {

}

void Aplicacao::leitor(){
	ifstream arquivo;
	arquivo.open("iris.data");
	char matriz_linha[5000];
	vector<vector<vector<double> > > matrizes_d;
//	double matrizes_d [NUM_MAT][ROWS][COLS];
	int i = 0, j;
	float num;
	char a[1];
	int matriz = 0;

	a[0] = '#';
	cout << "Iniciando...\n";

	if(!arquivo.is_open()){
		cout << "Nao foi possivel abrir o arquivo.\n";
		arquivo.clear();
	}

	else{
		// Alocando memória para o array tridimensional.
		matrizes_d.resize(NUM_MAT);
		for (int x = 0; x < NUM_MAT; ++x){
			matrizes_d[x].resize(ROWS);

			for (int y = 0; y < ROWS; ++y){
				matrizes_d[x][y].resize(COLS);
			}
		}

		while(arquivo.getline(matriz_linha, 5000)){
			string linha = matriz_linha;
			istringstream iss(linha);

			if (matriz_linha[0] == a[0]){
//				cout << "\nIniciando nova matriz...\n";
				i = 0;
				matriz++;
			}
			else{
				j = 0;
				do{
					string sub;
					iss >> sub;
					if (sub != ""){
						num = atof(sub.c_str());
						matrizes_d[matriz][i][j] = num;
//						cout << "matriz[" << matriz << "][" << i << "][" << j << "]: " << matrizes_d[matriz][i][j] << endl;
					}
					j++;
				}while (iss);
				i++;
			}
		}
	}
	arquivo.close();
}

Aplicacao::~Aplicacao() {
	// TODO Auto-generated destructor stub
}
