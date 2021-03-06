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
#include <cstdlib>
#include <ctime>
#include "Node.h"
#include <algorithm>

#define ROWS 150
#define COLS 150
#define NUM_MAT 4

using namespace std;

// função gerador aleatório
int myrandom (int i) { return std::rand()%i;}

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

void Aplicacao::inicializa_clusters(int xTam, int yTam, int pTam){
	int tamanho = xTam*yTam;
	int x;
	int y;
	int i = 0;
	int amostra_tam;
	vector<int> indices;
	vector<double> pesos;

	pesos.resize(pTam);
	for (int x = 0; x < pTam; x++){
		pesos[x] = 1;
	}

	amostra_tam = (int)this->matrizes_d[0][0].size();
	indices = this->generate_random(amostra_tam, tamanho);

	for(x = 0; x < xTam; x++){
		for (y = 0; y < yTam; y++){
			vector<int> coordenadas;
			coordenadas.push_back(x);
			coordenadas.push_back(y);
			Node* newNode = new Node(pesos, coordenadas);
			newNode->prototipos.push_back(indices[i]);
			this->clusters.push_back(newNode);
			i++;
		}
	}
}

void Aplicacao::atualiza_prototipos(Node* node, double temperatura){
	float distancia;
	double exponencial;
	float fator;
	double soma_diss;
	double soma_pesos;
	double soma_i;
	int prototipo;
	Node* node_atual;
	vector<double> criterios;

	fator = 2*pow(temperatura, 2);

	for(int c = 0; c < (int)this->clusters.size(); c++){
		node_atual = this->clusters[c];

		for(int i = 0; i < (int)node_atual->elementos.size(); i++){
			distancia = node->sqeuclidean(node_atual);
			exponencial = exp(-distancia/fator);

			soma_pesos = 0;
			for (int j = 0; j < (int)this->matrizes_d.size(); j++){
				// Obtém o somatório das dissimilaridades entre o protótipo e o elemento atual
				soma_diss = 0;
				for (int p = 0; p < (int)node->prototipos.size(); p++){
					// j-> matriz atual
					// i-> elemento atual
					// p-> protótipo atual
					prototipo = node->prototipos[p];
					soma_diss += this->matrizes_d[j][i][prototipo];
				}// fim do for do somatório de dissimilaridades
				soma_pesos += node->pesos[j] * soma_diss;
			}// fim do for de matrizes
			soma_i += exponencial * soma_pesos;
		}
		criterios.push_back(soma_i);
	}
}

vector<int> Aplicacao::generate_random(int tam, int resize){
	vector<int> rnd_numb;

	std::srand ( unsigned ( std::time(0) ) );
	for(int i = 0; i < tam; i++) rnd_numb.push_back(i);
	std::random_shuffle(rnd_numb.begin(), rnd_numb.end(), myrandom);

	rnd_numb.resize(resize);

//	for(int j = 0; j < (int)rnd_numb.size(); j++){
//		cout << rnd_numb[j] << endl;
//	}

	return rnd_numb;
}

void Aplicacao::atualiza_particao(double temperatura){
	float distancia;
	double exponencial;
	float fator;
	double soma_diss;
	double soma_pesos;
	double soma_clusters;
	float indice;
	int prototipo;
	Node* node_atual;
	Node* node;
	vector<double> elemento_atual;
	vector<double> criterios;

	fator = 2*pow(temperatura, 2);

	for (int i = 0; i < (int)this->matrizes_d[0].size(); i++){
		elemento_atual = this->matrizes_d[0][i];

		for(int h = 0; h < (int)this->clusters.size(); h++){
			node_atual = this->clusters[h];
			soma_clusters = 0;
			for(int l = 0; l < (int)this->clusters.size(); l++){
				node = this->clusters[l];
				distancia = node->sqeuclidean(node_atual);
				exponencial = exp(-distancia/fator);

				soma_pesos = 0;
				for (int j = 0; j < (int)this->matrizes_d.size(); j++){
					// Obtém o somatório das dissimilaridades entre o protótipo e o elemento atual
					soma_diss = 0;
					for (int p = 0; p < (int)node->prototipos.size(); p++){
						// j-> matriz atual
						// i-> elemento atual
						// p-> protótipo atual
						prototipo = node->prototipos[p];
						soma_diss += this->matrizes_d[j][i][prototipo];
					}// fim do for do somatório de dissimilaridades
					soma_pesos += node->pesos[j] * soma_diss;
				}// fim do for de matrizes
				soma_clusters += exponencial * soma_pesos;
			}// fim do for de clusters interno
			criterios.push_back(soma_clusters);
		}
		indice = std::min_element(criterios.begin(), criterios.end()) - criterios.begin();
		this->clusters[indice]->elementos.push_back(i);
		criterios.clear();
	}
}

Aplicacao::~Aplicacao() {
	// TODO Auto-generated destructor stub
}
