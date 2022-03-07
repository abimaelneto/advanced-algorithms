#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

#define V 4
/*
int grafo[V][V] = {{0,1,1,0,0,0},
				   {0,0,0,1,0,0},
				   {0,0,0,1,1,0},
				   {0,0,0,0,0,1},
				   {0,0,0,0,0,1},
				   {0,0,0,0,0,0}};


int grafo[V][V] = {{0,1,0,1,0,0,0,0},
				   {0,0,1,0,0,0,0,0},
				   {0,0,0,0,1,0,0,0},
				   {0,0,0,0,1,1,0,0},
				   {0,0,0,0,0,0,0,1},
				   {0,0,0,0,0,0,1,0},
				   {0,0,0,0,0,0,0,1},
				   {0,0,0,0,0,0,0,0}};
*/
using namespace std;

/*
int grafo[V][V] = {{0,16,13,0,0,0},
				   {0,0,10,12,0,0},
				   {0,4,0,0,14,0},
				   {0,0,9,0,0,20},
				   {0,0,0,7,0,4},
				   {0,0,0,0,0,0}};


int grafo2[V][V] = {
					{0,100,0,100},
					{0,0,100,0},
					{0,0,0,0},
					{0,1,100,0}
					};

*/
int grafo[V][V] = {
					{0,3,2,0},
					{0,0,5,2},
					{0,0,0,3},
					{0,0,0,0}
					};
/*
int grafo[V][V] = {{0,10,0,4,0,0},
				   {0,0,13,0,4,0},
				   {0,0,0,0,0,10},
				   {0,0,4,0,0,0},
				   {0,0,0,0,0,4},
				   {0,0,0,0,0,0}};
*/
int rgrafo[V][V];
int pai[V];

void printMat(int m[V][V], int v){
	for (int i = 0; i < v; ++i) {
		for (int j = 0; j < v; ++j)
			printf("%d\t", m[i][j]);
		printf("\n");
	}
}

bool caminho(int s, int t){  // implementacao direta BFS...!!!!
	queue<int> q;

	q.push(s);
	pai[s] = -1;

	int visitado[V];
	memset(visitado, 0, sizeof visitado);
	visitado[s] = 1;

	while (!q.empty()){
		int u = q.front(); q.pop();
		
		// para todo v adj a u
		for (int v = 0; v < V; ++v){
			// so entra na fila se TIVER RESIDUO e NAO visitado..
			if (rgrafo[u][v]>0 && visitado[v] == 0) {
				q.push(v);
				pai[v] = u;
				visitado[v] = 1;
			}
		}
	}
	// verifica se tem caminho de s para t
	return (visitado[t] == 1);
}


int ff(){  // edmonds-karp !!!!!!
	int u,v;


	// o grafo residual é o inicialmente o grafo original...
	for (int i = 0; i < V; ++i)
		for (int j = 0; j < V; ++j)
			rgrafo[i][j] = grafo[i][j];

	int s = 0;
	int t = V-1;

	int maxFlow = 0;

	while (caminho(s,t)){     // equanto tem augmented path !!!!!
		printMat(rgrafo,V); printf("**********************\n");
		int gargalo = 100000;
		// calcular o gargalo....
		for (int v = t; v!=s; v = pai[v]){
			u = pai[v];
			gargalo = min(gargalo, rgrafo[u][v]);
		}

		// Atualiza o forward e backward edges...
		for (int v = t; v!=s; v = pai[v]){
			u = pai[v];
			rgrafo[u][v] -= gargalo;  // FORWARD EDGE
			//rgrafo[v][u] += gargalo;  // BACKWARD EDGE !!!
		}
		maxFlow += gargalo;
	}

	return maxFlow;

}

void dfs(int rGraph[V][V], int s, bool visited[]) {
    visited[s] = true;
    for (int i = 0; i < V; i++)
       if (rGraph[s][i] && !visited[i]){
       		printf("%d * %d \n", s,i);
           dfs(rGraph, i, visited);
       }
}

void mincut(int rg[V][V], int s, int t){
	bool vis[V];
	memset(vis, false, sizeof vis);
	dfs(rg, s, vis);
	// Print all edges that are from a reachable vertex to
    // non-reachable vertex in the original graph
    for (int i = 0; i < V; i++)
      for (int j = 0; j < V; j++)
         if (vis[i] && !vis[j] && grafo[i][j])
              cout << i << " - " << j << endl;

}


int main(int argc, char const *argv[])
{
	printf("O Fluxo maximo no grafo eh %d\n", ff());

	printMat(rgrafo, V);

	mincut(rgrafo, 0, V-1);
	return 0;
} 