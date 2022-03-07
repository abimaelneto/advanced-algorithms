#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

#define MAX 100

int vet[MAX];
int pred[MAX];

int MEMO[MAX];
int N;

void printVet(int v[], int n){
	for (int i = 0; i < n; ++i){
		cout << v[i] << " ";
	}
	cout << endl;
}

int lisREC(int i, int &maxl){
	cout << "lisREC -- i: " << i << endl;
	if (i == 0)
		return 1;

	int maior = 1;


	for (int j = i-1; j>=0; j--){
		printf("começo recursão com i: %d, j: %d\n", i, j);
		int res = lisREC(j, maxl);
		printf("fim recursão com i: %d, j: %d\n", i, j);
		printf("res = %i\n", res);
		if (vet[i]>vet[j])
			maior = max(res+1, maior);
	}
	if (maior > maxl)
		maxl = maior;
	printf("\nresultado i: %d -- %d\n\n", i, maior);
	return maior;
}


int lisRECPD(int i, int &maxlis){
	if (i == 0)
		return 1;

	if (MEMO[i] != -1)
		return MEMO[i];

	int maior = 1;
	for (int j = i-1; j>=0; j--) { // para todo j [i-1 ... 0]
		int res = lisRECPD(j,maxlis);
		if (vet[j] < vet[i])
			maior = max(res+1, maior);
	}

	MEMO[i] = maior;

	if (maxlis < maior)
		maxlis = maior;

	return MEMO[i];
}


int lisPD(){
	int maxlis = 1;
	for (int i = 1; i <=N; ++i) { // para todo elemento i do vetor
		int maior = 1;
		for (int j = i-1; j>=0; j--) { // para todo j [i-1 ... 0]
			//int res = MEMO[j];
			if (vet[j] < vet[i]){
				maior = max(MEMO[j]+1, maior);
			}
		}

		MEMO[i] = maior;

		if (maxlis < maior){
			maxlis = maior;

		}
	}

	return maxlis;
}

int lisPD2(){
	int maxlis;
	MEMO[0] = maxlis = 1;
	for (int i = 1; i <=N; ++i) { // para todo elemento i do vetor
		MEMO[i] = 1; //inicializacao
		for (int j = i-1; j>=0; j--) { // para todo j [i-1 ... 0]
			//int res = MEMO[j];
			if (vet[j] < vet[i] && MEMO[j]+1 > MEMO[i]){
				MEMO[i] = MEMO[j]+1;
				pred[i] = j;
			}
		}

		if (maxlis < MEMO[i]){
			maxlis = MEMO[i];

		}
	}

	return maxlis;
}


int lis(int n){
	int maxl = 1;
	lisREC(n-1, maxl);

	return maxl;
}


int main(int argc, char const *argv[])
{

	
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> vet[i];
	
	pred[0] = -1;

	int maxlis = 1;
	// printf("LIS = %d\n", lisREC(N-1, maxlis));
	// printf("maxlis = %d\n", maxlis);

	// memset(MEMO, -1, sizeof MEMO);
	// printf("LIS (REC PD) = %d\n", lisRECPD(N-1, maxlis));
	// printf("maxlis = %d\n", maxlis);
	// printVet(MEMO, N);
    

	//memset(MEMO, -1, sizeof MEMO);
	MEMO[0] = 1;
	printf("LIS (PD) = %d\n", lisPD());
	printVet(MEMO, N);

	printf("LIS (PD2) = %d\n", lisPD2());
	printVet(MEMO, N);



	printVet(pred, N);


	//printf("LIS = %d\n", lis(n));
	return 0;
}