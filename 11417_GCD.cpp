#include <iostream>

using namespace std;

int mdc_euclides(int divisor, int dividendo)
{
    while (divisor != 0)
    {
        int resto = dividendo % divisor;
        dividendo = divisor;
        divisor = resto;
    }
    return dividendo;
}

int main()
{
    int N, G;
    do
    {
        G = 0;
        cin >> N;
        for (int i = 1; i < N; i++)
        {
            for (int j = i + 1; j <= N; j++)
            {
                G += mdc_euclides(i, j);
            }
        }
        cout << G << endl;

    } while (N != 0);
    return 0;
}
