#include <bits/stdc++.h>

using namespace std;

#define PB push_back

typedef unsigned long long ull;

unordered_map< char,vector<string> > A;

string cad;

ull ops;

vector<string> convert(string);

void word(vector<string>);

void CantOper1Seg();

void init();

void heart();

int main()
{
    freopen("data\\text.in","r",stdin);

    init();

    CantOper1Seg();

    ull cont = ops;

    while(cont--);

    system("color 4c");

    getline(cin,cad);

    string a;

    for(int i = 0 ; i < cad.size() ; i++)
    {
        if(cad[i] == '-' && a.size())
        {
            word(convert(a));
            heart();
            a = "";
        }
        else if(cad[i] == '-')
        {
            heart();
        }
        else a += cad[i];

        if(i == cad.size() - 1 && a.size())word(convert(a));
    }

    system("cls");

    return 0;
}

vector<string> convert(string s)
{
    vector<string> V(7);

    for(int i = 0 ; i < 7 ; i++)
    {
        for(int j = 0 ; j < 80 ; j++)
        {
            V[i] += " ";
        }
    }

    for(int i = 0 ; i < s.size() ; i++)
    {
        for(int j = 0 ; j < 7 ; j++)
        {
            if(!A[s[i]].empty())V[j] += A[s[i]][j];
            if(i == s.size()-1)V[j] += "\n";
        }
    }

    return V;
}

void word(vector<string> V)
{
    while(V[0].size())
    {
        ull cont = ops / 20;

        system("cls");

        cout << '\n' << '\n' << '\n';
        cout << V[0].substr(0,80);
        cout << V[1].substr(0,80);
        cout << V[2].substr(0,80);
        cout << V[3].substr(0,80);
        cout << V[4].substr(0,80);
        cout << V[5].substr(0,80);
        cout << V[6].substr(0,80);

        while(cont--);

        V[0].erase(0,1);
        V[1].erase(0,1);
        V[2].erase(0,1);
        V[3].erase(0,1);
        V[4].erase(0,1);
        V[5].erase(0,1);
        V[6].erase(0,1);
    }

    return;
}

void CantOper1Seg()
{
    clock_t a = clock();

    for(int i = 1 ; i >= 1 && i == i && true ; i += 5 * 1 / 1 - 4)
    {
        if((clock() - a) >= CLOCKS_PER_SEC)
        {
            ops = i;
            return;
        }
        int h = 193;
        int b = 19 * h - h / 23;
        int c = b % ((int)1e5);
        int sum = h + b + c;
        h = sum = sum;
    }
}

