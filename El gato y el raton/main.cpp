#include <bits/stdc++.h>

#include <conio.h>

#define db(x) cout << #x ": " << x << '\n';

using namespace std;

const int MAXN = 64;

const int MAXC = 8;

typedef unsigned long long ull;

typedef map<ull, map<ull, int > > map64;

typedef pair<ull,ull> pll;

map64 DP;

ull POW3[MAXN/2];

int tablero[MAXN];

vector<int> fichas[2];

void calcPOW3()
{
    POW3[0] = 1;

    for(int i = 1 ; i < MAXN / 2 ; i++)
    {
        POW3[i] = POW3[i-1] * 3;
    }

    return;
}

pll convertir(int A[MAXN])
{
    pll n;

    for(int i = 0 ; i < MAXN / 2 ; i++)
    {
        n.first +=  A[i] * POW3[i];
        n.second += A[i+MAXN/2] * POW3[i];
    }

    return n;
}

void leerdatos()
{
    FILE *fin = fopen ("DP.in", "r");

    ull n1, n2, n3;

    while(fscanf (fin, "%lld %lld %lld", &n1, &n2, &n3) != EOF)
    {
        DP[n1][n2] = n3;
    }

    fichas[1].push_back(1);
    fichas[1].push_back(3);
    fichas[1].push_back(5);
    fichas[1].push_back(7);
    fichas[0].push_back(60);

    tablero[1] = 2;
    tablero[3] = 2;
    tablero[5] = 2;
    tablero[7] = 2;
    tablero[60] = 1;

    return;
}

void print(int A[MAXN],bool v)
{
    cout << "   1 2 3 4 5 6 7 8" << "  \'r\' - retornar, \'i\' - invertir, \'s\' - salir."<< '\n';
    cout << "  ----------------" << '\n';

    for(int i = 0 ; i < MAXC ; i++)
    {
        cout << i + 1 << "| ";

        for(int j = 0 ; j < MAXC ; j++)
        {
            int a;

            if(v)
            {
                a = A[(7-i)*8+(7-j)];
            }
            else
            {
                a = A[i*8+j];
            }

            if(a == 0)
            {
                cout << '.' << " ";
            }
            else if(a == 1)
            {
                cout << 'O' << " ";
            }
            else if(a == 2)
            {
                cout << '#' << " ";
            }

        }

        cout << '\n';
    }

    return;
}

void chequearmovimientos(int pos, int A[MAXN], vector<int> &mov)
{
    if(A[pos] == 1)
    {
        if(pos % MAXC != 7 && pos / MAXC != 0 && !A[pos-MAXC+1])
        {
            mov.push_back(pos-MAXC+1);
        }
        if(pos % MAXC != 0 && pos / MAXC != 0 && !A[pos-MAXC-1])
        {
            mov.push_back(pos-MAXC-1);
        }
        if(pos % MAXC != 7 && pos / MAXC != 7 && !A[pos+MAXC+1])
        {
            mov.push_back(pos+MAXC+1);
        }
        if(pos % MAXC != 0 && pos / MAXC != 7 && !A[pos+MAXC-1])
        {
            mov.push_back(pos+MAXC-1);
        }
    }
    else if(A[pos] == 2)
    {
        if(pos % MAXC != 7 && pos / MAXC != 7 && !A[pos+MAXC+1])
        {
            mov.push_back(pos+MAXC+1);
        }
        if(pos % MAXC != 0 && pos / MAXC != 7 && !A[pos+MAXC-1])
        {
            mov.push_back(pos+MAXC-1);
        }
    }

    return;
}

void igualarArreglo(int A[MAXN], int B[MAXN])
{
    for(int i = 0 ; i < MAXN ; i++)
    {
        A[i] = B[i];
    }

    return;
}

bool chequearganar(int A[MAXN])
{
    for(int i = 0 ; i < MAXC ; i++)
    {
        if(A[i] == 1)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    cout << "Cargando Base de Datos...";

    calcPOW3();

    leerdatos();

    system("cls");

    bool player = false;

    bool v = false;

    vector<pll> retjug;
    vector<int> retfic;

    while(1)
    {
        vector<pll>jug;

        vector<int>fi;

        if(!chequearganar(tablero))
        {
            print(tablero,v);

            int cont = 1;

            for(int i = 0 ; i < fichas[player].size() ; i++)
            {
                vector<int>movimientos;

                chequearmovimientos(fichas[player][i], tablero, movimientos);

                int tabA[MAXN];

                igualarArreglo(tabA,tablero);

                cout << '\n';

                for(int j = 0 ; j < movimientos.size() ; j++)
                {
                    tabA[movimientos[j]] = tabA[fichas[player][i]];

                    tabA[fichas[player][i]] = 0;

                    pll n = convertir(tabA);

                    cout << cont << "- ";

                    if(v)
                    {
                        cout << 9-(fichas[player][i]/8+1) << ";" << 9-(fichas[player][i]%8+1) << " -> ";
                        cout << 9-(movimientos[j]/8+1) << ";" << 9-(movimientos[j]%8+1) << " : ";
                    }
                    else
                    {
                        cout << fichas[player][i]/8+1 << ";" << fichas[player][i]%8+1 << " -> ";
                        cout << movimientos[j]/8+1 << ";" << movimientos[j]%8+1 << " : ";
                    }

                    if(player)
                    {
                        if(DP[n.first][n.second] == 1)
                        {
                            cout << "G" << '\n';
                        }
                        else if(DP[n.first][n.second] == 2)
                        {
                            cout << "P" << '\n';
                        }
                    }
                    else
                    {
                        if(DP[n.first][n.second] == 1)
                        {
                            cout << "G" << '\n';
                        }
                        else if(DP[n.first][n.second] == 2)
                        {
                            cout << "P" << '\n';
                        }
                    }

                    jug.push_back(make_pair(fichas[player][i],movimientos[j]));

                    fi.push_back(i);

                    igualarArreglo(tabA,tablero);

                    cont++;
                }
            }

        }
        else
        {
            system("cls");

            print(tablero,v);

            cout << '\n' << "El juego ha terminado" << '\n';
        }

        if(!fi.size() && !chequearganar(tablero))
        {
            system("cls");

            print(tablero,v);

            cout << '\n' << "El juego ha terminado" << '\n';
        }

        cout << '\n' << "No.mov: ";

        char n;

        n = getch();

        if(n == 's' || n == 'S')
        {
            return 0;
        }

        if(n == 'i' || n == 'I')
        {
            v = !v;

            system("cls");

            continue;
        }

        if(n < '1' || n > jug.size() + '0' && n != 'r' && n != 'R')
        {
            system("cls");

            continue;
        }

        if((n == 'r' || n == 'R') && !retjug.size())
        {
            system("cls");

            continue;
        }

        if(n == 'r' || n == 'R' && retjug.size())
        {
            tablero[retjug[retjug.size()-1].first] = tablero[retjug[retjug.size()-1].second];

            tablero[retjug[retjug.size()-1].second] = 0;

            fichas[!player][retfic[retfic.size()-1]] = retjug[retjug.size()-1].first;

            player = !player;

            retjug.pop_back();

            retfic.pop_back();

            system("cls");

            continue;
        }

        n--;

        tablero[jug[n-'0'].second] = tablero[jug[n-'0'].first];

        tablero[jug[n-'0'].first] = 0;

        fichas[player][fi[n-'0']] = jug[n-'0'].second;

        player = !player;

        retjug.push_back(make_pair(jug[n-'0'].first,jug[n-'0'].second));

        retfic.push_back(fi[n-'0']);

        system("cls");
    }

    return 0;
}
