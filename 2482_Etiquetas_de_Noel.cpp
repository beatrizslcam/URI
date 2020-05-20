#include <iostream>
#include <map>
#include <list>

using namespace std;

int main()
{
    int qtd_traducao, qtd_criancas;
    string lingua, saudacao, crianca;
    map<string, string> msg_idiomas;
    list<pair<string, string>> lista;

    cin >> qtd_traducao;
    for (int i = 0; i < qtd_traducao; i++)
    {

        cin >> lingua;
        cin.ignore();
        getline(cin, saudacao);
        msg_idiomas.insert(pair<string, string>(lingua, saudacao));
    }

    cin >> qtd_criancas;
    for (int i = 0; i < qtd_criancas; i++)
    {
        cin.ignore();
        getline(cin, crianca);
        cin >> lingua;

        lista.push_back(make_pair(crianca, lingua));
    }

    for (auto it = lista.begin(); it != lista.end(); it++)
    {
        msg_idiomas.find(it->second);
        cout << it->first << endl;
        cout << msg_idiomas.find(it->second)->second << endl
             << endl;
    }

    return 0;
}