#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;
  
vector <string> words_vec; // palavras que o usuario fornece
vector <string> templates_vec; //templates das senhas

string ref_template;

vector<string> senha (256);

int nivel;

void printa_senha() {
    for (int i = 0; i < (int) ref_template.size(); i ++) {
        cout << senha[i];
    }
    cout << endl;
}

void backtracking(int nivel) {
    if ( nivel == (int) ref_template.size()){
        printa_senha();
        senha.clear();
    } else {
        if( ref_template.at(nivel) == '0') {
            // itera sobre os digitos
            for( int i = 0; i < 10; i++) {      
                senha[nivel] = ( to_string(i)  );
                backtracking(nivel + 1);
            }
        }
        else if( ref_template.at(nivel) == '#') {
            // itera sobre o array de palavras
            for( string word : words_vec) {
                senha[nivel] = ( word );
                backtracking(nivel + 1);
            }
        }       
    }
}

int main() {
    
    int words_number = 0;

    string blank; // apenas para leitura em branco

    string n_words_buffer; // apenas para ler a linha inteira e verificar se devemos continuar o loop
    getline(cin, n_words_buffer);

    do {

        words_number = stoi(n_words_buffer);

        //para cada palavra, lê e armazena no vetor de palavras para consulta
        string temp_string;
        for ( int word_count = 0 ; word_count < words_number; word_count++) {

            getline(cin,temp_string);
            words_vec.push_back(temp_string);
        }

        // faz o mesmo com os templates
        int n_templates;
        cin >> n_templates;
        getline(cin, blank);

        for ( int template_count = 0 ; template_count < n_templates; template_count++) { 
            getline(cin,temp_string);
            templates_vec.push_back( temp_string );
        }
        cout << "--" << endl;
        //chama recursão principal para cada template
        for ( int tmp = 0; tmp < (int) templates_vec.size(); tmp++ ){
            senha.clear();
            ref_template = templates_vec.at(tmp);
            backtracking(0);
        }
        words_vec.clear();
        templates_vec.clear();

        getline(cin, n_words_buffer);

    } while( !n_words_buffer.empty());


    return 0;
}