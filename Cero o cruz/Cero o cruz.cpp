#include <bits/stdc++.h>
#include <conio.h>

using namespace std;

typedef unsigned long long ull;

bool check_win(int,int,int,int,int,int,int,int,int);
bool check_draw(int,int,int,int,int,int,int,int,int);
void precalc(int,int,int,int,int,int,int,int,int,bool);
void print_M();

///Desactivar Mejor Inteligencia Artificial: IAB = 0;

int IAB = 1;

///Desactivar IA (jugar RANDOM): IA = 0;

int IA = 1;

///Desactivar hacer Jugadas Ganadoras: DW = 0;

int DW = 1;

///Probabilidad de 1 en 'probalW' de hacer Jugadas Ganadoras;

int probalW = 1;

///Desactivar hacer Jugadas Perdedoras: DP = 0;

int DP = 1;

///Probabilidad de 1 en 'probalP' de hacer Jugadas Perdedoras;

int probalP = 1;

///Desactivar Ganar facil: DCW = 0;

int DCW = 1;

///Desactivar Evitar Perder facil: DCP = 0;

int DCP = 1;

int dp[3][3][3][3][3][3][3][3][3];

char M[9];

int Mp[9];

char c[] = {'X','O'};

bool check_win(int c0, int c1, int c2, int c3, int c4, int c5, int c6, int c7, int c8)
{

    if(c0 == c1 && c1 == c2 && c0 && c1 && c2)return true;
    if(c3 == c4 && c4 == c5 && c3 && c4 && c5)return true;
    if(c6 == c7 && c7 == c8 && c6 && c7 && c8)return true;
    if(c0 == c3 && c3 == c6 && c0 && c3 && c6)return true;
    if(c1 == c4 && c4 == c7 && c1 && c4 && c7)return true;
    if(c2 == c5 && c5 == c8 && c2 && c5 && c8)return true;
    if(c0 == c4 && c4 == c8 && c0 && c4 && c8)return true;
    if(c2 == c4 && c4 == c6 && c2 && c4 && c6)return true;
    return false;

}

bool check_draw(int c0, int c1, int c2, int c3, int c4, int c5, int c6, int c7, int c8)
{

    if(c0 && c1 && c2 && c3 && c4 && c5 && c6 && c7 && c8)return true;
    return false;

}

