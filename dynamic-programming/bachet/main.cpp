#include <iostream>
using namespace std;

int n_moves, n_rocks;

enum PLAYERS{
  STAN = 1,
  OLLIE
};

void findWinner(int* moves) {
	
	int* MEMO = (int*) malloc(sizeof(int)*n_rocks+1);
	MEMO[0] = 0;

	for (int j = 1; j <=n_rocks; ++j){

		MEMO[j] = -1;
		for (int i = 0; i < n_moves; ++i) {
			if (j>=moves[i] && MEMO[j-moves[i]] != -1){
				MEMO[j] = max (MEMO[j], MEMO[j-moves[i]]+1); // aplica a memoizacao !!
			}
		}
	 

	}
	if(n_hamburgers == 0) beer = t;

	cout << n_hamburgers;
	if( beer > 0) cout << " " << beer;
	cout << endl;
}


int main( ) {

    while(!feof(stdin)){

			cin >> n_rocks;
			cin >> n_moves;
      int cont = 0;
      int* moves = (int*) malloc(n_moves*sizeof(int*));
      
      while(cont < n_moves) {
        cin >> moves[cont];
      }

			int t = 0;
			cin >> t;

			if(t == 0) break;

			findMinimumBeer(t);
			
		}
    return 0;
}