#include <bits/stdc++.h>

#define db(x) cout << #x ": " << (x) << '\n';

using namespace std;

typedef long long ll;

const int oo = 1e9;

const int MOD = 256;

string word;

string letters;

string temp;

int A[MOD];

int T[MOD];

int main()
{
    ios_base::sync_with_stdio(0);

    ifstream fin("letters.in");

    fin.tie(0);

    fin >> word >> letters;

    fin.close();

    for(int i = 0 ; i < letters.size() ; i++)
    {
        A[(letters[i]+MOD)%MOD]++;
    }

    ifstream BD("disword.in");

    BD.tie(0);

    ofstream fout("words.out");

    fout.tie(0);

    while(BD >> temp)
    {
        if(temp.size() != word.size())continue;
        for(int i = 0 ; i < temp.size() ; i++)
        {
            if(temp[i] == 'á')temp[i] = 'a';
            else if(temp[i] == 'é')temp[i] = 'e';
            else if(temp[i] == 'í')temp[i] = 'i';
            else if(temp[i] == 'ó')temp[i] = 'o';
            else if(temp[i] == 'ú')temp[i] = 'u';
        }
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
        fout << temp << '\n';
    }

    fout.close();

    BD.close();

    return 0;
}
