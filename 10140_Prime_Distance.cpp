#include <iostream>
#include <math.h>
#include <set>
#include <utility>
#include <stdlib.h>

using namespace std;
bool primos(int n)
{
    if (n == 2)
        return 1;
    for (int i = 2; i <= ceil(sqrt(n)); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int main()
{
    int primeiro, ultimo, subtracao, auxiliar;
    bool primo;
    set<int> primos_intervalo;
    pair<int, int> maior;
    pair<int, int> menor;

    cin >> primeiro;
    cin >> ultimo;

    menor = make_pair(20, 50);
    maior = make_pair(1, 1);

    int tamanho = ultimo - primeiro;

    for (int i = primeiro; i <= ultimo; i++)
    {
        primo = primos(i);
        if (primo)
        {
            primos_intervalo.insert(i);
        }
    }
    for (auto it = primos_intervalo.begin(); it != primos_intervalo.end(); it++)
    {
        auxiliar = *it;
        break;
    }

    for (auto it = primos_intervalo.begin(); it != primos_intervalo.end(); it++)
    {
        if (*it != primeiro)
        {
            subtracao = *it - auxiliar;

            if (subtracao > abs(maior.first - maior.second))
            {
                maior = make_pair(auxiliar, *it);
            }
            if (subtracao < abs(menor.second - menor.first))
            {
                menor = make_pair(auxiliar, *it);
            }
            auxiliar = *it;
        }
    }
    if (maior.first == 1 && maior.second == 1 && (menor.first == 20 && menor.first == 50 || menor.first == menor.second))
    {
        cout << "There are no adjacent primes.";
    }
    else
    {
        cout << menor.first << "," << menor.second << " are closest, " << maior.first << "," << maior.second << " are most distant.";
    }

    return 0;
}
