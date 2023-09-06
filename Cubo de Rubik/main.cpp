#include <bits/stdc++.h>
#include <conio.h>

using namespace std;

struct face
{
    int A[3][3];
};

struct cord
{
    char f;
    char c;
    int x, y;
};

char selmov;

cord mov[5][5];

map <char,face> cube;

char color[] = {'0','1','2','3','4','5'};

char faces[] = {'U','D','F','B','R','L'};

void cube_init()
{

    for(int s = 0 ; s < 6 ; s++)
    {
        for(int i = 0 ; i < 3 ; i++)
        {
            for(int j = 0 ; j < 3 ; j++)
            {
                cube[faces[s]].A[i][j] = color[s];
            }
        }
    }

}

void cube_print()
{

    cout << '\n';
    cout << "       "<< (char)cube['U'].A[0][2] <<"             "<< (char)cube['L'].A[0][2] <<"   "<< (char)cube['B'].A[0][0] <<"      " << '\n';
    cout << "     "<< (char)cube['U'].A[0][1] <<"   "<< (char)cube['U'].A[1][2] <<"         "<< (char)cube['L'].A[0][1] <<" "<< (char)cube['L'].A[1][2] <<"   "<< (char)cube['B'].A[1][0] <<" "<< (char)cube['B'].A[0][1] <<"    " << '\n';
    cout << "   "<< (char)cube['U'].A[0][0] <<"   "<< (char)cube['U'].A[1][1] <<"   "<< (char)cube['U'].A[2][2] <<"     "<< (char)cube['L'].A[0][0] <<" "<< (char)cube['L'].A[1][1] <<" "<< (char)cube['L'].A[2][2] <<"   "<< (char)cube['B'].A[2][0] <<" "<< (char)cube['B'].A[1][1] <<" "<< (char)cube['B'].A[0][2] <<"  " << '\n';
    cout << "     "<< (char)cube['U'].A[1][0] <<"   "<< (char)cube['U'].A[2][1] <<"       "<< (char)cube['L'].A[1][0] <<" "<< (char)cube['L'].A[2][1] <<"       "<< (char)cube['B'].A[2][1] <<" "<< (char)cube['B'].A[1][2] <<"  " << '\n';
    cout << " "<< (char)cube['F'].A[0][0] <<"     "<< (char)cube['U'].A[2][0] <<"     "<< (char)cube['R'].A[0][2] <<"   "<< (char)cube['L'].A[2][0] <<"     "<< (char)cube['D'].A[0][2] <<"     "<< (char)cube['B'].A[2][2] <<"  " << '\n';
    cout << " "<< (char)cube['F'].A[1][0] <<" "<< (char)cube['F'].A[0][1] <<"       "<< (char)cube['R'].A[0][1] <<" "<< (char)cube['R'].A[1][2] <<"       "<< (char)cube['D'].A[0][1] <<"   "<< (char)cube['D'].A[1][2] <<"      " << '\n';
    cout << " "<< (char)cube['F'].A[2][0] <<" "<< (char)cube['F'].A[1][1] <<" "<< (char)cube['F'].A[0][2] <<"   "<< (char)cube['R'].A[0][0] <<" "<< (char)cube['R'].A[1][1] <<" "<< (char)cube['R'].A[2][2] <<"     "<< (char)cube['D'].A[0][0] <<"   "<< (char)cube['D'].A[1][1] <<"   "<< (char)cube['D'].A[2][2] <<"    " << '\n';
    cout << "   "<< (char)cube['F'].A[2][1] <<" "<< (char)cube['F'].A[1][2] <<"   "<< (char)cube['R'].A[1][0] <<" "<< (char)cube['R'].A[2][1] <<"         "<< (char)cube['D'].A[1][0] <<"   "<< (char)cube['D'].A[2][1] <<"      " << '\n';
    cout << "     "<< (char)cube['F'].A[2][2] <<"   "<< (char)cube['R'].A[2][0] <<"             "<< (char)cube['D'].A[2][0] <<"        " << '\n';

}

cord asig(char c, int a, int b)
{

    cord mv;

    mv.f = c;
    mv.c = cube[c].A[a][b];
    mv.x = a;
    mv.y = b;

    return mv;

}

void rasgSA(int a1, int b1)
{

    cube[mov[a1][b1].f].A[mov[a1][b1].x][mov[a1][b1].y] = mov[b1][4-a1].c;

}

void rasgSH(int a1, int b1)
{

    cube[mov[a1][b1].f].A[mov[a1][b1].x][mov[a1][b1].y] = mov[4-b1][a1].c;

}

