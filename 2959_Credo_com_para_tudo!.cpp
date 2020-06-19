
#include <iostream>
#include <queue>
#include <list>
#include <set>

using namespace std;

void busca_largura(int no_inicial, vector<list<int>> &grafo, vector<bool> &visitado)
{
    queue<int> fila;
    fila.push(no_inicial);
    visitado[no_inicial] = true;

    while (fila.size() > 0)
    {
        int no = fila.front();
        fila.pop();

        for (list<int>::iterator it = grafo[no].begin(); it != grafo[no].end(); it++)
        {
            if (!visitado[*it])
            {
                visitado[*it] = true;
                fila.push(*it);
            }
        }
    }
}

int main()
{
    int x, y;
    int no, aresta, qtd, inicio, objetivo;

    //quantidade de vertice e arestas;
    cin >> no >> aresta >> qtd;

    //vetor com os vertices já visitados;
    vector<bool> visitado(no, false);

    //grafo com  n (no) vertices
    vector<list<int>> grafo(no);

    for (int i = 0; i < aresta; i++)
    {
        cin >> x >> y;
        x--;
        y--;
        grafo[x].push_back(y);
        grafo[y].push_back(x);
    }

    for (int i = 0; i < qtd; i++)
    {
        cin >> inicio >> objetivo;
        inicio--;
        objetivo--;

        busca_largura(0, grafo, visitado);

        if (visitado[objetivo] == false || visitado[inicio] == false)
        {
            cout << "Deu ruim" << endl;
        }
        else
        {
            cout << "Lets que lets" << endl;
        }
    }

    return 0;
}