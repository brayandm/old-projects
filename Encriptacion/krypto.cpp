#include <bits/stdc++.h>

using namespace std;

string encriptar(string cad, int init, int key)
{
    for(int i = 0 ; i < cad.size() ; i++)if(cad[i] != ' ')cad[i] = (key*cad[i]+init)%256;
    return cad;
}

string desencriptar(string cad, int init, int key)
{
    int mult = 1;
    for(int i = 0 ; i < 127 ; i++)mult = mult*key%256;
    for(int i = 0 ; i < cad.size() ; i++)if(cad[i] != ' ')cad[i] = (cad[i]-init+256)*mult%256;
    return cad;
}

int convert(string cad)
{
    int num = 0;
    for(int i = 0 ; i < cad.size() ; i++)
    {
        num = num*10+cad[i]-'0';
    }
    return num;
}

string cad;

int main(int args, char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ifstream Fin("krypto.in");
    ofstream Fout("krypto.out");

    string opc = argv[1];

    string init = argv[2];

    string key = argv[3];

    while(getline(Fin,cad))
    {
        if(convert(opc))cad = encriptar(cad,convert(init),convert(key));
        else cad = desencriptar(cad,convert(init),convert(key));
        Fout << cad << '\n';
    }

    Fin.close();
    Fout.close();

    system("erase krypto.in");
    system("rename krypto.out krypto.in");

    return 0;
}
