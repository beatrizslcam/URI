#include <iostream>
#include <list>
#include <map>

using namespace std;

int main()
{
    int qtd_perguntas, repeticao, auxiliar, auxiliar2, contador, aux;
    list<int> numeros;
    map<int, int> mapa;

    cin >> qtd_perguntas;
    cin >> repeticao;

    do
    {

        for (int i = 0; i < qtd_perguntas; i++)
        {
            cin >> auxiliar;
            numeros.push_back(auxiliar);

            mapa.insert(pair<int, int>(auxiliar, 1));
        }

        auxiliar2 = numeros.front();
        numeros.sort();

        for (auto it = numeros.begin(); it != numeros.end(); it++)
        {
            if (it != numeros.begin())
            {

                if (*it == auxiliar2)
                {

                    aux = mapa.find(*it)->second;
                    mapa.find(auxiliar2)->second = aux + 1;
                }
                auxiliar2 = *it;
            }
        }

        for (auto it = mapa.begin(); it != mapa.end(); ++it)
        {
            aux = it->second;
            if (repeticao <= aux)
            {
                contador++;
            }
        }

        cout << contador;
        contador = 0;
        mapa.clear();
        cin >> qtd_perguntas;
        cin >> repeticao;
    } while (qtd_perguntas != 0 && repeticao != 0);

    return 0;
}