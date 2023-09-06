#include <bits/stdc++.h>

#define int long long

using namespace std;

vector<int> convert(string cad)
{
    vector<int> bas = {307,311,313,317,331,337,347,349,353,359};
    vector<int> mod = {7,9,21,33,87,93,97,103,123,181};

    for(int i = 0 ; i < mod.size() ; i++)
    {
        mod[i] += 1000000000;
    }

    vector<int> vect;

    for(int i = 0 ; i < min(bas.size(), mod.size()) ; i++)
    {
        int num = 0;
        for(int j = 0 ; j < cad.size() ; j++)
        {
            num = (num*bas[i] + cad[j]) % mod[i];
        }
        vect.push_back(num);
    }

    return vect;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<char> alpha;

    for(char c = 32 ; c <= 126 ; c++)
    {
        alpha.push_back(c);
    }

    ifstream fin("Dkrip.in");

    vector<string> vect;

    string temp_cad;

    while(getline(fin,temp_cad))
    {
        vect.push_back(temp_cad);
    }

    fin.close();

    bool flag_alpha = true;

    for(int i = 0 ; i < vect.size() ; i++)
    {
        for(int j = 0 ; j < vect[i].size() ; j++)
        {
            bool flag = false;
            for(int k = 0 ; k < alpha.size() ; k++)
            {
                if(vect[i][j] == alpha[k])
                {
                    flag = true;
                }
            }
            if(flag == false)
            {
                flag_alpha = false;
            }
        }
    }

    if(flag_alpha == false)
    {
        cout << "The file contains unknown symbols" << '\n';
        return 0;
    }

    int opc;
    cin >> opc;

    string cad;
    cin >> cad;

    vector<int> num = convert(cad);

    mt19937 rng0(num[0]);
    mt19937 rng1(num[1]);
    mt19937 rng2(num[2]);
    mt19937 rng3(num[3]);
    mt19937 rng4(num[4]);
    mt19937 rng5(num[5]);
    mt19937 rng6(num[6]);
    mt19937 rng7(num[7]);
    mt19937 rng8(num[8]);
    mt19937 rng9(num[9]);

    function<int()> rng = [&]()
    {
        int num = 0;
        num ^= rng0();
        num ^= rng1();
        num ^= rng2();
        num ^= rng3();
        num ^= rng4();
        num ^= rng5();
        num ^= rng6();
        num ^= rng7();
        num ^= rng8();
        num ^= rng9();
        return num;
    };

    if(opc)
    {
        for(int i = 0 ; i < vect.size() ; i++)
        {
            for(int j = 0 ; j < vect[i].size() ; j++)
            {
                for(int k = 0 ; k < alpha.size() ; k++)
                {
                    if(vect[i][j] == alpha[k])
                    {
                        int rd = rng()%alpha.size();
                        vect[i][j] = alpha[(k+rd)%alpha.size()];
                        break;
                    }
                }
            }
        }
    }
    else
    {
        for(int i = 0 ; i < vect.size() ; i++)
        {
            for(int j = 0 ; j < vect[i].size() ; j++)
            {
                for(int k = 0 ; k < alpha.size() ; k++)
                {
                    if(vect[i][j] == alpha[k])
                    {
                        int rd = rng()%alpha.size();
                        vect[i][j] = alpha[(k+alpha.size()-rd)%alpha.size()];
                        break;
                    }
                }
            }
        }
    }

    ofstream fout("Dkrip.out");

    for(int i = 0 ; i < vect.size() ; i++)
    {
        for(int j = 0 ; j < vect[i].size() ; j++)
        {
            fout << vect[i][j];
        }
        fout << '\n';
    }

    fout.close();

    system("rm Dkrip.in");
    system("mv Dkrip.out Dkrip.in");

    return 0;
}
