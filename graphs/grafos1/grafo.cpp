#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <climits>

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
vector<pair<int, ii> > EdgeList(100);




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


void bfs(int u){
	queue<int> q;
	q.push(u);
	vi dist(V,INF); // cria o vetor ara controlar ciclo...
	dist[u] = 0; // idstancia de u para u eh 0....

	while (!q.empty()){
		int ul = q.front(); q.pop();
		printf("%d ** ", ul);
		// para todo v adjacente a u...
		for (int i = 0; i < AdjList[ul].size(); ++i){
			ii par = AdjList[ul][i];
			int v = par.first;
			int peso = par.second;
			// se v for INF... atualiza a dist e poe na fila !!
			if (dist[v] == INF){
				dist[v] = dist[ul]+1;
				q.push(v);
			}
		}
	}
}

void dfs(int u){
	// marca como visitado
	visitado[u] = VISITADO;
	printf("%d *** ", u);
	// para todo v adjacente a u...
	for (int i = 0; i < AdjList[u].size(); ++i){
		ii par = AdjList[u][i];
		int v = par.first;
		int peso = par.second;
		// se v nao visitado... recursao..
		if (visitado[v] == NAOVISITADO)
			dfs(v);
	}
  
}


int main(int argc, char const *argv[])
{
	cin >> A;
	cin >> V;

	int u, v, w;
	for (int i = 0; i < A; ++i){
		cin >> u >> v >> w;
		AdjList[u].push_back(ii(v,w));
		// se o grafo nao eh direcionado, entao..
		AdjList[v].push_back(ii(u,w));
	}

	for (int i = 0; i < V; ++i)
		visitado.push_back(NAOVISITADO);

	printAdjList();

	dfs(0);
	printf("\n");
	bfs(0);

	return 0;
}
