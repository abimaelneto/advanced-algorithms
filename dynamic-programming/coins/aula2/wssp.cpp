#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

#define MAX_W 100
#define MAX_I 50

int N;
int W;
vector<int> P;


int MEMO[MAX_I+1][MAX_W+1];

void printMat(int m[][MAX_W+1], int N, int W){
	for (int i = N; i>= 0; i--){
		for (int w = 0; w <=W; w++)
			printf("%d\t", m[i][w]);
		printf("\n");
	}
			

}


int wsspREC(int j, int peso){
	if (j == 0)  // chegamos ao fim.. nada a retirar..
		return 0;

	if (P[j] > peso) // item nao cabe na mochila...
		return wsspREC(j-1, peso);
	else return max(wsspREC(j-1, peso), P[j]+wsspREC(j-1, peso - P[j])) ;

}


int wsspRECPD(int j, int peso){
	if (j == 0)  // chegamos ao fim.. nada a retirar..
		return 0;

	if (MEMO[j][peso]!= -1)
		return MEMO[j][peso];

	if (P[j] > peso) // item nao cabe na mochila...
		MEMO[j][peso] = wsspREC(j-1, peso);
	else MEMO[j][peso] = max(wsspRECPD(j-1, peso), P[j]+wsspRECPD(j-1, peso - P[j])) ;
	return MEMO[j][peso];
}

int wsspPD(){

	for (int j = 1; j<=N ; ++j) // para todos os itens
		for (int p = 0; p <=W; ++p) // para todos os pesos...
			if (P[j] > p) // item nao cabe na mochila...
				MEMO[j][p] = MEMO[j-1][p];
			else MEMO[j][p] = max(MEMO[j-1][p], P[j]+MEMO[j-1][p - P[j]]) ;
	
	return MEMO[N][W];
}



int main(int argc, char const *argv[])
{

	cin >> W; // peso maximo da mochila
	cin >> N; // nro de itens...

	P.assign(N+1,0); // os pesos dos itens...

	

	for (int i = 0; i <= N; ++i)
		cin >>P[i];

	 cout << "O peso na mochia eh = " << wsspREC(N, W) << endl;

	 memset(MEMO, -1, sizeof MEMO);

	 cout << "(REC PD) O peso na mochia eh = " << wsspRECPD(N,W) << endl;

	 // para a versao PD bottom-up, precisamos apenas inicializar com zero o item ZERO para todos os pesos...
	 for (int i = 0; i <=W; ++i)
	 	MEMO[0][i] = 0;

	  cout << "(REC PD) O peso na mochia eh = " << wsspPD() << endl;
	 printMat(MEMO, N,W);
	 

	return 0;
}