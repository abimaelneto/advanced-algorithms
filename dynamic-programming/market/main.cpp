#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

#define MAX_W 100
#define MAX_I 50

int N, M; //number of products and number of people
int W, P;

vector<int> people;
vector<pair<int, int> > products;

int MEMO[MAX_I+1][MAX_W+1];

void printMat(int m[][MAX_W+1], int N, int W){
	for (int i = N; i>= 0; i--){
		for (int w = 0; w <=W; w++)
			printf("%d (%d %d) ", m[i][w], i, w);
		printf("\n");
	}
}

int productPrice(int weight) {
  
  for(int i = 0; i < N; i++) {
    if(weight == products[i].second) return products[i].second;
  }
  
  return 0;
}

int wsspPD(){

	for (int j = 0; j<=N ; ++j) // para todos os itens
		for (int p = 0; p <=P; ++p) { // para todos os pesos...
      if(p==20) {
        int teste = MEMO[j-1][p - products[j].second];
        cout << endl << "aaaaa " << MEMO[j-1][p] << " " << products[j].second << " " << (teste) << endl;
      }
			if (products[j].second > p) // item nao cabe na mochila...
				MEMO[j][p] = MEMO[j-1][p];
			else MEMO[j][p] = max(MEMO[j-1][p], products[j].second+MEMO[j-1][p - products[j].second]) ;
    }
  int maxPrice = 0;
  int peso = P;
  for (int p = 0; p <=P; ++p){
    int productWeight = products[p].second;
    if(peso - productWeight >= 0 ) {
      maxPrice = max(maxPrice, MEMO[N][p]*productPrice(MEMO[N][p]));
      peso -= productWeight;
    }
  }
	return 0;
}



int main(int argc, char const *argv[])
{
  int n_tests;
  cin >> n_tests;
  
  for(int t = 0; t < n_tests; t++) {
    
    cin >> N; // produtos

	  people.assign(N+1,0); // os pesos dos itens...
    W = 0; //total weight
    P = 0; //total price
      
    
    products.assign(2*N, make_pair(0,0));
    for (int i = 1; i <= N; ++i) {    
      pair<int, int> product = make_pair(1, 2);
      cin >> product.first >> product.second;
      products.push_back(product);
    }

    cin >> M; //n_people
    int total = 0;
    for (int i = 1; i <= M; ++i) {
      cin >>people[i];
      P = people[i];
    
      for (int i = 0; i <=P; ++i)
        MEMO[0][i] = 0;

      printMat(MEMO, N, P);
      total += wsspPD() ;
      
      cout << endl << endl;
      cout << endl << endl;
      printMat(MEMO, N, P);
      break;
    }
    break;
    
    cout <<  endl << total << endl;

  }

	return 0;
}