#include <iostream>
#include <queue>
#include <list>
#include <set>
#include <vector>
#define fore(i, n) for (int i = 0; i < n; i++)

using namespace std;

int dfs(int v, vector<list<int>> &grafo, vector<bool> &visitado, int soma)
{

    visitado[v] = true;
    soma = soma + 1;

    for (list<int>::iterator it = grafo[v].begin(); it != grafo[v].end(); it++)
    {
        if (!visitado[*it])
        {
            soma = dfs(*it, grafo, visitado, soma);
            soma = soma + 1;
        }
    }

    return soma;
}

int main()
{

    int x, y;
    int vertice, aresta, quantidade, no_inicial, soma = 0;
    cin >> quantidade;
    for (int i = 0; i < quantidade; i++)
    {
        cin >> no_inicial >> vertice >> aresta;

        vector<bool> visitados(vertice, false);
        vector<list<int>> labirinto(vertice);

        for (int i = 0; i < aresta; i++)
        {
            cin >> x >> y;
            labirinto[x].push_back(y); /* Aresta x -> y */
            labirinto[y].push_back(x); /* Aresta y -> x */
        }

        soma = dfs(no_inicial, labirinto, visitados, soma);

        cout << endl;
        cout << soma - 1 << endl;
    }
}
