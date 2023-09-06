#include <bits/stdc++.h>

#define db(x) cout << #x ": " << (x) << '\n';

using namespace std;

const int MAXN = 500000;

const int MAXC = 300;

vector<string> vect;

vector<string> kripto;

vector<char> ch;

vector<bool> mark;

vector<char> kch;

char kst[MAXC];

char mp[MAXC];

string temp;

int Trie[MAXN][MAXC];

bool marktr[MAXN][MAXC];

int cont_trie;

bool is_tot;

bool find(string cad)
{
    is_tot = false;
    int cont = 0;
    for(int i = 0 ; i < cad.size() ; i++)
    {
        if(i + 1 == cad.size() && marktr[cont][(cad[i]+256)%256])is_tot = true;
        if(Trie[cont][(cad[i]+256)%256])cont = Trie[cont][(cad[i]+256)%256];
        else return false;
    }
    return true;
}

bool check()
{
    for(int i = 0 ; i < kripto.size() ; i++)
    {
        string tp;
        for(int j = 0 ; j < kripto[i].size() ; j++)
        {
            if(mp[(kripto[i][j]+256)%256] != '\0')
            {
                tp += mp[(kripto[i][j]+256)%256];
            }
            else break;
        }
        if(!find(tp))return false;
        if(tp.size() != kripto[i].size())break;
        else if(!is_tot)return false;
    }
    return true;
}

void view()
{
    for(int i = 0 ; i < kripto.size() ; i++)
    {
        for(int j = 0 ; j < kripto[i].size() ; j++)
        {
            cout << mp[(kripto[i][j]+256)%256];
        }
        cout << " ";
    }
    cout << '\n' << '\n';
}

void print()
{
    int cont = 1e6;
    while(cont--);
    for(int i = 0 ; i < kripto.size() ; i++)
    {
        for(int j = 0 ; j < kripto[i].size() ; j++)
        {
            if(mp[(kripto[i][j]+256)%256] == '\0')cout << '?';
            else cout << mp[(kripto[i][j]+256)%256];
        }
        cout << " ";
    }
    cout << '\n';
}

void backtraking(int pos)
{
    //print();
    bool flag = check();
    if(flag && pos + 1 == kch.size())
    {
        view();
        return;
    }
    if(!flag || pos+1 == kch.size())return;
    for(int i = 0 ; i < ch.size() ; i++)
    {
        if(mark[i])continue;
        mark[i] = true;
        mp[(kch[pos+1]+256)%256] = ch[i];
        backtraking(pos+1);
        mp[(kch[pos+1]+256)%256] = '\0';
        mark[i] = false;
    }
}

int main()
{
    ifstream BD("Dkrip.in");

    while(BD >> temp)
    {
        vect.push_back(temp);
    }

    BD.close();

    for(int i = 0 ; i < vect.size() ; i++)
    {
        int cont = 0;
        for(int j = 0 ; j < vect[i].size() ; j++)
        {
            if(!Trie[cont][(vect[i][j]+256)%256])
            {
                Trie[cont][(vect[i][j]+256)%256] = ++cont_trie;
            }
            if(j + 1 == vect[i].size())marktr[cont][(vect[i][j]+256)%256] = true;
            cont = Trie[cont][(vect[i][j]+256)%256];
        }
    }

    ifstream fin("krypto.in");

    while(fin >> temp)
    {
        kripto.push_back(temp);
        for(int i = 0 ; i < temp.size() ; i++)
        {
            if(kst[(temp[i]+256)%256] == '\0')
            {
                kst[(temp[i]+256)%256] = ' ';
                kch.push_back((temp[i]+256)%256);
            }
        }
    }

    fin.close();

    for(int i = 'a' ; i <= 'z' ; i++)
    {
        ch.push_back(i);
        mark.push_back(0);
    }

    ch.push_back(('á'+256)%256);
    ch.push_back(('é'+256)%256);
    ch.push_back(('í'+256)%256);
    ch.push_back(('ó'+256)%256);
    ch.push_back(('ú'+256)%256);
    ch.push_back(('ñ'+256)%256);
    mark.push_back(0);
    mark.push_back(0);
    mark.push_back(0);
    mark.push_back(0);
    mark.push_back(0);

    for(int i = 0 ; i < ch.size() ; i++)
    {
        if(mark[i])continue;
        mark[i] = true;
        mp[(kch[0]+256)%256] = ch[i];
        backtraking(0);
        mark[i] = false;
        mp[(kch[0]+256)%256] = '\0';
    }

    cout << "No se encontraron mas coincidencias.";

    system("pause > nul");

    return 0;
}