void init()
{
    A[' '].PB("      ");
    A[' '].PB("      ");
    A[' '].PB("      ");
    A[' '].PB("      ");
    A[' '].PB("      ");
    A[' '].PB("      ");
    A[' '].PB("      ");

    A[','].PB("      ");
    A[','].PB("      ");
    A[','].PB("      ");
    A[','].PB("      ");
    A[','].PB("      ");
    A[','].PB(" ##   ");
    A[','].PB("##    ");

    A['.'].PB("      ");
    A['.'].PB("      ");
    A['.'].PB("      ");
    A['.'].PB("      ");
    A['.'].PB("      ");
    A['.'].PB("###   ");
    A['.'].PB("###   ");

    A['A'].PB("  ####     ");
    A['A'].PB(" ##  ##    ");
    A['A'].PB("##    ##   ");
    A['A'].PB("##    ##   ");
    A['A'].PB("########   ");
    A['A'].PB("##    ##   ");
    A['A'].PB("##    ##   ");

    A['B'].PB("#######    ");
    A['B'].PB("##    ##   ");
    A['B'].PB("##   ##    ");
    A['B'].PB("######     ");
    A['B'].PB("##   ##    ");
    A['B'].PB("##    ##   ");
    A['B'].PB("#######    ");

    A['C'].PB("  ######   ");
    A['C'].PB(" ##        ");
    A['C'].PB("##         ");
    A['C'].PB("##         ");
    A['C'].PB("##         ");
    A['C'].PB(" ##        ");
    A['C'].PB("  ######   ");

    A['D'].PB("######     ");
    A['D'].PB("##   ##    ");
    A['D'].PB("##    ##   ");
    A['D'].PB("##    ##   ");
    A['D'].PB("##    ##   ");
    A['D'].PB("##   ##    ");
    A['D'].PB("######     ");

    A['E'].PB("########   ");
    A['E'].PB("##         ");
    A['E'].PB("##         ");
    A['E'].PB("######     ");
    A['E'].PB("##         ");
    A['E'].PB("##         ");
    A['E'].PB("########   ");

    A['F'].PB("########   ");
    A['F'].PB("##         ");
    A['F'].PB("##         ");
    A['F'].PB("######     ");
    A['F'].PB("##         ");
    A['F'].PB("##         ");
    A['F'].PB("##         ");

    A['G'].PB(" ######    ");
    A['G'].PB("##    ##   ");
    A['G'].PB("##         ");
    A['G'].PB("##         ");
    A['G'].PB("##  ####   ");
    A['G'].PB("##    ##   ");
    A['G'].PB(" ######    ");

    A['H'].PB("##    ##   ");
    A['H'].PB("##    ##   ");
    A['H'].PB("##    ##   ");
    A['H'].PB("########   ");
    A['H'].PB("##    ##   ");
    A['H'].PB("##    ##   ");
    A['H'].PB("##    ##   ");

    A['I'].PB("########   ");
    A['I'].PB("   ##      ");
    A['I'].PB("   ##      ");
    A['I'].PB("   ##      ");
    A['I'].PB("   ##      ");
    A['I'].PB("   ##      ");
    A['I'].PB("########   ");

    A['J'].PB("  ######   ");
    A['J'].PB("    ##     ");
    A['J'].PB("    ##     ");
    A['J'].PB("    ##     ");
    A['J'].PB("##  ##     ");
    A['J'].PB("##  ##     ");
    A['J'].PB(" #####     ");

    A['K'].PB("##    ##   ");
    A['K'].PB("##   ##    ");
    A['K'].PB("##  ##     ");
    A['K'].PB("#####      ");
    A['K'].PB("##  ##     ");
    A['K'].PB("##   ##    ");
    A['K'].PB("##    ##   ");

    A['L'].PB("##         ");
    A['L'].PB("##         ");
    A['L'].PB("##         ");
    A['L'].PB("##         ");
    A['L'].PB("##         ");
    A['L'].PB("##         ");
    A['L'].PB("########   ");

    A['M'].PB("##    ##   ");
    A['M'].PB("###  ###   ");
    A['M'].PB("########   ");
    A['M'].PB("## ## ##   ");
    A['M'].PB("##    ##   ");
    A['M'].PB("##    ##   ");
    A['M'].PB("##    ##   ");

    A['N'].PB("##    ##   ");
    A['N'].PB("###   ##   ");
    A['N'].PB("####  ##   ");
    A['N'].PB("## ## ##   ");
    A['N'].PB("##  ####   ");
    A['N'].PB("##   ###   ");
    A['N'].PB("##    ##   ");

    A['O'].PB(" ######    ");
    A['O'].PB("##    ##   ");
    A['O'].PB("##    ##   ");
    A['O'].PB("##    ##   ");
    A['O'].PB("##    ##   ");
    A['O'].PB("##    ##   ");
    A['O'].PB(" ######    ");

    A['P'].PB("#######    ");
    A['P'].PB("##    ##   ");
    A['P'].PB("##    ##   ");
    A['P'].PB("#######    ");
    A['P'].PB("##         ");
    A['P'].PB("##         ");
    A['P'].PB("##         ");

    A['Q'].PB(" ######    ");
    A['Q'].PB("##    ##   ");
    A['Q'].PB("##    ##   ");
    A['Q'].PB("##    ##   ");
    A['Q'].PB("##   ###   ");
    A['Q'].PB("##    ###  ");
    A['Q'].PB(" ######    ");

    A['R'].PB("#######    ");
    A['R'].PB("##    ##   ");
    A['R'].PB("##   ##    ");
    A['R'].PB("######     ");
    A['R'].PB("##  ##     ");
    A['R'].PB("##   ##    ");
    A['R'].PB("##    ##   ");

    A['S'].PB(" #######   ");
    A['S'].PB("##         ");
    A['S'].PB("##         ");
    A['S'].PB(" ######    ");
    A['S'].PB("      ##   ");
    A['S'].PB("      ##   ");
    A['S'].PB("#######    ");

    A['T'].PB("########   ");
    A['T'].PB("   ##      ");
    A['T'].PB("   ##      ");
    A['T'].PB("   ##      ");
    A['T'].PB("   ##      ");
    A['T'].PB("   ##      ");
    A['T'].PB("   ##      ");

    A['U'].PB("##    ##   ");
    A['U'].PB("##    ##   ");
    A['U'].PB("##    ##   ");
    A['U'].PB("##    ##   ");
    A['U'].PB("##    ##   ");
    A['U'].PB("##    ##   ");
    A['U'].PB(" ######    ");

    A['V'].PB("##    ##   ");
    A['V'].PB("##    ##   ");
    A['V'].PB("##    ##   ");
    A['V'].PB("##    ##   ");
    A['V'].PB("##    ##   ");
    A['V'].PB(" ##  ##    ");
    A['V'].PB("  ####     ");

    A['W'].PB("##    ##   ");
    A['W'].PB("##    ##   ");
    A['W'].PB("##    ##   ");
    A['W'].PB("## ## ##   ");
    A['W'].PB("########   ");
    A['W'].PB("###  ###   ");
    A['W'].PB("##    ##   ");

    A['X'].PB("##    ##   ");
    A['X'].PB(" ##  ##    ");
    A['X'].PB("  ####     ");
    A['X'].PB("   ##      ");
    A['X'].PB("  ####     ");
    A['X'].PB(" ##  ##    ");
    A['X'].PB("##    ##   ");

    A['Y'].PB("##    ##   ");
    A['Y'].PB(" ##  ##    ");
    A['Y'].PB("  ####     ");
    A['Y'].PB("   ##      ");
    A['Y'].PB("   ##      ");
    A['Y'].PB("   ##      ");
    A['Y'].PB("   ##      ");

    A['Z'].PB("########   ");
    A['Z'].PB("     ##    ");
    A['Z'].PB("    ##     ");
    A['Z'].PB("   ##      ");
    A['Z'].PB("  ##       ");
    A['Z'].PB(" ##        ");
    A['Z'].PB("########   ");

    /*
    A[''].PB("");
    A[''].PB("");
    A[''].PB("");
    A[''].PB("");
    A[''].PB("");
    A[''].PB("");
    A[''].PB("");
    */

    return;
}

