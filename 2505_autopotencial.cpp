#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, size1, size2;
    long long int m;
    bool result = true;
    string str_pow, str_numb;
    while (cin >> n)
    {
        if (n == 1)
            cout << "SIM" << endl;
        else
        {

            m = pow(n, n);

            //Convertendo a potenciação em vetor de caracter
            str_pow = to_string(m);
            size1 = str_pow.length();
            char numbers_pow[size1 + 1];
            strcpy(numbers_pow, str_pow.c_str());

            //Convertendo o número em vetor de caracter
            str_numb = to_string(n);
            size2 = str_numb.length();
            char numb[size2 + 1];
            strcpy(numb, str_numb.c_str());

            for (int i = 0; i < size1; i++)
            {
                if (i >= size1 - size2)
                {
                    for (int j = 0; j < size2; j++)
                    {
                        if (numbers_pow[i] != numb[j])
                            result = false;
                    }
                }
            }

            if (result)
                cout << "SIM" << endl;
            else
                cout << "NAO" << endl;
        }

        result = true;
    }
    return 0;
}