void rallSA()
{

    for(int i = 1 ; i < 4 ; i++)
    {
        rasgSA(0,i);
        rasgSA(4,i);
    }

    for(int i = 1 ; i < 4 ; i++)
    {
        for(int j = 0 ; j < 5 ; j++)
        {
            rasgSA(i,j);
        }
    }

}


void rallSH()
{

    for(int i = 1 ; i < 4 ; i++)
    {
        rasgSH(0,i);
        rasgSH(4,i);
    }

    for(int i = 1 ; i < 4 ; i++)
    {
        for(int j = 0 ; j < 5 ; j++)
        {
            rasgSH(i,j);
        }
    }

}

void RallSA()
{

    for(int i = 1 ; i < 4 ; i++)
    {
        rasgSA(0,i);
        rasgSA(4,i);
    }

    for(int i = 1 ; i < 4 ; i++)
    {
        rasgSA(i,0);
        rasgSA(i,4);
    }

}

void RallSH()
{

    for(int i = 1 ; i < 4 ; i++)
    {
        rasgSH(0,i);
        rasgSH(4,i);
    }

    for(int i = 1 ; i < 4 ; i++)
    {
        rasgSH(i,0);
        rasgSH(i,4);
    }

}

void cube_move_u()
{

    for(int i = 1 ; i < 4 ; i++)
    {
        mov[0][i] = asig('L',0,i-1);
        mov[4][i] = asig('R',0,i-1);
    }

    for(int i = 1 ; i < 4 ; i++)
    {
        for(int j = 1 ; j < 4 ; j++)
        {
            mov[i][j] = asig('U',i-1,j-1);
        }
    }

    for(int i = 1 ; i < 4 ; i++)
    {
        mov[i][0] = asig('F',0,i-1);
        mov[i][4] = asig('B',0,i-1);
    }

    rallSA();

}

void cube_move_U()
{

    for(int i = 1 ; i < 4 ; i++)
    {
        mov[0][i] = asig('L',0,i-1);
        mov[4][i] = asig('R',0,i-1);
    }

    for(int i = 1 ; i < 4 ; i++)
    {
        for(int j = 1 ; j < 4 ; j++)
        {
            mov[i][j] = asig('U',i-1,j-1);
        }
    }

    for(int i = 1 ; i < 4 ; i++)
    {
        mov[i][0] = asig('F',0,i-1);
        mov[i][4] = asig('B',0,i-1);
    }

    rallSH();

}

void cube_move_r()
{
    for(int i = 1 ; i < 4 ; i++)
    {
        mov[0][i] = asig('U',2,i-1);
        mov[4][i] = asig('D',2,i-1);
    }

    for(int i = 1 ; i < 4 ; i++)
    {
        for(int j = 1 ; j < 4 ; j++)
        {
            mov[i][j] = asig('R',i-1,j-1);
        }
    }

    for(int i = 1 ; i < 4 ; i++)
    {
        mov[i][0] = asig('F',i-1,2);
        mov[i][4] = asig('B',i-1,2);
    }

    rallSA();

}

void cube_move_R()
{

    for(int i = 1 ; i < 4 ; i++)
    {
        mov[0][i] = asig('U',2,i-1);
        mov[4][i] = asig('D',2,i-1);
    }

    for(int i = 1 ; i < 4 ; i++)
    {
        for(int j = 1 ; j < 4 ; j++)
        {
            mov[i][j] = asig('R',i-1,j-1);
        }
    }

    for(int i = 1 ; i < 4 ; i++)
    {
        mov[i][0] = asig('F',i-1,2);
        mov[i][4] = asig('B',i-1,2);
    }

    rallSH();

}

void cube_move_f()
{
    for(int i = 1 ; i < 4 ; i++)
    {
        mov[0][i] = asig('U',i-1,0);
        mov[4][i] = asig('D',i-1,0);
    }

    for(int i = 1 ; i < 4 ; i++)
    {
        for(int j = 1 ; j < 4 ; j++)
        {
            mov[i][j] = asig('F',i-1,j-1);
        }
    }

    for(int i = 1 ; i < 4 ; i++)
    {
        mov[i][0] = asig('L',i-1,0);
        mov[i][4] = asig('R',i-1,0);
    }

    rallSA();

}

void cube_move_F()
{

    for(int i = 1 ; i < 4 ; i++)
    {
        mov[0][i] = asig('U',i-1,0);
        mov[4][i] = asig('D',i-1,0);
    }

    for(int i = 1 ; i < 4 ; i++)
    {
        for(int j = 1 ; j < 4 ; j++)
        {
            mov[i][j] = asig('F',i-1,j-1);
        }
    }

    for(int i = 1 ; i < 4 ; i++)
    {
        mov[i][0] = asig('L',i-1,0);
        mov[i][4] = asig('R',i-1,0);
    }

    rallSH();

}

