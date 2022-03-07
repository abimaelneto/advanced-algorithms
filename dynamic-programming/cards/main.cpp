#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

#define MAX 1010

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


int lisPD2(){
	int maxlis;
	MEMO[0] = maxlis = 1;
	for (int i = 1; i <=N; ++i) { // para todo elemento i do vetor
		MEMO[i] = 1; 
		for (int j = i-1; j>=0; j--) { // para todo j [i-1 ... 0]

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


int main(int argc, char const *argv[])
{

	
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> vet[i];
	
	pred[0] = -1;

	MEMO[0] = 1;

	printf("%d\n", N-lisPD2());

	return 0;
}