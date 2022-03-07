#include <iostream>

using namespace std;

int hamburgers[2];
int m, n;



void findMinimumBeer(int t) {
	int beer = 0;
	int n_hamburgers = 0;
	int* MEMO = (int*) malloc(sizeof(int)*t+1);
	MEMO[0] = 0;
    // PARA todo j de 1 ate V (inclusive!)
	for (int j = 1; j <=t; ++j){
		//para todos os hamburgueres, encontrar o que retorna a qtd máxima para o valor t
		MEMO[j] = -1;
		for (int i = 0; i < 2; ++i) {
			if (j>=hamburgers[i] && MEMO[j-hamburgers[i]] != -1){
				// cout << "j: " << j << " memo: " << MEMO[j] << " " << MEMO[j-hamburgers[i]] << endl;
				MEMO[j] = max (MEMO[j], MEMO[j-hamburgers[i]]+1); // aplica a memoizacao !!
			}
		}
		if(MEMO[j] != -1) {
			n_hamburgers = MEMO[j];
			beer = t-j;
		}

	}
	if(n_hamburgers == 0) beer = t;

	cout << n_hamburgers;
	if( beer > 0) cout << " " << beer;
	cout << endl;
}


int main( ) {

    while(!feof(stdin)){

			cin >> m;
			cin >> n;
			int t = 0;
			cin >> t;

			if(t == 0) break;
						
			hamburgers[0] = m;
			hamburgers[1] = n;
			
			findMinimumBeer(t);
			
		}
    return 0;
}