void cube_move_l()
{

    for(int i = 1 ; i < 4 ; i++)
    {
        mov[0][i] = asig('U',0,3-i);
        mov[4][i] = asig('D',0,3-i);
    }

    for(int i = 1 ; i < 4 ; i++)
    {
        for(int j = 1 ; j < 4 ; j++)
        {
            mov[i][j] = asig('L',i-1,3-j);
        }
    }

    for(int i = 1 ; i < 4 ; i++)
    {
        mov[i][0] = asig('B',i-1,0);
        mov[i][4] = asig('F',i-1,0);
    }

    rallSA();

}

void cube_move_L()
{

    for(int i = 1 ; i < 4 ; i++)
    {
        mov[0][i] = asig('U',0,3-i);
        mov[4][i] = asig('D',0,3-i);
    }

    for(int i = 1 ; i < 4 ; i++)
    {
        for(int j = 1 ; j < 4 ; j++)
        {
            mov[i][j] = asig('L',i-1,3-j);
        }
    }

    for(int i = 1 ; i < 4 ; i++)
    {
        mov[i][0] = asig('B',i-1,0);
        mov[i][4] = asig('F',i-1,0);
    }

    rallSH();

}

void cube_move_b()
{

    for(int i = 1 ; i < 4 ; i++)
    {
        mov[0][i] = asig('U',3-i,2);
        mov[4][i] = asig('D',3-i,2);
    }

    for(int i = 1 ; i < 4 ; i++)
    {
        for(int j = 1 ; j < 4 ; j++)
        {
            mov[i][j] = asig('B',i-1,3-j);
        }
    }

    for(int i = 1 ; i < 4 ; i++)
    {
        mov[i][0] = asig('R',i-1,2);
        mov[i][4] = asig('L',i-1,2);
    }

    rallSA();

}

void cube_move_B()
{

    for(int i = 1 ; i < 4 ; i++)
    {
        mov[0][i] = asig('U',3-i,2);
        mov[4][i] = asig('D',3-i,2);
    }

    for(int i = 1 ; i < 4 ; i++)
    {
        for(int j = 1 ; j < 4 ; j++)
        {
            mov[i][j] = asig('B',i-1,3-j);
        }
    }

    for(int i = 1 ; i < 4 ; i++)
    {
        mov[i][0] = asig('R',i-1,2);
        mov[i][4] = asig('L',i-1,2);
    }

    rallSH();

}

void cube_move_d()
{
    for(int i = 1 ; i < 4 ; i++)
    {
        mov[0][i] = asig('B',2,3-i);
        mov[4][i] = asig('F',2,3-i);
    }

    for(int i = 1 ; i < 4 ; i++)
    {
        for(int j = 1 ; j < 4 ; j++)
        {
            mov[i][j] = asig('D',3-j,3-i);
        }
    }

    for(int i = 1 ; i < 4 ; i++)
    {
        mov[i][0] = asig('R',2,3-i);
        mov[i][4] = asig('L',2,3-i);
    }

    rallSA();

}

void cube_move_D()
{

    for(int i = 1 ; i < 4 ; i++)
    {
        mov[0][i] = asig('B',2,3-i);
        mov[4][i] = asig('F',2,3-i);
    }

    for(int i = 1 ; i < 4 ; i++)
    {
        for(int j = 1 ; j < 4 ; j++)
        {
            mov[i][j] = asig('D',3-j,3-i);
        }
    }

    for(int i = 1 ; i < 4 ; i++)
    {
        mov[i][0] = asig('R',2,3-i);
        mov[i][4] = asig('L',2,3-i);
    }

    rallSH();

}

void cube_move_m()
{

    for(int i = 1 ; i < 4 ; i++)
    {
        mov[0][i] = asig('U',1,i-1);
        mov[4][i] = asig('D',1,i-1);
    }

    for(int i = 1 ; i < 4 ; i++)
    {
        mov[i][0] = asig('F',i-1,1);
        mov[i][4] = asig('B',i-1,1);
    }

    RallSA();

}

void cube_move_M()
{

    for(int i = 1 ; i < 4 ; i++)
    {
        mov[0][i] = asig('U',1,i-1);
        mov[4][i] = asig('D',1,i-1);
    }

    for(int i = 1 ; i < 4 ; i++)
    {
        mov[i][0] = asig('F',i-1,1);
        mov[i][4] = asig('B',i-1,1);
    }

    RallSH();

}

void cube_move_w()
{

    for(int i = 1 ; i < 4 ; i++)
    {
        mov[0][i] = asig('F',1,3-i);
        mov[4][i] = asig('B',1,3-i);
    }

    for(int i = 1 ; i < 4 ; i++)
    {
        mov[i][0] = asig('R',1,i-1);
        mov[i][4] = asig('L',1,i-1);
    }

    RallSA();

}

