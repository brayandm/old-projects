#include <bits/stdc++.h>

#define db(x) cout << #x ": " << x << '\n';

using namespace std;

const int MAXN = 64;

const int MAXC = 8;

typedef unsigned long long ull;

typedef map<ull, map<ull, int > > map64;

typedef pair<ull,ull> pll;

map64 DP;

int cont;

int tablero[MAXN];

vector<int> fichas[2];

ull POW3[MAXN/2];

void calcPOW3();

pll convertir(int[]);

bool chequearganar(int[]);

int recursividad(int[]);

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

void print(int A[MAXN])
{
    for(int i = 0 ; i < MAXC ; i++)
    {
        for(int j = 0 ; j < MAXC ; j++)
        {
            cout << A[i*8+j] << " ";
        }
        cout << '\n';
    }

    cin.get();

    return;
}

int recursividad(int A[MAXN],vector<int> F[2], bool player)
{
    pll n = convertir(A);

    if(DP[n.first][n.second])
    {
        return DP[n.first][n.second];
    }

    if(chequearganar(A))
    {
        DP[n.first][n.second] = 1;

        cout << n.first << " " << n.second << " " << DP[n.first][n.second] << '\n';

        return DP[n.first][n.second];
    }

    bool gan = false;

    bool per = false;

    for(int i = 0 ; i < F[player].size() ; i++)
    {
        vector<int> movimientos;

        chequearmovimientos(F[player][i],A,movimientos);

        int posOF = F[player][i];

        int Fich = A[F[player][i]];

        for(int j = 0 ; j < movimientos.size() ; j++)
        {
            A[F[player][i]] = 0;

            F[player][i] = movimientos[j];

            A[F[player][i]] = Fich;

            int ver = recursividad(A,F,!player);

            if(ver == 1)
            {
                gan = true;
            }
            else if(ver == 2)
            {
                per = true;
            }

            A[F[player][i]] = 0;

            F[player][i] = posOF;

            A[F[player][i]] = Fich;
        }
    }

    if(gan)
    {
        DP[n.first][n.second] = 2;

        cout << n.first << " " << n.second << " " << DP[n.first][n.second] << '\n';

        return DP[n.first][n.second];
    }
    if(!gan && per)
    {
        DP[n.first][n.second] = 1;

        cout << n.first << " " << n.second << " " << DP[n.first][n.second] << '\n';

        return DP[n.first][n.second];
    }
    if(!gan && !per)
    {
        DP[n.first][n.second] = 1;

        cout << n.first << " " << n.second << " " << DP[n.first][n.second] << '\n';

        return DP[n.first][n.second];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("DP.in","w",stdout);

    calcPOW3();

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

    recursividad(tablero,fichas,0);

    return 0;
}
