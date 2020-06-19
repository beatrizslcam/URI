#include <iostream>
#include <math.h>
#include <vector>
#include <bitset>

using namespace std;

bool crivo_bitset(int n)
{
    vector<int> primos;
    bitset<100> conjunto;
    conjunto.set(); //setando tudo como 1
    conjunto[0] = 0;
    conjunto[1] = 0;

    for (int i = 2; i <= n; i++)
    {
        if (conjunto[i] = 1)
        { //setando como zero os multiplos do primo encontrado
            for (int j = i * i; j <= n; j += i)
            {
                conjunto[j] = 0;
            }
            //add o primo encontrado no vetor primo.
            primos.push_back(i);
        }
    }
    for (int i = 0; i < primos.size(); i++)
    {
        if (n == primos[i])
        {
            return true;
        }
    }
    return false;
}

int divisores(int n)
{
    int divisor;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            divisor++;
        }
    }
    return divisor;
}

int main()
{
    int n;
    int div;
    bool ehprimo;
    int contador = 0;

    while (cin >> n)
    {
        cin >> n;
        contador = 0;
        for (int i = 2; i <= n; i++)
        {
            div = divisores(n);
            ehprimo = crivo_bitset(div);
            if (ehprimo)
                contador++;
        }
        cout << contador << endl;
    }

    return 0;
}