void cube_move_W()
{

    for(int i = 1 ; i < 4 ; i++)
    {
        mov[0][i] = asig('F',1,3-i);
        mov[4][i] = asig('B',1,3-i);
    }

    for(int i = 1 ; i < 4 ; i++)
    {
        mov[i][0] = asig('R',1,i-1);
        mov[i][4] = asig('L',1,i-1);
    }

    RallSH();

}

void cube_move_v()
{
    for(int i = 1 ; i < 4 ; i++)
    {
        mov[0][i] = asig('U',i-1,1);
        mov[4][i] = asig('D',i-1,1);
    }

    for(int i = 1 ; i < 4 ; i++)
    {
        mov[i][0] = asig('L',i-1,1);
        mov[i][4] = asig('R',i-1,1);
    }

    RallSA();

}

void cube_move_V()
{

    for(int i = 1 ; i < 4 ; i++)
    {
        mov[0][i] = asig('U',i-1,1);
        mov[4][i] = asig('D',i-1,1);
    }

    for(int i = 1 ; i < 4 ; i++)
    {
        mov[i][0] = asig('L',i-1,1);
        mov[i][4] = asig('R',i-1,1);
    }

    RallSH();

}

void cube_move_x()
{

    cube_move_u();
    cube_move_D();
    cube_move_w();

}

void cube_move_X()
{

    cube_move_U();
    cube_move_d();
    cube_move_W();

}

void cube_move_y()
{

    cube_move_r();
    cube_move_L();
    cube_move_m();

}

void cube_move_Y()
{

    cube_move_R();
    cube_move_l();
    cube_move_M();

}

void cube_move_z()
{

    cube_move_f();
    cube_move_B();
    cube_move_v();

}

void cube_move_Z()
{

    cube_move_F();
    cube_move_b();
    cube_move_V();

}

bool cube_check()
{

    for(int s = 0 ; s < 6 ; s++)
    {
        char cl = cube[faces[s]].A[0][0];

        for(int i = 0 ; i < 3 ; i++)
        {
            for(int j = 0 ; j < 3 ; j++)
            {
                if(cube[faces[s]].A[i][j] != cl)return 0;
            }
        }
    }

    return 1;

}

///       1             6   4
///     1   1         6 6   4 4
///   1   1   1     6 6 6   4 4 4
///     1   1       6 6       4 4
/// 3     1     5   6     2     4
/// 3 3       5 5       2   2
/// 3 3 3   5 5 5     2   2   2
///   3 3   5 5         2   2
///     3   5             2


int main()
{

    system("color 8B");

    cube_init();

    while(1)
    {

        cube_print();

        selmov = getch();

        system("cls");

        if(selmov == 'i')
        {
            cube_init();
        }
        else if(selmov == 'r')
        {
            cube_move_r();
        }
        else if(selmov == 'R')
        {
            cube_move_R();
        }
        else if(selmov == 'u')
        {
            cube_move_u();
        }
        else if(selmov == 'U')
        {
            cube_move_U();
        }
        else if(selmov == 'f')
        {
            cube_move_f();
        }
        else if(selmov == 'F')
        {
            cube_move_F();
        }
        else if(selmov == 'l')
        {
            cube_move_l();
        }
        else if(selmov == 'L')
        {
            cube_move_L();
        }
        else if(selmov == 'b')
        {
            cube_move_b();
        }
        else if(selmov == 'B')
        {
            cube_move_B();
        }
        else if(selmov == 'd')
        {
            cube_move_d();
        }
        else if(selmov == 'D')
        {
            cube_move_D();
        }
        else if(selmov == 'm')
        {
            cube_move_m();
        }
        else if(selmov == 'M')
        {
            cube_move_M();
        }
        else if(selmov == 'w')
        {
            cube_move_w();
        }
        else if(selmov == 'W')
        {
            cube_move_W();
        }
        else if(selmov == 'v')
        {
            cube_move_v();
        }
        else if(selmov == 'V')
        {
            cube_move_V();
        }
        else if(selmov == 'x')
        {
            cube_move_x();
        }
        else if(selmov == 'X')
        {
            cube_move_X();
        }
        else if(selmov == 'y')
        {
            cube_move_y();
        }
        else if(selmov == 'Y')
        {
            cube_move_Y();
        }
        else if(selmov == 'z')
        {
            cube_move_z();
        }
        else if(selmov == 'Z')
        {
            cube_move_Z();
        }
        else if(selmov == 'c')
        {
            cout << cube_check();
        }

    }

    return 0;
}
