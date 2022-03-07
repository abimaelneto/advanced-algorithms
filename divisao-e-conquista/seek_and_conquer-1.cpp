#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;


long long int merge (int *vet, int inf, int mid, int sup){
 	
	int i = inf;      // indice da lista 'A'
 	int j = mid+1;   // indeice da lista 'B'
 	// precisamos de um vetor aux para ordenar 
 	int k = 0;
 	int aux[sup-inf+1]; // o vetor auxiliar !!!
 	
 	long long int count = 0;

 	// Enquanto tem elementos em AMBAS as listas
 	while(i<=mid && j<=sup){
 		if (vet[i] <= vet[j])  // nao encontrei inversao
 			aux[k++] = vet[i++];
 		else{   // opa... achamos uma inversao !!!
 			  aux[k++] = vet[j++];
 			  count = count + (mid-i +1);  // incrementa count com o tamanho do resto da lista 'A'
 		}
 	}

 	// copia os remanescentes de ambas as listas
 	// lista 'A'
 	while(i<=mid)
 		aux[k++] = vet[i++];

 	// lista 'B'
 	while(j<=sup)
 		aux[k++] = vet[j++];

 	// tem que atualizar o vetor original
 	for (int i = inf, k = 0; i <= sup; i++, k++)
 		vet[i] = aux[k];
 	return count;

}


long long int inv(int *vet, int inf, int sup){
	// se a lista tem tam 1
	if (inf == sup)
		return 0;

	int mid = (inf+sup)/2;

	long long int qtdesq = inv(vet, inf, mid);      //  T(n/2)
	long long int qtddir = inv(vet, mid+1, sup);    // T(n/2)
	long long int qtdmer = merge(vet, inf, mid, sup);


	return qtdesq + qtddir + qtdmer;
}

int main(){
    
    int n = 0;

    while (cin >> n && n > 0) {
         int sequence[n];
        
        for(int i = 0; i < n; i++) {
            cin >> sequence[i];

        }
        cout << inv( sequence, 0, n-1) << endl;

    }
    return 0;
}