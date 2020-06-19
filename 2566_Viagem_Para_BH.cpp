#include <iostream>
#include <climits>
#include <queue>
#include <vector>
#include <algorithm>
#define INF INT_MAX / 2

using namespace std;

class Aresta
{

public:
    int valor;
    int no;

    Aresta(int a, int b)
    {
        valor = a;
        no = b;
    }
    bool operator>(const Aresta &b) const
    {
        return valor > b.valor;
    }
};

int dijkstra(vector<vector<Aresta>> &grafo, int ini, int fim)
{

    vector<int> dist(grafo.size(), INF);
    dist[ini] = 0;

    priority_queue<Aresta, vector<Aresta>, greater<Aresta>> pq;
    pq.push(Aresta(0, ini));

    while (!pq.empty())
    {
        Aresta x = pq.top();
        pq.pop();

        if (dist[x.no] == x.valor)
        {
            for (int i = 0; i < grafo[x.no].size(); i++)
            {
                Aresta y = grafo[x.no][i];
                if (dist[x.no] + y.valor < dist[y.no])
                {
                    dist[y.no] = dist[x.no] + y.valor;
                    pq.push(Aresta(dist[y.no], y.no));
                }
            }
        }
    }

    return dist[fim];
}

int main()
{
    int n, m, ini, fim, valor, consultas, temp, valor_onibus, valor_aviao;
    int saida, chegada, transporte;

    while (cin >> n >> m)
    {
        vector<vector<Aresta>> grafo_onibus(n);
        vector<vector<Aresta>> grafo_aviao(n);

        for (int i = 0; i < m; i++)
        {
            cin >> saida >> chegada >> transporte >> valor;
            if (transporte == 0)
            {
                Aresta ar(valor, chegada - 1);
                grafo_onibus[saida - 1].push_back(ar);
            }
            else
            {
                Aresta ar(valor, chegada - 1);
                grafo_aviao[saida - 1].push_back(ar);
            }
        }
        valor_onibus = dijkstra(grafo_onibus, 0, n - 1);
        valor_aviao = dijkstra(grafo_aviao, 0, n - 1);
        cout << min(valor_onibus, valor_aviao);
        cout << endl;
    }
}
