#include <bits/stdc++.h>

#define db(x) cout << #x ": " << (x) << '\n';

using namespace std;

string temp;

vector<string> vecttemp;

vector<string> vect;

int main()
{
    ifstream fin("BD.in");
    ifstream ftemp("Dkrip.in");

    while(ftemp >> temp)
    {
        for(int i = 0 ; i < temp.size() ; i++)
        {
            if(temp[i] == '�')temp[i] = 'a';
            else if(temp[i] == '�')temp[i] = 'e';
            else if(temp[i] == '�')temp[i] = 'i';
            else if(temp[i] == '�')temp[i] = 'o';
            else if(temp[i] == '�')temp[i] = 'u';
        }
        vecttemp.push_back(temp);
    }

    ftemp.close();

    while(getline(fin,temp))
    {
        string cad;
        for(int i = 0 ; i < temp.size() ; i++)
        {
            if(temp[i] >= 'A' && temp[i] <= 'Z')temp[i] += 32;
            if((temp[i] >= 'a' && temp[i] <= 'z') || temp[i] == '�' || temp[i] == '�' || temp[i] == '�' || temp[i] == '�' || temp[i] == '�' || temp[i] == '�')
            {
                cad += temp[i];
            }
            else if(cad.size())
            {
                for(int i = 0 ; i < cad.size() ; i++)
                {
                    if(cad[i] == '�')cad[i] = 'a';
                    else if(cad[i] == '�')cad[i] = 'e';
                    else if(cad[i] == '�')cad[i] = 'i';
                    else if(cad[i] == '�')cad[i] = 'o';
                    else if(cad[i] == '�')cad[i] = 'u';
                }
                vecttemp.push_back(cad);
                cad = "";
            }
        }
        if(cad.size())
        {
            vecttemp.push_back(cad);
        }
    }

    fin.close();

    sort(vecttemp.begin(),vecttemp.end());

    for(int i = 0 ; i < vecttemp.size() ; i++)
    {
        if(!vect.size() || vect.back() != vecttemp[i])
        {
            vect.push_back(vecttemp[i]);
        }
    }

    ofstream fout("Dkrip.in");

    for(auto i : vect)fout << i << '\n';

    fout.close();

    return 0;
}
