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
#include "Node.h"

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
//	vector<vector<vector<double> > > matrizes_d;
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
		this->matrizes_d.resize(NUM_MAT);
		for (int x = 0; x < NUM_MAT; ++x){
			this->matrizes_d[x].resize(ROWS);

			for (int y = 0; y < ROWS; ++y){
				this->matrizes_d[x][y].resize(COLS);
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
						this->matrizes_d[matriz][i][j] = num;
//						cout << "matriz[" << matriz << "][" << i << "][" << j << "]: " << this->matrizes_d[matriz][i][j] << endl;
					}
					j++;
				}while (iss);
				i++;
			}
		}
	}
	arquivo.close();
}

void Aplicacao::atualiza_prototipos(Node* node, double temperatura){
	float distancia;
	double exponencial;
	float fator;

	fator = 2*pow(temperatura, 2);
	for(int i = 0; i < (int)this->clusters.size(); i++){
		Node* node_atual = this->clusters[i];
		for(int j = 0; j < (int)node_atual->elementos.size(); j++){
			distancia = node->sqeuclidean(node_atual);
			exponencial = exp(-distancia/fator);
		}
	}
}

Aplicacao::~Aplicacao() {
	// TODO Auto-generated destructor stub
}
