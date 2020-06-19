#include <iostream>
#include <queue>
#include <list>
#include <set>
#define fore(i, n) for (int i = 0; i < n; i++)

using namespace std;

char dfs(int v, vector<list<int>> &grafo, vector<bool> &visitado, vector<char> &final)
{

    visitado[v] = true;
    cout << "Vertice " << v << "foi visitado." << endl;

    for (list<int>::iterator it = grafo[v].begin(); it != grafo[v].end(); it++)
    {
        if (!visitado[*it])
        {
            char temp = dfs(*it, grafo, visitado, final);
            final.push_back(temp);
        }
    }

    for (int i = 0; i < visitado.size(); i++)
    {
        if (!visitado[i])
        {
            final.push_back('*');
            char temp = dfs(i, grafo, visitado, final);
            final.push_back(temp);
        }
    }

    return '*';
}

int main()
{
    // char alfabeto['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'];
    char alfabeto[27];
    alfabeto[0] = 'a';
    alfabeto[1] = 'b';
    alfabeto[2] = 'b';
    alfabeto[3] = 'c';
    alfabeto[4] = 'd';
    alfabeto[5] = 'e';
    alfabeto[6] = 'f';
    alfabeto[7] = 'g';
    alfabeto[8] = 'h';
    alfabeto[9] = 'i';
    alfabeto[10] = 'j';
    alfabeto[11] = 'k';
    alfabeto[12] = 'l';
    alfabeto[13] = 'm';
    alfabeto[14] = 'n';
    alfabeto[15] = 'o';
    alfabeto[16] = 'p';
    alfabeto[17] = 'q';
    alfabeto[18] = 'r';
    alfabeto[19] = 's';
    alfabeto[20] = 't';
    alfabeto[21] = 'u';
    alfabeto[22] = 'v';
    alfabeto[23] = 'w';
    alfabeto[24] = 'x';
    alfabeto[25] = 'y';
    alfabeto[26] = 'z';

    int x, y;
    int v, e, qtd, contador = 0;
    cin >> qtd;

    for (int i = 0; i < qtd; i++)
    {
        cin >> v >> e;
        vector<bool> visitado(v, false);
        vector<list<int>> grafo(v);
        vector<char> final;

        for (int i = 0; i < e; i++)
        {
            cin >> x >> y;
            grafo[x].push_back(alfabeto[y]); /* Aresta x -> y */
            grafo[y].push_back(alfabeto[x]); /* Aresta y -> x */
        }

        char temp = dfs(0, grafo, visitado, final);
        cout << "Case #" << i + 1 << ":" << endl;
        for (int j = 0; j < final.size(); j++)
        {
            contador++;
            cout << final[j] << ",";
            if (final[j] = '*')
            {
                cout << endl;
            }
        }
        cout << contador << " connected components" << endl;
    }

    return 0;
}