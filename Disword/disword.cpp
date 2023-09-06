#include <bits/stdc++.h>

#define db(x) cout << #x ": " << (x) << '\n';

using namespace std;

const int MOD = 256;

const int MAXN = 500000;

const int MAXC = 300;

int Trie[MAXN][MAXC];

bool marktr[MAXN][MAXC];

int cont_trie;

int tam;

string cad;

string temp;

string characters = "abcdefghijklmnopqrstuvwxyzáéíóúñ";

int cant[MAXC];

int find(string cad)
{
    int cont = 0;
    bool flag = false;
    for(int i = 0 ; i < cad.size() ; i++)
    {
        if(i + 1 == cad.size() && marktr[cont][(cad[i]+MOD)%MOD])flag = true;
        if(Trie[cont][(cad[i]+MOD)%MOD])cont = Trie[cont][(cad[i]+MOD)%MOD];
        else return 0;
    }
    if(!flag)return 1;
    else return 2;
}

void backtraking(int pos)
{
    int opc = find(temp);
    if(!opc)return;
    if(opc == 2 && (!tam || temp.size() == tam))cout << temp << '\n';
    for(int i = 0 ; i < characters.size() ; i++)
    {
        int num = (characters[i]+MOD)%MOD;
        if(cant[num])cant[num]--;
        else continue;
        temp += (char)num;
        backtraking(pos+1);
        temp.erase(--temp.end());
        cant[num]++;
    }
}

int main()
{
//    ios_base::sync_with_stdio(0)
//    cin.tie(0);
//    cout.tie(0);

    ifstream fin("disword.in");

    string word;

    while(fin >> word)
    {
        int cont = 0;
        for(int i = 0 ; i < word.size() ; i++)
        {
            if(!Trie[cont][(word[i]+MOD)%MOD])
            {
                Trie[cont][(word[i]+MOD)%MOD] = ++cont_trie;
            }
            if(i + 1 == word.size())marktr[cont][(word[i]+MOD)%MOD] = true;
            cont = Trie[cont][(word[i]+MOD)%MOD];
        }
    }

    fin.close();

    ifstream letters("letters.in");

    cin >> tam;

    cin >> cad;

    letters.close();

    for(int i = 0 ; i < cad.size() ; i++)
    {
        cant[(cad[i]+MOD)%MOD]++;
    }

    backtraking(0);

    // system("pause > nul");

    return 0;
}
