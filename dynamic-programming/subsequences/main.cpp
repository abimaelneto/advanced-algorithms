#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <climits>
#include <string.h>
using namespace std;

#define MAX 1010

string str1;
string str2;


// h 112233
// g 112222
// d 112222
// c 111111
// b 111111
// a 111111 
// 	 aedfhr 

int MEMO[MAX][MAX];
int M,N;

void printVet(int v[], int n){
	for (int i = 0; i < n; ++i){
		cout << v[i] << " ";
	}
	cout << endl;
}

void printMemo(){
	for(int i = 0; i < M; ++i){
		for(int j = 0; j < N; ++j){
			cout << MEMO[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

int lisPD2(){

	// para todo caractere de str1
	for (int i = 0; i <=M; ++i) { 

		for (int j = 0; j<=N; j++) { 
			//chars match
			 if (i == 0 || j == 0) {
        MEMO[i][j] = 0;
				continue;
			}

			if (str1[i-1] == str2[j-1]) {
				MEMO[i][j] = 1+MEMO[i-1][j-1];
			}
			else {
				MEMO[i][j] = max(MEMO[i-1][j], MEMO[i][j-1]);
			}

		}

	}

	return MEMO[M][N];
}


int main(int argc, char const *argv[])
{
	string aux;
	while(!feof(stdin)) {
		cin >> str1;
		cin >> str2;
		if(str1 == aux) break;
		M = str1.length();
		N = str2.length();

		memset(MEMO, 0, sizeof(MEMO));
		aux = str1;
		cout << lisPD2() << endl;
	}

	return 0;
}