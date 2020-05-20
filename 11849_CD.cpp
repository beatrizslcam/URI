#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int main()
{
    vector<int> Jack;
    stack<int> CDS;
    vector<int> Jill;
    int qtd_Jack, qtd_Jill, contador, cds, zeros;
    zeros = 0;
    cin >> qtd_Jack;
    cin >> qtd_Jill;
    contador = 0;
    do
    {
        cin >> cds;
        CDS.push(cds);
        if (CDS.top() == 0)
        {
            zeros++;
            CDS.pop();
        }

    } while (zeros < 2);

    for (int i = 0; i < qtd_Jill; i++)
    {
        Jill.insert(Jill.begin(), CDS.top());
        CDS.pop();
    }

    for (int i = 0; i < qtd_Jack; i++)
    {
        Jack.insert(Jack.begin(), CDS.top());
        CDS.pop();
    }
    for (int i = 0; i < qtd_Jack; i++)
    {
        for (int j = 0; j < qtd_Jill; j++)
        {
            if (Jack.at(i) == Jill.at(j))
                contador++;
        }
    }
    cout << contador;

    return 0;
}