void precalc(int c0, int c1, int c2, int c3, int c4, int c5, int c6, int c7, int c8, bool player)
{
    if(dp[c0][c1][c2][c3][c4][c5][c6][c7][c8])
    {
        return;
    }

    if(check_win(c0,c1,c2,c3,c4,c5,c6,c7,c8))
    {
        dp[c0][c1][c2][c3][c4][c5][c6][c7][c8] = 1;
        return;
    }

    if(check_draw(c0,c1,c2,c3,c4,c5,c6,c7,c8))
    {
        dp[c0][c1][c2][c3][c4][c5][c6][c7][c8] = 3;
        return;
    }

    int contg = 0;
    int contp = 0;
    int contn = 0;

    if(!c0)
    {
        precalc(player+1,c1,c2,c3,c4,c5,c6,c7,c8,!player);
        if(dp[player+1][c1][c2][c3][c4][c5][c6][c7][c8] == 1)contg++;
        else if(dp[player+1][c1][c2][c3][c4][c5][c6][c7][c8] == 2)contp++;
        else if(dp[player+1][c1][c2][c3][c4][c5][c6][c7][c8] == 3)contn++;
    }

    if(!c1)
    {
        precalc(c0,player+1,c2,c3,c4,c5,c6,c7,c8,!player);
        if(dp[c0][player+1][c2][c3][c4][c5][c6][c7][c8] == 1)contg++;
        else if(dp[c0][player+1][c2][c3][c4][c5][c6][c7][c8] == 2)contp++;
        else if(dp[c0][player+1][c2][c3][c4][c5][c6][c7][c8] == 3)contn++;
    }

    if(!c2)
    {
        precalc(c0,c1,player+1,c3,c4,c5,c6,c7,c8,!player);
        if(dp[c0][c1][player+1][c3][c4][c5][c6][c7][c8] == 1)contg++;
        else if(dp[c0][c1][player+1][c3][c4][c5][c6][c7][c8] == 2)contp++;
        else if(dp[c0][c1][player+1][c3][c4][c5][c6][c7][c8] == 3)contn++;
    }

    if(!c3)
    {
        precalc(c0,c1,c2,player+1,c4,c5,c6,c7,c8,!player);
        if(dp[c0][c1][c2][player+1][c4][c5][c6][c7][c8] == 1)contg++;
        else if(dp[c0][c1][c2][player+1][c4][c5][c6][c7][c8] == 2)contp++;
        else if(dp[c0][c1][c2][player+1][c4][c5][c6][c7][c8] == 3)contn++;
    }

    if(!c4)
    {
        precalc(c0,c1,c2,c3,player+1,c5,c6,c7,c8,!player);
        if(dp[c0][c1][c2][c3][player+1][c5][c6][c7][c8] == 1)contg++;
        else if(dp[c0][c1][c2][c3][player+1][c5][c6][c7][c8] == 2)contp++;
        else if(dp[c0][c1][c2][c3][player+1][c5][c6][c7][c8] == 3)contn++;
    }

    if(!c5)
    {
        precalc(c0,c1,c2,c3,c4,player+1,c6,c7,c8,!player);
        if(dp[c0][c1][c2][c3][c4][player+1][c6][c7][c8] == 1)contg++;
        else if(dp[c0][c1][c2][c3][c4][player+1][c6][c7][c8] == 2)contp++;
        else if(dp[c0][c1][c2][c3][c4][player+1][c6][c7][c8] == 3)contn++;
    }

    if(!c6)
    {
        precalc(c0,c1,c2,c3,c4,c5,player+1,c7,c8,!player);
        if(dp[c0][c1][c2][c3][c4][c5][player+1][c7][c8] == 1)contg++;
        else if(dp[c0][c1][c2][c3][c4][c5][player+1][c7][c8] == 2)contp++;
        else if(dp[c0][c1][c2][c3][c4][c5][player+1][c7][c8] == 3)contn++;
    }

    if(!c7)
    {
        precalc(c0,c1,c2,c3,c4,c5,c6,player+1,c8,!player);
        if(dp[c0][c1][c2][c3][c4][c5][c6][player+1][c8] == 1)contg++;
        else if(dp[c0][c1][c2][c3][c4][c5][c6][player+1][c8] == 2)contp++;
        else if(dp[c0][c1][c2][c3][c4][c5][c6][player+1][c8] == 3)contn++;
    }

    if(!c8)
    {
        precalc(c0,c1,c2,c3,c4,c5,c6,c7,player+1,!player);
        if(dp[c0][c1][c2][c3][c4][c5][c6][c7][player+1] == 1)contg++;
        else if(dp[c0][c1][c2][c3][c4][c5][c6][c7][player+1] == 2)contp++;
        else if(dp[c0][c1][c2][c3][c4][c5][c6][c7][player+1] == 3)contn++;
    }

    if(contg)
    {
        dp[c0][c1][c2][c3][c4][c5][c6][c7][c8] = 2;
        return;
    }
    if(contp && !contn)
    {
        dp[c0][c1][c2][c3][c4][c5][c6][c7][c8] = 1;
        return;
    }
    if(contp && contn)
    {
        dp[c0][c1][c2][c3][c4][c5][c6][c7][c8] = 3;
        return;
    }
    if(!contp && contn)
    {
        dp[c0][c1][c2][c3][c4][c5][c6][c7][c8] = 3;
        return;
    }

}

void print_M()
{

    cout << '\n';
    cout << '\n';
    cout << "    " << M[0] << " / " << M[1] << " / " << M[2] << '\n';
    cout << "   ----------" << '\n';
    cout << "   " << M[3] << " / " << M[4] << " / " << M[5] << '\n';
    cout << "  ---------- " << '\n';
    cout << "  " << M[6] << " / " << M[7] << " / " << M[8] << '\n';

    return;
}

