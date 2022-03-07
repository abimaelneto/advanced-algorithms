#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

#include "UnionFind.h"

using namespace std;

#define VISITADO 1
#define NAOVISITADO 0
#define INF INT_MAX


typedef pair<int,int> ii; // um par de <u, peso>
typedef vector<ii> vii; // vetor de pares....
typedef vector<int> vi;

// Lista de adjacencia é um vetor de vetor de pares !!
vector<vii> AdjList(100);

// LIsta de arestas..
vector< pair<int, ii> > EdgeList;


int A;
int V; 
vi visitado;

void printAdjList(){
	for (int i = 0; i < V; ++i) // para todos os vértices
	{
		printf("%d -> ", i);
		for (int j = 0; j < AdjList[i].size(); ++j)
		{	if (j < AdjList[i].size()-1)
				printf("(%d,%d) > ", AdjList[i][j].first, AdjList[i][j].second);
			else 	printf("(%d,%d)", AdjList[i][j].first, AdjList[i][j].second);
		}
		printf("\n");
	}
}


void kruskal(){
	// ordena as arestas...
	sort(EdgeList.begin(), EdgeList.end());

	UnionFind uf(V); //  cria objeto 

	int custoMin = 0;
	// consome as arestas todas...
	for (int i = 0; i < EdgeList.size(); ++i){
		pair<int, ii> par = EdgeList[i];
		int w = par.first;
		int u = par.second.first;
		int v = par.second.second;

		// se u e v nao pertencem a mesma floresta.. acumula o valor e une as florestas
		if (!uf.isSameSet(u,v)) {
			custoMin = custoMin+w;
			uf.unionSet(u,v);
		}
	}

	printf("A MST tem custo = %d\n", custoMin);
}



int main(int argc, char const *argv[])
{
	cin >> A;
	cin >> V;

	int u, v, w;
	for (int i = 0; i < A; ++i){
		cin >> u >> v >> w;
		EdgeList.push_back(make_pair(w, ii(u,v)));
	}

	
	kruskal();

	return 0;
}
