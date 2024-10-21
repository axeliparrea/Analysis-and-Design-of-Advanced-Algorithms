#include <iostream>
#include <map>
#include <string>

using namespace std;

// Nodo del Trie
struct TrieNode {
    map<char, TrieNode*> hijos;  
    bool finDePalabra;

    TrieNode() : finDePalabra(false) {}
};

// Clase Trie
class Trie {
private:
    TrieNode* raiz;

    void dfs(TrieNode* nodo, string palabra) {
        if (nodo->finDePalabra) {
            cout << palabra << endl;
        }
        for (auto it : nodo->hijos) {
            dfs(it.second, palabra + it.first);
        }
    }

public:
    Trie() {
        raiz = new TrieNode();
    }

    void insertar(const string& palabra) {
        TrieNode* nodo = raiz;
        for (char c : palabra) {
            if (nodo->hijos.find(c) == nodo->hijos.end()) {
                nodo->hijos[c] = new TrieNode();
            }
            nodo = nodo->hijos[c];
        }
        nodo->finDePalabra = true;
    }
    bool buscar(const string& palabra) {
        TrieNode* nodo = raiz;
        for (char c : palabra) {
            if (nodo->hijos.find(c) == nodo->hijos.end()) {
                return false;
            }
            nodo = nodo->hijos[c];
        }
        return nodo->finDePalabra;
    }
    void recorridoDFS() {
        dfs(raiz, "");
    }
};

int main() {
    Trie trie;
    int N, M;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        string palabra;
        cin >> palabra;
        trie.insertar(palabra);
    }
    trie.recorridoDFS();
    cin >> M;

    for (int i = 0; i < M; ++i) {
        string palabra;
        cin >> palabra;
        cout << trie.buscar(palabra) << endl;
    }

    return 0;
}