int main()
{
    system("color 8b");

    FILE *fin = fopen ("IA.in", "r");

    fscanf(fin,"%d%d%d%d%d%d%d%d",&IAB,&IA,&DW,&probalW,&DP,&probalP,&DCW,&DCP);

    fclose(fin);

    if(probalW <= 0)probalW = 1;
    if(probalP <= 0)probalP = 1;

    precalc(0,0,0,0,0,0,0,0,0,0);

    char conc[2][9];

    conc[0][0] = 'q';
    conc[0][1] = 'w';
    conc[0][2] = 'e';
    conc[0][3] = 'a';
    conc[0][4] = 's';
    conc[0][5] = 'd';
    conc[0][6] = 'z';
    conc[0][7] = 'x';
    conc[0][8] = 'c';

    conc[1][0] = '7';
    conc[1][1] = '8';
    conc[1][2] = '9';
    conc[1][3] = '4';
    conc[1][4] = '5';
    conc[1][5] = '6';
    conc[1][6] = '1';
    conc[1][7] = '2';
    conc[1][8] = '3';

    char el;

    bool b = 1;
    bool j = 0;

    bool cc = 1;

    cout << "Que configuracion de control quieres QWE(\'1\') o Num Pad(\'2\'): ";

    el = getch();

    if(el == '1')cc = 0;

    system("cls");

    cout << "\"Vamos a jugar, quien empieza primero tu (\'1\') o yo (\'2\')\": ";

    el = getch();

    if(el == '1')b = 0;

    system("cls");

    cout << "\"Elige Cero (\'1\') o Cruz (\'2\')\": ";

    el = getch();

    if(el == '1')swap(c[0],c[1]);

    system("cls");

    bool uj = b;

    while(1)
    {
        b = uj;

        uj = !uj;

        for(int i = 0 ; i < 9 ; i++)
        {
            M[i] = ' ';
            Mp[i] = 0;

            j = 0;
        }

        while(1)
        {

            print_M();

            char sel;

            if(!b)sel = getch();
            else
            {

                vector<int>w;
                vector<int>p;
                vector<int>n;
                vector<int>o;
                vector<int>ow;
                vector<int>r;

                int cantm = 0;;

                if(!Mp[0])
                {
                    r.push_back(0);
                    int play = dp[j+1][Mp[1]][Mp[2]][Mp[3]][Mp[4]][Mp[5]][Mp[6]][Mp[7]][Mp[8]];
                    if(play == 1)w.push_back(0);
                    else if(play == 2)p.push_back(0);
                    else if(play == 3)n.push_back(0);
                    cantm++;
                }
                if(!Mp[1])
                {
                    r.push_back(1);
                    int play = dp[Mp[0]][j+1][Mp[2]][Mp[3]][Mp[4]][Mp[5]][Mp[6]][Mp[7]][Mp[8]];
                    if(play == 1)w.push_back(1);
                    else if(play == 2)p.push_back(1);
                    else if(play == 3)n.push_back(1);
                    cantm++;
                }
                if(!Mp[2])
                {
                    r.push_back(2);
                    int play = dp[Mp[0]][Mp[1]][j+1][Mp[3]][Mp[4]][Mp[5]][Mp[6]][Mp[7]][Mp[8]];
                    if(play == 1)w.push_back(2);
                    else if(play == 2)p.push_back(2);
                    else if(play == 3)n.push_back(2);
                    cantm++;
                }
                if(!Mp[3])
                {
                    r.push_back(3);
                    int play = dp[Mp[0]][Mp[1]][Mp[2]][j+1][Mp[4]][Mp[5]][Mp[6]][Mp[7]][Mp[8]];
                    if(play == 1)w.push_back(3);
                    else if(play == 2)p.push_back(3);
                    else if(play == 3)n.push_back(3);
                    cantm++;
                }
                if(!Mp[4])
                {
                    r.push_back(4);
                    int play = dp[Mp[0]][Mp[1]][Mp[2]][Mp[3]][j+1][Mp[5]][Mp[6]][Mp[7]][Mp[8]];
                    if(play == 1)w.push_back(4);
                    else if(play == 2)p.push_back(4);
                    else if(play == 3)n.push_back(4);
                    cantm++;
                }
                if(!Mp[5])
                {
                    r.push_back(5);
                    int play = dp[Mp[0]][Mp[1]][Mp[2]][Mp[3]][Mp[4]][j+1][Mp[6]][Mp[7]][Mp[8]];
                    if(play == 1)w.push_back(5);
                    else if(play == 2)p.push_back(5);
                    else if(play == 3)n.push_back(5);
                    cantm++;
                }
                if(!Mp[6])
                {
                    r.push_back(6);
                    int play = dp[Mp[0]][Mp[1]][Mp[2]][Mp[3]][Mp[4]][Mp[5]][j+1][Mp[7]][Mp[8]];
                    if(play == 1)w.push_back(6);
                    else if(play == 2)p.push_back(6);
                    else if(play == 3)n.push_back(6);
                    cantm++;
                }
                if(!Mp[7])
                {
                    r.push_back(7);
                    int play = dp[Mp[0]][Mp[1]][Mp[2]][Mp[3]][Mp[4]][Mp[5]][Mp[6]][j+1][Mp[8]];
                    if(play == 1)w.push_back(7);
                    else if(play == 2)p.push_back(7);
                    else if(play == 3)n.push_back(7);
                    cantm++;
                }
                if(!Mp[8])
                {
                    r.push_back(8);
                    int play = dp[Mp[0]][Mp[1]][Mp[2]][Mp[3]][Mp[4]][Mp[5]][Mp[6]][Mp[7]][j+1];
                    if(play == 1)w.push_back(8);
                    else if(play == 2)p.push_back(8);
                    else if(play == 3)n.push_back(8);
                    cantm++;
                }

                bool checkp = 0;
                bool checkw = 0;

                if(cantm > 1)
                {

                    if(!Mp[0] && check_win(!j+1,Mp[1],Mp[2],Mp[3],Mp[4],Mp[5],Mp[6],Mp[7],Mp[8]))
                    {
                        checkp = 1;
                        o.push_back(0);
                    }
                    if(!Mp[1] && check_win(Mp[0],!j+1,Mp[2],Mp[3],Mp[4],Mp[5],Mp[6],Mp[7],Mp[8]))
                    {
                        checkp = 1;
                        o.push_back(1);
                    }
                    if(!Mp[2] && check_win(Mp[0],Mp[1],!j+1,Mp[3],Mp[4],Mp[5],Mp[6],Mp[7],Mp[8]))
                    {
                        checkp = 1;
                        o.push_back(2);
                    }
                    if(!Mp[3] && check_win(Mp[0],Mp[1],Mp[2],!j+1,Mp[4],Mp[5],Mp[6],Mp[7],Mp[8]))
                    {
                        checkp = 1;
                        o.push_back(3);
                    }
                    if(!Mp[4] && check_win(Mp[0],Mp[1],Mp[2],Mp[3],!j+1,Mp[5],Mp[6],Mp[7],Mp[8]))
                    {
                        checkp = 1;
                        o.push_back(4);
                    }
                    if(!Mp[5] && check_win(Mp[0],Mp[1],Mp[2],Mp[3],Mp[4],!j+1,Mp[6],Mp[7],Mp[8]))
                    {
                        checkp = 1;
                        o.push_back(5);
                    }
                    if(!Mp[6] && check_win(Mp[0],Mp[1],Mp[2],Mp[3],Mp[4],Mp[5],!j+1,Mp[7],Mp[8]))
                    {
                        checkp = 1;
                        o.push_back(6);
                    }
                    if(!Mp[7] && check_win(Mp[0],Mp[1],Mp[2],Mp[3],Mp[4],Mp[5],Mp[6],!j+1,Mp[8]))
                    {
                        checkp = 1;
                        o.push_back(7);
                    }
                    if(!Mp[8] && check_win(Mp[0],Mp[1],Mp[2],Mp[3],Mp[4],Mp[5],Mp[6],Mp[7],!j+1))
                    {
                        checkp = 1;
                        o.push_back(8);
                    }
                    if(!Mp[0] && check_win(j+1,Mp[1],Mp[2],Mp[3],Mp[4],Mp[5],Mp[6],Mp[7],Mp[8]))
                    {
                        checkw = 1;
                        ow.push_back(0);
                    }
                    if(!Mp[1] && check_win(Mp[0],j+1,Mp[2],Mp[3],Mp[4],Mp[5],Mp[6],Mp[7],Mp[8]))
                    {
                        checkw = 1;
                        ow.push_back(1);
                    }
                    if(!Mp[2] && check_win(Mp[0],Mp[1],j+1,Mp[3],Mp[4],Mp[5],Mp[6],Mp[7],Mp[8]))
                    {
                        checkw = 1;
                        ow.push_back(2);
                    }
                    if(!Mp[3] && check_win(Mp[0],Mp[1],Mp[2],j+1,Mp[4],Mp[5],Mp[6],Mp[7],Mp[8]))
                    {
                        checkw = 1;
                        ow.push_back(3);
                    }
                    if(!Mp[4] && check_win(Mp[0],Mp[1],Mp[2],Mp[3],j+1,Mp[5],Mp[6],Mp[7],Mp[8]))
                    {
                        checkw = 1;
                        ow.push_back(4);
                    }
                    if(!Mp[5] && check_win(Mp[0],Mp[1],Mp[2],Mp[3],Mp[4],j+1,Mp[6],Mp[7],Mp[8]))
                    {
                        checkw = 1;
                        ow.push_back(5);
                    }
                    if(!Mp[6] && check_win(Mp[0],Mp[1],Mp[2],Mp[3],Mp[4],Mp[5],j+1,Mp[7],Mp[8]))
                    {
                        checkw = 1;
                        ow.push_back(6);
                    }
                    if(!Mp[7] && check_win(Mp[0],Mp[1],Mp[2],Mp[3],Mp[4],Mp[5],Mp[6],j+1,Mp[8]))
                    {
                        checkw = 1;
                        ow.push_back(7);
                    }
                    if(!Mp[8] && check_win(Mp[0],Mp[1],Mp[2],Mp[3],Mp[4],Mp[5],Mp[6],Mp[7],j+1))
                    {
                        checkw = 1;
                        ow.push_back(8);
                    }

                }



                int tim = time(0);

                while(time(0) < tim + 2);

                int possel;

                srand(time(0));

                if(!IA && !IAB)
                {

                    srand(time(0));

                    int ale = rand() % r.size();

                    possel = r[ale];

                }
                else if(checkw && !IAB && DCW)
                {

                    srand(time(0));

                    int ale = rand() % ow.size();

                    possel = ow[ale];

                }
                else if(checkp && !IAB && DCP)
                {

                    srand(time(0));

                    int ale = rand() % o.size();

                    possel = o[ale];

                }
                else if(rand() % probalP == 0 && p.size() && !IAB && DP)
                {

                    srand(time(0));

                    int ale = rand() % p.size();

                    possel = p[ale];

                }
                else if((rand() % probalW == 0 || IAB) && w.size() && (DW || IAB))
                {

                    srand(time(0));

                    int ale = rand() % w.size();

                    possel = w[ale];

                }
                else if(n.size())
                {

                    srand(time(0));

                    int ale = rand() % n.size();

                    possel = n[ale];

                }
                else if(w.size())
                {

                    srand(time(0));

                    int ale = rand() % w.size();

                    possel = w[ale];

                }
                else if(p.size())
                {

                    srand(time(0));

                    int ale = rand() % p.size();

                    possel = p[ale];

                }

                if(possel == 0)sel = conc[cc][0];
                else if(possel == 1)sel = conc[cc][1];
                else if(possel == 2)sel = conc[cc][2];
                else if(possel == 3)sel = conc[cc][3];
                else if(possel == 4)sel = conc[cc][4];
                else if(possel == 5)sel = conc[cc][5];
                else if(possel == 6)sel = conc[cc][6];
                else if(possel == 7)sel = conc[cc][7];
                else if(possel == 8)sel = conc[cc][8];

            }

            if(sel == conc[cc][0])
            {
                if(Mp[0])
                {
                    system("cls");
                    cout << "No puedes jugar en el mismo lugar.";
                    continue;
                }
                M[0] = c[b];
                Mp[0] = j + 1;
            }
            else if(sel == conc[cc][1])
            {
                if(Mp[1])
                {
                    system("cls");
                    cout << "No puedes jugar en el mismo lugar.";
                    continue;
                }
                M[1] = c[b];
                Mp[1] = j + 1;

            }
            else if(sel == conc[cc][2])
            {
                if(Mp[2])
                {
                    system("cls");
                    cout << "No puedes jugar en el mismo lugar.";
                    continue;
                }
                M[2] = c[b];
                Mp[2] = j + 1;
            }
            else if(sel == conc[cc][3])
            {
                if(Mp[3])
                {
                    system("cls");
                    cout << "No puedes jugar en el mismo lugar.";
                    continue;
                }
                M[3] = c[b];
                Mp[3] = j + 1;
            }
            else if(sel == conc[cc][4])
            {
                if(Mp[4])
                {
                    system("cls");
                    cout << "No puedes jugar en el mismo lugar.";
                    continue;
                }
                M[4] = c[b];
                Mp[4] = j + 1;
            }
            else if(sel == conc[cc][5])
            {
                if(Mp[5])
                {
                    system("cls");
                    cout << "No puedes jugar en el mismo lugar.";
                    continue;
                }
                M[5] = c[b];
                Mp[5] = j + 1;
            }
            else if(sel == conc[cc][6])
            {
                if(Mp[6])
                {
                    system("cls");
                    cout << "No puedes jugar en el mismo lugar.";
                    continue;
                }
                M[6] = c[b];
                Mp[6] = j + 1;
            }
            else if(sel == conc[cc][7])
            {
                if(Mp[7])
                {
                    system("cls");
                    cout << "No puedes jugar en el mismo lugar.";
                    continue;
                }
                M[7] = c[b];
                Mp[7] = j + 1;
            }
            else if(sel == conc[cc][8])
            {
                if(Mp[8])
                {
                    system("cls");
                    cout << "No puedes jugar en el mismo lugar.";
                    continue;
                }
                M[8] = c[b];
                Mp[8] = j + 1;
            }
            else
            {
                system("cls");
                cout << "Estas presionando una tecla incorrecta.";
                continue;
            }

            b = !b;
            j = !j;

            system("cls");

            if(check_win(Mp[0],Mp[1],Mp[2],Mp[3],Mp[4],Mp[5],Mp[6],Mp[7],Mp[8]))
            {
                if(b)
                {
                    if(!IAB)cout << "Has ganado, pero no has vencido mi mejor IA!!!.";
                    else cout << "Me has derrotado completamente, felicidades!!!.";
                    uj = 0;
                }
                else
                {
                    cout << "Has perdido, tal vez me ganes la proxima vez!!!.";
                    uj = 1;
                }
                print_M();
                break;
            }

            if(check_draw(Mp[0],Mp[1],Mp[2],Mp[3],Mp[4],Mp[5],Mp[6],Mp[7],Mp[8]))
            {
                cout << "Creo que tenemos un empate, juegas bien!!!.";
                print_M();
                break;
            }

        }

        cout << '\n' << "Quieres jugar de nuevo si('1') o no('2')?: ";

        el = getch();

        system("cls");

        if(el == '1')continue;
        else break;

    }

    cout << "Gracias por jugar conmigo \"Cero o Cruz\", nos vemos luego." << '\n' << '\n';
    cout << "Juego creado por Brayan Duran Medina: Habana-Cuba / 2017.";

    system("pause > nul");

    return 0;
}
