#include <bits/stdc++.h>

#define db(x) cout << #x ": " << (x) << '\n';

using namespace std;

typedef long long ll;

const int oo = 1e9;

const int MOD = 256;

const int tamc = 60;

string word;

string letters;

string temp;

int A[MOD];

int T[MOD];

int main()
{
    int opm = 0;

    while(clock() < 100)
    {
        opm++;
    }

    while(1)
    {
        cin >> word;
        if(word == "1")return 0;
        cin >> letters;

        // system("cls");

        for(int i = 0 ; i < MOD ; i++)A[i] = 0;

        for(int i = 0 ; i < letters.size() ; i++)
        {
            A[(letters[i]+MOD)%MOD]++;
        }

        ifstream BD("disword.in");

        int tam = 0;

        while(BD >> temp)
        {
            if(temp.size() != word.size())continue;
            bool flag = false;
            for(int i = 0 ; i < word.size() ; i++)
            {
                if(word[i] != '?' && word[i] != temp[i])flag = true;
            }
            if(flag)continue;
            for(int i = 0 ; i < letters.size() ; i++)
            {
                T[(letters[i]+MOD)%MOD] = A[(letters[i]+MOD)%MOD];
            }
            bool ban = false;
            for(int i = 0 ; i < temp.size() ; i++)
            {
                if(T[(temp[i]+MOD)%MOD])T[(temp[i]+MOD)%MOD]--;
                else ban = true;
            }
            if(ban)continue;
            tam += temp.size()+1;
            if(tam > tamc)tam = temp.size()+1, cout << '\n';
            cout << temp << " ";
            int cont = opm*50;
            while(cont--);
        }

        BD.close();

        // system("pause > nul");

        // system("cls");
    }

    return 0;
}
