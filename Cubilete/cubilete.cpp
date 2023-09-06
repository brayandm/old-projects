#include <bits/stdc++.h>

#define db(x) cout << #x ": " << (x) << '\n';

using namespace std;

vector<vector<int>> cal;

vector<int> v;

int cantdados;

int cantcaras;

int cantopc;

void precal(int cant)
{
    if(!cant)cal.clear();
    if(cant == cantdados)
    {
        cal.push_back(v);
        return;
    }
    for(int i = 0 ; i < cantcaras ; i++)
    {
        v.push_back(i);
        precal(cant+1);
        v.pop_back();
    }
    return;
}

void imprimir()
{
    vector<int> tot(cantdados+1);
    for(int i = 0 ; i < cal.size() ; i++)
    {
        vector<int> vect(cantcaras);
        vector<bool> b(cantdados+1);
        for(int j = 0 ; j < cal[i].size() ; j++)
        {
            vect[cal[i][j]]++;
        }
        for(int j = 0 ; j < cantopc-1 ; j++)
        {
            for(int k = 0 ; k <= vect[j] + vect[cantcaras-1] ; k++)
            {
                b[k] = true;
            }
        }
        for(int j = 0 ; j <= cantdados ; j++)
        {
            if(b[j])tot[j]++;
        }
    }
    for(int i = 1 ; i <= cantdados ; i++)
    {
        cout << setprecision(2) << fixed << (double)(tot[i])/double(pow((double)cantcaras,(double)cantdados))*100.0 << "%" << '\n';
    }
    return;
}

int main()
{
    cantcaras = 6;

    for(cantdados = 5 ; cantdados > 0 ; cantdados--)
    {
        precal(0);
        for(cantopc = cantcaras ; cantopc > 1 ; cantopc--)
        {
            imprimir();
            cout << '\n';
        }
    }

    return 0;
}
