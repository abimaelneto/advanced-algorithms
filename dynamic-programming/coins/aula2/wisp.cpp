#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>

using namespace std;


int N;
vector<int> V;
vector<int> P;

vector<int>MEMO;
vector<int>MEMO2;


int wispREC(int j){
	if (j == 0)
		return 0;
	return max(V[j]+wispREC(P[j]), wispREC(j-1));
}

int wispRECPD(int j){
	if (j == 0)
		return 0;
	if (MEMO[j] != -1)
		return MEMO[j];

	MEMO[j] = max(V[j]+wispRECPD(P[j]), wispRECPD(j-1));
	return MEMO[j];
}


int wispPD(){
	MEMO2[0] = 0;
	for (int j = 1; j <=N; ++j) {
		MEMO2[j] = max(V[j]+MEMO2[P[j]], MEMO2[j-1]);
	}

	
	return MEMO2[N];
}






int main(int argc, char const *argv[])
{

	cin >> N; // nro de intervalos

	V.assign(N+1,0); // os pesos
	P.assign(N+1,0); // o proximo intervalo valido !

	MEMO.assign(N+1, -1); // memoizacao para wispRECPD
	MEMO2.assign(N+1, -1); // memoizacao para wispRECPD


	for (int i = 0; i <= N; ++i)
	 	cin >> V[i];

	 for (int i = 0; i <= N; ++i)
	 	cin >>P[i];

	 cout << "O peso maximo obtido para estes intervalos eh = " << wispREC(N) << endl;
	 cout << "(REC PD) O peso maximo obtido para estes intervalos eh = " << wispRECPD(N) << endl;


	 cout << "(PD bottom-up) O peso maximo obtido para estes intervalos eh = " << wispPD() << endl;

	 // Como saber quais intervalos pertencem a solução ????
	// simples! Basta verifica se V[j]+wispREC(P[j]) >= wispREC(j-1)

	 cout << "Os intervalos pertencentes a solucao sao = ";
	 int j = N;
	 while (j > 0){
	 	if (V[j]+MEMO2[P[j]] > MEMO2[j-1]){
	 		cout << j << " ";
	 		j = P[j];
	 	}
	 	else j--;
	 }
	 	
	 cout << endl;
	 

	return 0;
}