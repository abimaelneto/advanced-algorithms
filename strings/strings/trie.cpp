
#include <iostream>
#include <cstdio>

using namespace std;

const int ALPHABET_SIZE = 26;

// trie node
typedef struct trieNode {
	struct trieNode *prox[ALPHABET_SIZE];

	// delimita fim da palavra...
	bool fim;
} TrieNode;

// Returns new trie node (initialized to NULLs)
TrieNode *criaNode(void)
{
	TrieNode *no = new TrieNode;

	no->fim = false;

	for (int i = 0; i < ALPHABET_SIZE; i++)
		no->prox[i] = NULL;

	return no;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(TrieNode *raiz, string chave)
{
	TrieNode *p = raiz;

	for (int i = 0; i < chave.length(); i++)
	{
		int index = chave[i] - 'a';
		if (!p->prox[index])
			p->prox[index] = criaNode();

		p = p->prox[index];
	}

	// mark last node as leaf
	p->fim = true;
}

// Returns true if key presents in trie, else
// false
bool search(TrieNode *raiz, string chave)
{
	TrieNode *p = raiz;

	for (int i = 0; i < chave.length(); i++)
	{
		int index = chave[i] - 'a';
		if (!p->prox[index])
			return false;

		p = p->prox[index];
	}

	return (p->fim);
}


int main()
{
	string s;
	TrieNode *raiz = criaNode();

	while (getline(cin,s)){
		insert(raiz,s);
	}


	// Search for different keys
	search(raiz, "the")? cout << "Yes\n" :
						cout << "No\n";
	search(raiz, "candy")? cout << "Yes\n" :
						cout << "No\n";
	return 0;
}

