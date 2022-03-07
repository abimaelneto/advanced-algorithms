#include <iostream>
#include <cstdio>
#include <climits>
#include <cstring>

#define MAX 150
#define MAX2 200

using namespace std;


int V;
int M;
int moedas[MAX];
int MEMO[MAX2]; 


void printVet(int *v, int tam){
	for (int i = 0; i <= tam; ++i)
		printf("%d ", v[i]);
	printf("\n");
}

int solve (int v){
	if (v == 0)   // nao tem mais troco. retorna 0
		return 0;
	if (v < 0)  // nao tem sentido trocar por uma moeda maior. descarta.
		return INT_MAX-1;
	// para todas as moedas, encontre a que retorna a qtd minima para o valor v
	int minimo = INT_MAX;
	for (int i = 0; i < M; ++i)
		minimo = min (minimo, solve(v-moedas[i])+1);
		
	return minimo;
}


int solvePD (int v){
	if (v == 0)   // nao tem mais troco. retorna 0
		return 0;
	if (v < 0)  // nao tem sentido trocar por uma moeda maior. descarta.
		return INT_MAX-1;
	// verifica se já existe o resultado para este valor de v !!!!
	if (MEMO[v] != -1)
		return MEMO[v];

	// para todas as moedas, encontre a que retorna a qtd minima para o valor v
	MEMO[v] = INT_MAX;
	for (int i = 0; i < M; ++i) // ara todas as moedas
		MEMO[v] = min (MEMO[v], solvePD(v-moedas[i])+1); // aplica a memoizacao !!
	
	return MEMO[v];
}

int PD (){
	// PARA todo j de 1 ate V (inclusive!)
	for (int j = 1; j <=V; ++j){
		// para todas as moedas, encontre a que retorna a qtd minima para o valor v
		MEMO[j] = INT_MAX;
		for (int i = 0; i < M; ++i) // para todas as moedas
			if (j>=moedas[i])
				MEMO[j] = min (MEMO[j], MEMO[j-moedas[i]]+1); // aplica a memoizacao !!
	}

	return MEMO[V];
}


int main(int argc, char const *argv[])
{
							
	cin >> V;
	cin >> M; 
	for (int i = 0; i < M; ++i)
		cin >> moedas[i];


	//cout << "A menor quantidade de moedas eh = " << solve(V) << endl;
	memset(MEMO, -1, sizeof MEMO);
	printVet(MEMO, V);
	cout << "A menor quantidade de moedas eh = " << solvePD(V) << endl;
	printVet(MEMO, V);

	MEMO[0] = 0; //nao requer inicializacao do vetor MEMO inteiro. basta v == 0
	cout << "A menor quantidade de moedas eh = " << PD() << endl;
	printVet(MEMO, V);
	


	return 0;
}

