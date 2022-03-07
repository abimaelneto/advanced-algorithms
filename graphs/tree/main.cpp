#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define VISITADO 1
#define NAOVISITADO 0
#define NAOEXISTE 2
#define INF INT_MAX

int smaller = 100;
typedef pair<int,int> ii; // um par de <u, peso>
typedef vector<ii> vii; // vetor de pares....
typedef vector<int> vi;

// Lista de adjacencia é um vetor de vetor de pares !!
vector<vi> AdjList(100);

// LIsta de arestas..
vector<pair<int, int> > EdgeList(100);

int A;
int V; 
int visitado[100];

// void printAdjList(){
// 	for (int i = 0; i < 100; ++i) // para todos os vértices
// 	{
//     if(AdjList[i].empty()) continue;
// 		printf("%d -> ", i);
// 		for (int j = 0; j < AdjList[i].size(); ++j)
// 		{	if (j < AdjList[i].size()-1)
// 				printf("(%d) > ", AdjList[i][j]);
// 			else 	printf("(%d)", AdjList[i][j]);
// 		}
// 		printf("\n");
// 	}
// }

bool dfs(int u, int parent){
	// marca como visitado
	visitado[u] = VISITADO;
	// printf("%d *** parent %d\n", u, parent);
	// para todo v adjacente a u...
	for (long unsigned int i = 0; i < AdjList[u].size(); ++i){
		int v = AdjList[u][i];
    // cout << "u " << u << " v " << v << endl;
		// se v nao visitado... recursao..
		if (visitado[v] == NAOVISITADO){
      if(dfs(v, u)) return true;
    } 

		// If an adjacent is visited and not parent of current
		// vertex, then there is a cycle.
		else if (v != parent)
		return true;
	}
  return false;
}


bool isTree (){
  int i=0;
  while(true) {
    if(visitado[i] == NAOVISITADO) break;
    i++;
  }

  if (dfs(i, -1)) return false;

  // If we find a vertex which is not reachable from 0
	// (not marked by isCyclicUtil(), then we return false
	for (int u = 0; u < 100; u++)
		if (visitado[u] == NAOVISITADO)
		return false;

	return true;
}
int main(int argc, char const *argv[])
{
	int u, v, cont = 1;

  
  while(true) {
    cin >> u >> v;
  	V = 1;

    for(int i = 0; i<100; i++) {
      visitado[i] = NAOEXISTE;
      AdjList[i].clear();

    }
    if(u < 0 && v < 0) break;

    while(true){
      if(u == 0 && v == 0) break;
      AdjList[u].push_back(v);
      AdjList[v].push_back(u);
      visitado[u] = NAOVISITADO;
      visitado[v] = NAOVISITADO;
      // cout << u << " " << v << " " << endl;
      V++;
      cin >> u >> v;
    }

    // cout << "V " << V << endl;


    // printAdjList();
    isTree()? cout << "Case " << cont << " is a tree.\n":
                 cout << "Case " << cont << " is not a tree.\n";    
    // printf("\n");
    cont++;
    // bfs(0);
  }
	return 0;
}
