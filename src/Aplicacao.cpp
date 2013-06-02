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
#include <cmath>
#include "Node.h"
#include <algorithm>

#define ROWS 150
#define COLS 150
#define NUM_MAT 4

using namespace std;

Aplicacao::Aplicacao() {
	// Alocando memória para o array tridimensional.
	this->matrizes_d.resize(NUM_MAT);
	for (int x = 0; x < NUM_MAT; ++x){
		this->matrizes_d[x].resize(ROWS);
		for (int y = 0; y < ROWS; ++y){
			this->matrizes_d[x][y].resize(COLS);
		}
	}
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

void Aplicacao::inicializa_clusters(int xTam, int yTam){
	int tamanho = xTam*yTam;

	for(int i = 0; i < tamanho; i++){

	}
}

void Aplicacao::atualiza_prototipos(Node* node, double temperatura){
	float distancia;
	double exponencial;
	float fator;
	Node* node_atual;

	fator = 2*pow(temperatura, 2);

	cout << "clusters size: " << this->clusters.size() << endl;

	for(int i = 0; i < (int)this->clusters.size(); i++){
		node_atual = &this->clusters[i];

		cout << "elementos size: " << node_atual->elementos.size() << endl;

		for(int j = 0; j < (int)node_atual->elementos.size(); j++){
			distancia = node->sqeuclidean(node_atual);
			exponencial = exp(-distancia/fator);
			cout << exponencial << endl;
		}
	}
}

vector<int> Aplicacao::generate_random(int tam){
	vector<int> rnd_numb;

	for(int i = 0; i < tam; i++) rnd_numb.push_back(i);
	std::random_shuffle(rnd_numb.begin(), rnd_numb.end());

	return rnd_numb;
}

Aplicacao::~Aplicacao() {
	// TODO Auto-generated destructor stub
}
