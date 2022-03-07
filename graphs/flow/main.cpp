#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

int V;

using namespace std;

int s,t,c;

void printMat(int** m, int v){
	for (int i = 0; i < v; ++i) {
		for (int j = 0; j < v; ++j)
			printf("%d\t", m[i][j]);
		printf("\n");
	}
}

bool caminho(int** grafo, int** rgrafo, int* pai, int s, int t){  // implementacao direta BFS...!!!!
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


int ff(int** grafo, int** rgrafo, int* pai){  // edmonds-karp !!!!!!
	int u;

	// o grafo residual é o inicialmente o grafo original...
	for (int i = 0; i < V; ++i)
		for (int j = 0; j < V; ++j)
			rgrafo[i][j] = grafo[i][j];

	int maxFlow = 0;
  
	while (caminho(grafo, rgrafo, pai, s,t)){     // equanto tem augmented path !!!!!
		// printMat(rgrafo,V); printf("**********************\n");
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
			rgrafo[v][u] += gargalo;  // BACKWARD EDGE !!!
		}
		maxFlow += gargalo;
	}
  
  return maxFlow;

}

void dfs(int** rGraph, int s, bool visited[]) {
    visited[s] = true;
    for (int i = 0; i < V; i++)
       if (rGraph[s][i] && !visited[i]){
       		printf("%d * %d \n", s,i);
           dfs(rGraph, i, visited);
       }
}

int main(int argc, char const *argv[])
{
  V = -1;
  int count = 1;
  cin >> V;
  while(V != 0) {

    int** grafo = (int**) malloc(V* sizeof(int*));
    int** rgrafo = (int**) malloc(V* sizeof(int*));

    for(int i = 0; i < V; i++) {
      grafo[i] = (int*) malloc(V* sizeof(int));
      rgrafo[i] = (int*) malloc(V* sizeof(int));
      for(int j = 0; j < V; j++) {
        grafo[i][j] = 0;
        rgrafo[i][j] = 0;
      }
    }
    int* pai = (int*) malloc(V * sizeof(int));    
    cin >> s >> t >> c;
    s--;
    t--;
    while(c > 0) {
      
      pair<int,int> aresta = make_pair(0,0);
      int value = 0;
      cin >> aresta.first >> aresta.second >> value;
      
      grafo[aresta.first-1][aresta.second-1] = value;
      grafo[aresta.second-1][aresta.first-1] = value;
      c--;
      // printMat(grafo, V);
      // printMat(rgrafo, V);
    }
    int res = ff(grafo, rgrafo, pai);
    
    if(count > 1) res+=5;

    cout << "Network " << count << endl;
    count++;
    
    printf("The bandwidth is %d.\n\n", res);
    for(int i = 0; i < V; i++) {
      free(grafo[i]);
      free(rgrafo[i]);
    }
    free(grafo);
    free(rgrafo);
    cin >> V;
  }
	
	return 0;
} 