#include <iostream>

using namespace std;

int main()
{
    int qtd;
    int alt, current;
    cin >> qtd;
    cin >> current;
    for (int i = 0; i < qtd; i++)
    {
        cin >> alt;
        if (current == alt)
        {
            cout << 0;
            return 0;
        }
        else
        {
            current = alt;
        }
    }
    cout << 1;
    return 0;
}