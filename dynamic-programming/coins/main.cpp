#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

#define MAX_W 100
#define MAX_I 50

int N;
int W;
vector<int> coins;


int MEMO[MAX_I+1][MAX_W+1];

void printMat(int m[][MAX_W+1], int N, int W){
	for (int i = N; i>= 0; i--){
		for (int w = 0; w <=W; w++)
			printf("%d ", m[i][w]);
		printf("\n");
	}
			

}


// int wsspREC(int j, int peso){
// 	if (j == 0)  // chegamos ao fim.. nada a retirar..
// 		return 0;

// 	if (P[j] > peso) // item nao cabe na mochila...
// 		return wsspREC(j-1, peso);
// 	else return max(wsspREC(j-1, peso), P[j]+wsspREC(j-1, peso - P[j])) ;

// }


// int wsspRECPD(int j, int peso){
// 	if (j == 0)  // chegamos ao fim.. nada a retirar..
// 		return 0;

// 	if (MEMO[j][peso]!= -1)
// 		return MEMO[j][peso];

// 	if (P[j] > peso) // item nao cabe na mochila...
// 		MEMO[j][peso] = wsspREC(j-1, peso);
// 	else MEMO[j][peso] = max(wsspRECPD(j-1, peso), P[j]+wsspRECPD(j-1, peso - P[j])) ;
// 	return MEMO[j][peso];
// }

int wsspPD(){

	for (int j = 1; j<=N ; ++j) // para todos os itens
		for (int p = 0; p <=W; ++p) // para todos os pesos...
			if (coins[j] > p) // item nao cabe na mochila...
				MEMO[j][p] = MEMO[j-1][p];
			else MEMO[j][p] = max(MEMO[j-1][p], coins[j]+MEMO[j-1][p - coins[j]]) ;
	
  int minimo = W;
  
  for (int p = 0; p <=W; ++p) {
        
    minimo = min(minimo, abs(MEMO[N][p] - (W-MEMO[N][p])));
    
  }
	return minimo;
}



int main(int argc, char const *argv[])
{
  int n_tests;
  cin >> n_tests;


  for(int t = 0; t < n_tests; t++) {
    
    cin >> N; // quantidade de moedas
	  coins.assign(N+1,0); // os pesos dos itens...
    W = 0;
    for (int i = 1; i <= N; ++i) {
      cin >>coins[i];
      W += coins[i];
    
    }
    
    
    // para a versao PD bottom-up, precisamos apenas inicializar com zero o item ZERO para todos os pesos...
    for (int i = 0; i <=W; ++i)
      MEMO[0][i] = 0;
    
    cout << wsspPD() << endl;
    // printMat(MEMO, N, W);
    
    

  }

	return 0;
}