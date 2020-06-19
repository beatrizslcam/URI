#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define INF INT_MAX / 2

using namespace std;

void floyd(vector<vector<double>> &grafo)
{

    int n = grafo.size();

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                grafo[i][j] = min(grafo[i][j], grafo[i][k] + grafo[k][j]);
            }
        }
    }
}

int main()
{

    int node, aresta, qtd, x, y, consultas, inicio, tempo, contador = 0;
    double peso;

    cin >> qtd;
    cout << endl;
    for (int i = 0; i < qtd; i++)
    {
        cin >> node;

        cin >> inicio;
        cin >> tempo;
        cin >> aresta;
        cout << endl;

        vector<vector<double>> grafo(node, vector<double>(node, INF));

        for (int i = 0; i < node; i++)
        {
            grafo[i][i] = 0;
        }

        for (int i = 0; i < aresta; i++)
        {
            cin >> x >> y >> peso;
            grafo[x - 1][y - 1] = peso;
            grafo[y - 1][x - 1] = peso;
        }

        floyd(grafo);

        for (int i = 0; i < grafo.size(); i++)
        {
            if (grafo[inicio - 1][i] <= tempo)
            {
                contador++;
            }
        }
        cout << contador;
    }
    return 0;
}