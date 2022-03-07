#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

#define TAM 260010

using namespace std;

string texto;
string patt;


void kmpPreProcessamento(int *b, string pat){
	int tamp = pat.length();
	int i = 0, j = -1; b[0] = -1;

	while (i < tamp){
		printf("%d\n", j);
		while (j>=0 && pat[i] != pat[j]) { // eh diferente... Reseta j, usando b .
			j = b[j]; 
			//cout << "pat[i] = " << pat[i] << " pat[j] = "<< pat[j] << " j eh diferente = " << j << endl;
		}
			//j = -1;    
		i++; j++;
		b[i] = j;     // observe que b[i] so deixa de ser zero quando o padrao se repetir em pattern!
	}

}

void kmp (int *b, string text, string pat){
	int tamt = texto.length();
	int tamp = patt.length();
	int i = 0, j = 0;
	while (i < tamt){     // tem texto para  consumir.....
		while (j >= 0 &&  text[i] != pat[j]) {
			j = b[j];
			//cout << "opa... j = b[j] " << j << " i = " << i << endl;
		}
		i++; j++;
		if (j == tamp) { // opa... teve matching !!!
			cout << "A sub string foi encontrada na posicao = " << i - j << endl;
			j = b[j];        // prepara j para um provavel matching novo....
		}
	}
}

int main(int argc, char const *argv[])
{
	int b[1001];

	getline(cin, texto);
	getline(cin, patt);

	int tamt = texto.length(); 
	int tamp = patt.length();

	kmpPreProcessamento(b, patt);

	for (int i = 0; i <=tamp; ++i)
		cout << b[i] << " " ;
	cout << endl;

	kmp(b, texto, patt);

	return 0;
}