#include <bits/stdc++.h>

#define db(x) cout << #x ": " << (x) << '\n';

using namespace std;

string encriptar(string cad, int init, int key)
{
    for(int i = 0 ; i < cad.size() ; i++)if(cad[i] != ' ')cad[i] = (key*cad[i]+init)%256;
    return cad;
}

bool check(string cad)
{
    for(int i = 0 ; i < cad.size() ; i++)
    {
        bool flag = false;
        if(cad[i] >= 'a' && cad[i] <= 'z')flag = true;
        if(cad[i] >= 'A' && cad[i] <= 'Z')flag = true;
        if(cad[i] >= '0' && cad[i] <= '9')flag = true;
        if(cad[i] == ' ')flag = true;
        if(cad[i] == '.')flag = true;
        if(cad[i] == ',')flag = true;
        if(cad[i] == ';')flag = true;
        if(cad[i] == ':')flag = true;
        if(cad[i] == '-')flag = true;
        if(!flag)return false;
    }
    return true;
}

int main()
{
    ifstream Fin("krypto.in");

    string cad;

    string temp;

    while(getline(Fin,temp))
    {
        cad += temp;
    }

    for(int init = 0 ; init < 256 ; init++)
    {
        for(int key = 1 ; key < 256 ; key+=2)
        {
            temp = encriptar(cad,init,key);
            if(check(temp))
            {
                cout << temp << '\n';

                int inv = 1;
                for(int i = 0 ; i < 255 ; i++)
                {
                    inv = inv * key % 256;
                }

                cout << "Clave encontrada: " << (256 - (init*inv%256))%256 << " " << inv << '\n' << '\n';
            }
        }
    }

    system("pause > nul");

    return 0;
}