void heart()
{
    ull cont;

    ull contg = ops * 2;

    system("cls");

    cout<<'\n'<<'\n'<<'\n'<<'\n';
    cout<<"                                         \n";
    cout<<"                                         \n";
    cout<<"                                         \n";
    cout<<"                                         \n";
    cout<<"                                         \n";
    cout<<"                                         \n";
    cout<<"                                         \n";
    cout<<"                                       ##\n";
    cout<<"                                         \n";
    cout<<"                                         \n";
    cout<<"                                         \n";
    cout<<"                                         \n";
    cout<<"                                         \n";
    cout<<"                                         \n";
    cout<<"                                         \n";

    cont = contg;

    while(cont--);

    system("cls");

    cout<<'\n'<<'\n'<<'\n'<<'\n';
    cout<<"                                          \n";
    cout<<"                                          \n";
    cout<<"                                          \n";
    cout<<"                                          \n";
    cout<<"                                          \n";
    cout<<"                                          \n";
    cout<<"                                       ## \n";
    cout<<"                                      ####\n";
    cout<<"                                       ## \n";
    cout<<"                                          \n";
    cout<<"                                          \n";
    cout<<"                                          \n";
    cout<<"                                          \n";
    cout<<"                                          \n";
    cout<<"                                          \n";

    cont = contg;

    while(cont--);

    system("cls");

    cout<<'\n'<<'\n'<<'\n'<<'\n';
    cout<<"                                          \n";
    cout<<"                                          \n";
    cout<<"                                          \n";
    cout<<"                                          \n";
    cout<<"                                          \n";
    cout<<"                                          \n";
    cout<<"                                      ####\n";
    cout<<"                                      ####\n";
    cout<<"                                      ####\n";
    cout<<"                                          \n";
    cout<<"                                          \n";
    cout<<"                                          \n";
    cout<<"                                          \n";
    cout<<"                                          \n";
    cout<<"                                          \n";

    cont = contg;

    while(cont--);

    system("cls");

    cout<<'\n'<<'\n'<<'\n'<<'\n';
    cout<<"                                           \n";
    cout<<"                                           \n";
    cout<<"                                           \n";
    cout<<"                                           \n";
    cout<<"                                           \n";
    cout<<"                                       ##  \n";
    cout<<"                                      #### \n";
    cout<<"                                     ######\n";
    cout<<"                                      #### \n";
    cout<<"                                       ##  \n";
    cout<<"                                           \n";
    cout<<"                                           \n";
    cout<<"                                           \n";
    cout<<"                                           \n";
    cout<<"                                           \n";

    cont = contg;

    while(cont--);

    system("cls");

    cout<<'\n'<<'\n'<<'\n'<<'\n';
    cout<<"                                           \n";
    cout<<"                                           \n";
    cout<<"                                           \n";
    cout<<"                                           \n";
    cout<<"                                           \n";
    cout<<"                                      #### \n";
    cout<<"                                     ######\n";
    cout<<"                                     ######\n";
    cout<<"                                     ######\n";
    cout<<"                                      #### \n";
    cout<<"                                           \n";
    cout<<"                                           \n";
    cout<<"                                           \n";
    cout<<"                                           \n";
    cout<<"                                           \n";

    cont = contg;

    while(cont--);

    system("cls");

    cout<<'\n'<<'\n'<<'\n'<<'\n';
    cout<<"                                           \n";
    cout<<"                                           \n";
    cout<<"                                           \n";
    cout<<"                                           \n";
    cout<<"                                           \n";
    cout<<"                                     ######\n";
    cout<<"                                     ######\n";
    cout<<"                                     ######\n";
    cout<<"                                     ######\n";
    cout<<"                                     ######\n";
    cout<<"                                           \n";
    cout<<"                                           \n";
    cout<<"                                           \n";
    cout<<"                                           \n";
    cout<<"                                           \n";

    cont = contg;

    while(cont--);

    system("cls");

    cout<<'\n'<<'\n'<<'\n'<<'\n';
    cout<<"                                            \n";
    cout<<"                                            \n";
    cout<<"                                            \n";
    cout<<"                                            \n";
    cout<<"                                       ##   \n";
    cout<<"                                     ###### \n";
    cout<<"                                     ###### \n";
    cout<<"                                    ########\n";
    cout<<"                                     ###### \n";
    cout<<"                                     ###### \n";
    cout<<"                                       ##   \n";
    cout<<"                                            \n";
    cout<<"                                            \n";
    cout<<"                                            \n";
    cout<<"                                            \n";

    cont = contg;

    while(cont--);

    system("cls");

    cout<<'\n'<<'\n'<<'\n'<<'\n';
    cout<<"                                            \n";
    cout<<"                                            \n";
    cout<<"                                            \n";
    cout<<"                                            \n";
    cout<<"                                      ####  \n";
    cout<<"                                     ###### \n";
    cout<<"                                    ########\n";
    cout<<"                                    ########\n";
    cout<<"                                    ########\n";
    cout<<"                                     ###### \n";
    cout<<"                                      ####  \n";
    cout<<"                                            \n";
    cout<<"                                            \n";
    cout<<"                                            \n";
    cout<<"                                            \n";

    cont = contg;

    while(cont--);

    system("cls");

    cout<<'\n'<<'\n'<<'\n'<<'\n';
    cout<<"                                            \n";
    cout<<"                                            \n";
    cout<<"                                            \n";
    cout<<"                                            \n";
    cout<<"                                     ###### \n";
    cout<<"                                    ########\n";
    cout<<"                                    ########\n";
    cout<<"                                    ########\n";
    cout<<"                                    ########\n";
    cout<<"                                    ########\n";
    cout<<"                                     ###### \n";
    cout<<"                                            \n";
    cout<<"                                            \n";
    cout<<"                                            \n";
    cout<<"                                            \n";

    cont = contg;

    while(cont--);

    system("cls");

    cout<<'\n'<<'\n'<<'\n'<<'\n';
    cout<<"                                            \n";
    cout<<"                                            \n";
    cout<<"                                            \n";
    cout<<"                                            \n";
    cout<<"                                    ########\n";
    cout<<"                                    ########\n";
    cout<<"                                    ########\n";
    cout<<"                                    ########\n";
    cout<<"                                    ########\n";
    cout<<"                                    ########\n";
    cout<<"                                    ########\n";
    cout<<"                                            \n";
    cout<<"                                            \n";
    cout<<"                                            \n";
    cout<<"                                            \n";

    cont = contg;

    while(cont--);

    system("cls");

    cout<<'\n'<<'\n'<<'\n'<<'\n';
    cout<<"                                             \n";
    cout<<"                                             \n";
    cout<<"                                             \n";
    cout<<"                                       ##    \n";
    cout<<"                                    ######## \n";
    cout<<"                                    ######## \n";
    cout<<"                                    ######## \n";
    cout<<"                                   ##########\n";
    cout<<"                                    ######## \n";
    cout<<"                                    ######## \n";
    cout<<"                                    ######## \n";
    cout<<"                                       ##    \n";
    cout<<"                                             \n";
    cout<<"                                             \n";
    cout<<"                                             \n";

    cont = contg;

    while(cont--);

    system("cls");

    cout<<'\n'<<'\n'<<'\n'<<'\n';
    cout<<"                                             \n";
    cout<<"                                             \n";
    cout<<"                                             \n";
    cout<<"                                      ####   \n";
    cout<<"                                    ######## \n";
    cout<<"                                    ######## \n";
    cout<<"                                   ##########\n";
    cout<<"                                   ##########\n";
    cout<<"                                   ##########\n";
    cout<<"                                    ######## \n";
    cout<<"                                    ######## \n";
    cout<<"                                      ####   \n";
    cout<<"                                             \n";
    cout<<"                                             \n";
    cout<<"                                             \n";

    cont = contg;

    while(cont--);

    system("cls");

    cout<<'\n'<<'\n'<<'\n'<<'\n';
    cout<<"                                             \n";
    cout<<"                                             \n";
    cout<<"                                             \n";
    cout<<"                                     ######  \n";
    cout<<"                                    ######## \n";
    cout<<"                                   ##########\n";
    cout<<"                                   ##########\n";
    cout<<"                                   ##########\n";
    cout<<"                                   ##########\n";
    cout<<"                                   ##########\n";
    cout<<"                                    ######## \n";
    cout<<"                                     ######  \n";
    cout<<"                                             \n";
    cout<<"                                             \n";
    cout<<"                                             \n";

    cont = contg;

    while(cont--);

    system("cls");

    cout<<'\n'<<'\n'<<'\n'<<'\n';
    cout<<"                                             \n";
    cout<<"                                             \n";
    cout<<"                                             \n";
    cout<<"                                    ###  ### \n";
    cout<<"                                   ##########\n";
    cout<<"                                   ##########\n";
    cout<<"                                   ##########\n";
    cout<<"                                   ##########\n";
    cout<<"                                   ##########\n";
    cout<<"                                   ##########\n";
    cout<<"                                   ##########\n";
    cout<<"                                    ######## \n";
    cout<<"                                             \n";
    cout<<"                                             \n";
    cout<<"                                             \n";

    cont = contg;

    while(cont--);

    system("cls");

    cout<<'\n'<<'\n'<<'\n'<<'\n';
    cout<<"                                             \n";
    cout<<"                                             \n";
    cout<<"                                             \n";
    cout<<"                                   ####  ####\n";
    cout<<"                                   ##########\n";
    cout<<"                                   ##########\n";
    cout<<"                                   ##########\n";
    cout<<"                                   ##########\n";
    cout<<"                                   ##########\n";
    cout<<"                                   ##########\n";
    cout<<"                                   ##########\n";
    cout<<"                                    ######## \n";
    cout<<"                                             \n";
    cout<<"                                             \n";
    cout<<"                                             \n";

    cont = contg;

    while(cont--);

    system("cls");

    cout<<'\n'<<'\n'<<'\n'<<'\n';
    cout<<"                                              \n";
    cout<<"                                              \n";
    cout<<"                                  ####    ####\n";
    cout<<"                                  #####  #####\n";
    cout<<"                                  ############\n";
    cout<<"                                  ############\n";
    cout<<"                                  ############\n";
    cout<<"                                  ############\n";
    cout<<"                                  ############\n";
    cout<<"                                  ############\n";
    cout<<"                                  ############\n";
    cout<<"                                   ########## \n";
    cout<<"                                    ########  \n";
    cout<<"                                              \n";
    cout<<"                                              \n";

    cont = contg;

    while(cont--);

    system("cls");

    cout<<'\n'<<'\n'<<'\n'<<'\n';
    cout<<"                                               \n";
    cout<<"                                 ####      ####\n";
    cout<<"                                 #####    #####\n";
    cout<<"                                 ######  ######\n";
    cout<<"                                 ##############\n";
    cout<<"                                 ##############\n";
    cout<<"                                 ##############\n";
    cout<<"                                 ##############\n";
    cout<<"                                 ##############\n";
    cout<<"                                 ##############\n";
    cout<<"                                  ############ \n";
    cout<<"                                   ##########  \n";
    cout<<"                                    ########   \n";
    cout<<"                                     ######    \n";
    cout<<"                                               \n";

    cont = contg;

    while(cont--);

    system("cls");

    cout<<'\n'<<'\n'<<'\n'<<'\n';
    cout<<"                                ####        ####\n";
    cout<<"                                #####      #####\n";
    cout<<"                                ######    ######\n";
    cout<<"                                #######  #######\n";
    cout<<"                                ################\n";
    cout<<"                                ################\n";
    cout<<"                                ################\n";
    cout<<"                                ################\n";
    cout<<"                                ################\n";
    cout<<"                                 ############## \n";
    cout<<"                                  ############  \n";
    cout<<"                                   ##########   \n";
    cout<<"                                    ########    \n";
    cout<<"                                     ######     \n";
    cout<<"                                      ####      \n";

    cont = contg;

    while(cont--);

    system("cls");

    cout<<'\n'<<'\n'<<'\n'<<'\n';
    cout<<"                                ####        #### \n";
    cout<<"                               ######      ######\n";
    cout<<"                               #######    #######\n";
    cout<<"                               ########  ########\n";
    cout<<"                               ##################\n";
    cout<<"                               ##################\n";
    cout<<"                               ##################\n";
    cout<<"                               ##################\n";
    cout<<"                                ################ \n";
    cout<<"                                 ##############  \n";
    cout<<"                                  ############   \n";
    cout<<"                                   ##########    \n";
    cout<<"                                    ########     \n";
    cout<<"                                     ######      \n";
    cout<<"                                      ####       \n";

    cont = contg;

    while(cont--);

    system("cls");

    cout<<'\n'<<'\n'<<'\n'<<'\n';
    cout<<"                                ####        ####  \n";
    cout<<"                               ######      ###### \n";
    cout<<"                              ########    ########\n";
    cout<<"                              #########  #########\n";
    cout<<"                              ####################\n";
    cout<<"                              ####################\n";
    cout<<"                              ####################\n";
    cout<<"                               ################## \n";
    cout<<"                                ################  \n";
    cout<<"                                 ##############   \n";
    cout<<"                                  ############    \n";
    cout<<"                                   ##########     \n";
    cout<<"                                    ########      \n";
    cout<<"                                     ######       \n";
    cout<<"                                      ####        \n";

    cont = contg;

    while(cont--);

    system("cls");

    cout<<'\n'<<'\n'<<'\n'<<'\n';
    cout<<"                                ####        ####   \n";
    cout<<"                               ######      ######  \n";
    cout<<"                              ########    ######## \n";
    cout<<"                             ##########  ##########\n";
    cout<<"                             ######################\n";
    cout<<"                             ######################\n";
    cout<<"                              #################### \n";
    cout<<"                               ##################  \n";
    cout<<"                                ################   \n";
    cout<<"                                 ##############    \n";
    cout<<"                                  ############     \n";
    cout<<"                                   ##########      \n";
    cout<<"                                    ########       \n";
    cout<<"                                     ######        \n";
    cout<<"                                      ####         \n";

    cont = contg * 15;

    while(cont--);

    system("cls");

    cout<<'\n'<<'\n'<<'\n'<<'\n';
    cout<<"                                ####        ####  \n";
    cout<<"                               ######      ###### \n";
    cout<<"                              ########    ########\n";
    cout<<"                              #########  #########\n";
    cout<<"                              ####################\n";
    cout<<"                              ####################\n";
    cout<<"                              ####################\n";
    cout<<"                               ################## \n";
    cout<<"                                ################  \n";
    cout<<"                                 ##############   \n";
    cout<<"                                  ############    \n";
    cout<<"                                   ##########     \n";
    cout<<"                                    ########      \n";
    cout<<"                                     ######       \n";
    cout<<"                                      ####        \n";

    cont = contg;

    while(cont--);

    system("cls");

    cout<<'\n'<<'\n'<<'\n'<<'\n';
    cout<<"                                ####        #### \n";
    cout<<"                               ######      ######\n";
    cout<<"                               #######    #######\n";
    cout<<"                               ########  ########\n";
    cout<<"                               ##################\n";
    cout<<"                               ##################\n";
    cout<<"                               ##################\n";
    cout<<"                               ##################\n";
    cout<<"                                ################ \n";
    cout<<"                                 ##############  \n";
    cout<<"                                  ############   \n";
    cout<<"                                   ##########    \n";
    cout<<"                                    ########     \n";
    cout<<"                                     ######      \n";
    cout<<"                                      ####       \n";

    cont = contg;

    while(cont--);

    system("cls");

    cout<<'\n'<<'\n'<<'\n'<<'\n';
    cout<<"                                ####        ####\n";
    cout<<"                                #####      #####\n";
    cout<<"                                ######    ######\n";
    cout<<"                                #######  #######\n";
    cout<<"                                ################\n";
    cout<<"                                ################\n";
    cout<<"                                ################\n";
    cout<<"                                ################\n";
    cout<<"                                ################\n";
    cout<<"                                 ############## \n";
    cout<<"                                  ############  \n";
    cout<<"                                   ##########   \n";
    cout<<"                                    ########    \n";
    cout<<"                                     ######     \n";
    cout<<"                                      ####      \n";

    cont = contg;

    while(cont--);

    system("cls");

    cout<<'\n'<<'\n'<<'\n'<<'\n';
    cout<<"                                               \n";
    cout<<"                                 ####      ####\n";
    cout<<"                                 #####    #####\n";
    cout<<"                                 ######  ######\n";
    cout<<"                                 ##############\n";
    cout<<"                                 ##############\n";
    cout<<"                                 ##############\n";
    cout<<"                                 ##############\n";
    cout<<"                                 ##############\n";
    cout<<"                                 ##############\n";
    cout<<"                                  ############ \n";
    cout<<"                                   ##########  \n";
    cout<<"                                    ########   \n";
    cout<<"                                     ######    \n";
    cout<<"                                               \n";

    cont = contg;

    while(cont--);

    system("cls");

    cout<<'\n'<<'\n'<<'\n'<<'\n';
    cout<<"                                              \n";
    cout<<"                                              \n";
    cout<<"                                  ####    ####\n";
    cout<<"                                  #####  #####\n";
    cout<<"                                  ############\n";
    cout<<"                                  ############\n";
    cout<<"                                  ############\n";
    cout<<"                                  ############\n";
    cout<<"                                  ############\n";
    cout<<"                                  ############\n";
    cout<<"                                  ############\n";
    cout<<"                                   ########## \n";
    cout<<"                                    ########  \n";
    cout<<"                                              \n";
    cout<<"                                              \n";

    cont = contg;

    while(cont--);

    system("cls");

    cout<<'\n'<<'\n'<<'\n'<<'\n';
    cout<<"                                             \n";
    cout<<"                                             \n";
    cout<<"                                             \n";
    cout<<"                                   ####  ####\n";
    cout<<"                                   ##########\n";
    cout<<"                                   ##########\n";
    cout<<"                                   ##########\n";
    cout<<"                                   ##########\n";
    cout<<"                                   ##########\n";
    cout<<"                                   ##########\n";
    cout<<"                                   ##########\n";
    cout<<"                                    ######## \n";
    cout<<"                                             \n";
    cout<<"                                             \n";
    cout<<"                                             \n";

    cont = contg;

    while(cont--);

    system("cls");

    cout<<'\n'<<'\n'<<'\n'<<'\n';
    cout<<"                                             \n";
    cout<<"                                             \n";
    cout<<"                                             \n";
    cout<<"                                    ###  ### \n";
    cout<<"                                   ##########\n";
    cout<<"                                   ##########\n";
    cout<<"                                   ##########\n";
    cout<<"                                   ##########\n";
    cout<<"                                   ##########\n";
    cout<<"                                   ##########\n";
    cout<<"                                   ##########\n";
    cout<<"                                    ######## \n";
    cout<<"                                             \n";
    cout<<"                                             \n";
    cout<<"                                             \n";

    cont = contg;

    while(cont--);

    system("cls");

    cout<<'\n'<<'\n'<<'\n'<<'\n';
    cout<<"                                             \n";
    cout<<"                                             \n";
    cout<<"                                             \n";
    cout<<"                                     ######  \n";
    cout<<"                                    ######## \n";
    cout<<"                                   ##########\n";
    cout<<"                                   ##########\n";
    cout<<"                                   ##########\n";
    cout<<"                                   ##########\n";
    cout<<"                                   ##########\n";
    cout<<"                                    ######## \n";
    cout<<"                                     ######  \n";
    cout<<"                                             \n";
    cout<<"                                             \n";
    cout<<"                                             \n";

    cont = contg;

    while(cont--);

    system("cls");

    cout<<'\n'<<'\n'<<'\n'<<'\n';
    cout<<"                                             \n";
    cout<<"                                             \n";
    cout<<"                                             \n";
    cout<<"                                      ####   \n";
    cout<<"                                    ######## \n";
    cout<<"                                    ######## \n";
    cout<<"                                   ##########\n";
    cout<<"                                   ##########\n";
    cout<<"                                   ##########\n";
    cout<<"                                    ######## \n";
    cout<<"                                    ######## \n";
    cout<<"                                      ####   \n";
    cout<<"                                             \n";
    cout<<"                                             \n";
    cout<<"                                             \n";

    cont = contg;

    while(cont--);

    system("cls");

    cout<<'\n'<<'\n'<<'\n'<<'\n';
    cout<<"                                             \n";
    cout<<"                                             \n";
    cout<<"                                             \n";
    cout<<"                                       ##    \n";
    cout<<"                                    ######## \n";
    cout<<"                                    ######## \n";
    cout<<"                                    ######## \n";
    cout<<"                                   ##########\n";
    cout<<"                                    ######## \n";
    cout<<"                                    ######## \n";
    cout<<"                                    ######## \n";
    cout<<"                                       ##    \n";
    cout<<"                                             \n";
    cout<<"                                             \n";
    cout<<"                                             \n";

    cont = contg;

    while(cont--);

    system("cls");

    cout<<'\n'<<'\n'<<'\n'<<'\n';
    cout<<"                                            \n";
    cout<<"                                            \n";
    cout<<"                                            \n";
    cout<<"                                            \n";
    cout<<"                                    ########\n";
    cout<<"                                    ########\n";
    cout<<"                                    ########\n";
    cout<<"                                    ########\n";
    cout<<"                                    ########\n";
    cout<<"                                    ########\n";
    cout<<"                                    ########\n";
    cout<<"                                            \n";
    cout<<"                                            \n";
    cout<<"                                            \n";
    cout<<"                                            \n";

    cont = contg;

    while(cont--);

    system("cls");

    cout<<'\n'<<'\n'<<'\n'<<'\n';
    cout<<"                                            \n";
    cout<<"                                            \n";
    cout<<"                                            \n";
    cout<<"                                            \n";
    cout<<"                                     ###### \n";
    cout<<"                                    ########\n";
    cout<<"                                    ########\n";
    cout<<"                                    ########\n";
    cout<<"                                    ########\n";
    cout<<"                                    ########\n";
    cout<<"                                     ###### \n";
    cout<<"                                            \n";
    cout<<"                                            \n";
    cout<<"                                            \n";
    cout<<"                                            \n";

    cont = contg;

    while(cont--);

    system("cls");

    cout<<'\n'<<'\n'<<'\n'<<'\n';
    cout<<"                                            \n";
    cout<<"                                            \n";
    cout<<"                                            \n";
    cout<<"                                            \n";
    cout<<"                                      ####  \n";
    cout<<"                                     ###### \n";
    cout<<"                                    ########\n";
    cout<<"                                    ########\n";
    cout<<"                                    ########\n";
    cout<<"                                     ###### \n";
    cout<<"                                      ####  \n";
    cout<<"                                            \n";
    cout<<"                                            \n";
    cout<<"                                            \n";
    cout<<"                                            \n";

    cont = contg;

    while(cont--);

    system("cls");

    cout<<'\n'<<'\n'<<'\n'<<'\n';
    cout<<"                                            \n";
    cout<<"                                            \n";
    cout<<"                                            \n";
    cout<<"                                            \n";
    cout<<"                                       ##   \n";
    cout<<"                                     ###### \n";
    cout<<"                                     ###### \n";
    cout<<"                                    ########\n";
    cout<<"                                     ###### \n";
    cout<<"                                     ###### \n";
    cout<<"                                       ##   \n";
    cout<<"                                            \n";
    cout<<"                                            \n";
    cout<<"                                            \n";
    cout<<"                                            \n";

    cont = contg;

    while(cont--);

    system("cls");

    cout<<'\n'<<'\n'<<'\n'<<'\n';
    cout<<"                                           \n";
    cout<<"                                           \n";
    cout<<"                                           \n";
    cout<<"                                           \n";
    cout<<"                                           \n";
    cout<<"                                     ######\n";
    cout<<"                                     ######\n";
    cout<<"                                     ######\n";
    cout<<"                                     ######\n";
    cout<<"                                     ######\n";
    cout<<"                                           \n";
    cout<<"                                           \n";
    cout<<"                                           \n";
    cout<<"                                           \n";
    cout<<"                                           \n";

    cont = contg;

    while(cont--);

    system("cls");

    cout<<'\n'<<'\n'<<'\n'<<'\n';
    cout<<"                                           \n";
    cout<<"                                           \n";
    cout<<"                                           \n";
    cout<<"                                           \n";
    cout<<"                                           \n";
    cout<<"                                      #### \n";
    cout<<"                                     ######\n";
    cout<<"                                     ######\n";
    cout<<"                                     ######\n";
    cout<<"                                      #### \n";
    cout<<"                                           \n";
    cout<<"                                           \n";
    cout<<"                                           \n";
    cout<<"                                           \n";
    cout<<"                                           \n";

    cont = contg;

    while(cont--);

    system("cls");

    cout<<'\n'<<'\n'<<'\n'<<'\n';
    cout<<"                                           \n";
    cout<<"                                           \n";
    cout<<"                                           \n";
    cout<<"                                           \n";
    cout<<"                                           \n";
    cout<<"                                       ##  \n";
    cout<<"                                      #### \n";
    cout<<"                                     ######\n";
    cout<<"                                      #### \n";
    cout<<"                                       ##  \n";
    cout<<"                                           \n";
    cout<<"                                           \n";
    cout<<"                                           \n";
    cout<<"                                           \n";
    cout<<"                                           \n";

    cont = contg;

    while(cont--);

    system("cls");

    cout<<'\n'<<'\n'<<'\n'<<'\n';
    cout<<"                                          \n";
    cout<<"                                          \n";
    cout<<"                                          \n";
    cout<<"                                          \n";
    cout<<"                                          \n";
    cout<<"                                          \n";
    cout<<"                                      ####\n";
    cout<<"                                      ####\n";
    cout<<"                                      ####\n";
    cout<<"                                          \n";
    cout<<"                                          \n";
    cout<<"                                          \n";
    cout<<"                                          \n";
    cout<<"                                          \n";
    cout<<"                                          \n";

    cont = contg;

    while(cont--);

    system("cls");

    cout<<'\n'<<'\n'<<'\n'<<'\n';
    cout<<"                                          \n";
    cout<<"                                          \n";
    cout<<"                                          \n";
    cout<<"                                          \n";
    cout<<"                                          \n";
    cout<<"                                          \n";
    cout<<"                                       ## \n";
    cout<<"                                      ####\n";
    cout<<"                                       ## \n";
    cout<<"                                          \n";
    cout<<"                                          \n";
    cout<<"                                          \n";
    cout<<"                                          \n";
    cout<<"                                          \n";
    cout<<"                                          \n";

    cont = contg;

    while(cont--);

    system("cls");

    cout<<'\n'<<'\n'<<'\n'<<'\n';
    cout<<"                                         \n";
    cout<<"                                         \n";
    cout<<"                                         \n";
    cout<<"                                         \n";
    cout<<"                                         \n";
    cout<<"                                         \n";
    cout<<"                                         \n";
    cout<<"                                       ##\n";
    cout<<"                                         \n";
    cout<<"                                         \n";
    cout<<"                                         \n";
    cout<<"                                         \n";
    cout<<"                                         \n";
    cout<<"                                         \n";
    cout<<"                                         \n";

    system("cls");

    return;
}
