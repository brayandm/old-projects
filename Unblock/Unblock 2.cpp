#include <bits/stdc++.h>

#include <conio.h>

#define db(x) cout << #x ": " << (x) << '\n';

using namespace std;

const int oo = 1e9;

const int MAXT = 50;

const int MAXN = MAXT*2+10;

char tabla[MAXN][MAXN];

int tamanio_fila;

int tamanio_columna;

bool terminar;

bool retornar;

const char color_bloque_principal = '#';

const char color_bloque = 'O';

const char color_puntero = '*';

const char color_marcado = '@';

const char color_filas = '-';

const char color_columnas = '|';

const char color_meta = '+';

struct coordenadas
{
    int x;
    int y;
};

struct bloque
{
    coordenadas p1;
    coordenadas p2;
};

struct estado
{
    vector<bloque> est;
    friend bool operator <(const estado &v1, const estado &v2)
    {
        for(int i = 0 ; i < v1.est.size() ; i++)
        {
            if(v1.est[i].p1.x < v2.est[i].p1.x)return true;
            if(v1.est[i].p1.x > v2.est[i].p1.x)return false;
            if(v1.est[i].p1.y < v2.est[i].p1.y)return true;
            if(v1.est[i].p1.y > v2.est[i].p1.y)return false;
            if(v1.est[i].p2.x < v2.est[i].p2.x)return true;
            if(v1.est[i].p2.x > v2.est[i].p2.x)return false;
            if(v1.est[i].p2.y < v2.est[i].p2.y)return true;
            if(v1.est[i].p2.y > v2.est[i].p2.y)return false;
        }
        return false;
    }
};

struct jugada
{
    int bloque = 0;
    int direccion = 0;
};

estado vect;

coordenadas cord_meta;

void leer_dimensiones_tabla()
{
    cout << "Inserte las dimensiones de la tabla: ";
    cin >> tamanio_fila >> tamanio_columna;
    system("cls");
    return;
}

void llenar_tabla()
{
    for(int i = 0 ; i < tamanio_fila*2+1 ; i++)
    {
        for(int j = 0 ; j < tamanio_columna*2+1 ; j++)
        {
            if(i+1&1)tabla[i][j] = color_filas;
            else if(j+1&1)tabla[i][j] = color_columnas;
        }
    }
    return;
}

void imprimir_tabla()
{
    for(int i = 0 ; i < tamanio_fila*2+1 ; i++)
    {
        for(int j = 0 ; j < tamanio_columna*2+1 ; j++)
        {
            cout << tabla[i][j];
        }
        cout << '\n';
    }
    return;
}

coordenadas leer_coordenadas(int ejex, int ejey, bool bloque_principal)
{
    char movimiento;
    terminar = false;
    retornar = false;
    while(1)
    {
        char temp;
        if(tabla[ejex][ejey] == color_bloque_principal || tabla[ejex][ejey] == color_bloque)
        {
            temp = tabla[ejex][ejey], tabla[ejex][ejey] = color_marcado;
        }
        else tabla[ejex][ejey] = color_puntero;
        system("cls");
        if(bloque_principal)cout << "Inserta el bloque principal: " << '\n';
        else cout << "Inserta los demas bloques: " << '\n';
        imprimir_tabla();
        if(tabla[ejex][ejey] == color_puntero)tabla[ejex][ejey] = ' ';
        else if(tabla[ejex][ejey] == color_marcado)tabla[ejex][ejey] = temp;
        movimiento = getch();
        if(movimiento == 't' || movimiento == 'T')
        {
            terminar = true;
            break;
        }
        if(movimiento == 'r' || movimiento == 'R')
        {
            retornar = true;
            break;
        }
        if(movimiento == ' ' && tabla[ejex][ejey] != color_bloque_principal && tabla[ejex][ejey] != color_bloque)break;
        if(movimiento == 'w' || movimiento == 'W')ejex-=2;
        else if(movimiento == 's' || movimiento == 'S')ejex+=2;
        else if(movimiento == 'a' || movimiento == 'A')ejey-=2;
        else if(movimiento == 'd' || movimiento == 'D')ejey+=2;
        if(ejex < 1)ejex+=2;
        else if(ejex >= tamanio_fila*2)ejex-=2;
        else if(ejey < 1)ejey+=2;
        else if(ejey >= tamanio_columna*2)ejey-=2;
    }
    return {ejex,ejey};
}

bloque completar_bloque(bloque temp, bool bloque_principal)
{
    int ejex = temp.p1.x;
    int ejey = temp.p1.y;
    while(1)
    {
        coordenadas cord = leer_coordenadas(ejex,ejey,bloque_principal);
        if(terminar)
        {
            temp.p2.x = cord.x;
            temp.p2.y = cord.y;
            break;
        }
        if(retornar)
        {
            temp.p2.x = cord.x;
            temp.p2.y = cord.y;
            break;
        }
        if((cord.x == temp.p1.x ^ cord.y == temp.p1.y) && tabla[cord.x][cord.y] != color_bloque_principal && tabla[cord.x][cord.y] != color_bloque)
        {
            bool bandera = true;
            int px1 = temp.p1.x;
            int py1 = temp.p1.y;
            int px2 = cord.x;
            int py2 = cord.y;
            if(px1 > px2)swap(px1,px2), swap(py1,py2);
            if(py1 > py2)swap(px1,px2), swap(py1,py2);
            if(px1 == px2)
            {
                for(int i = py1+1 ; i <= py2-1 ; i++)
                {
                    if(tabla[px1][i] == color_bloque_principal || tabla[px1][i] == color_bloque)bandera = false;
                }
            }
            else
            {
                for(int i = px1+1 ; i <= px2-1 ; i++)
                {
                    if(tabla[i][py1] == color_bloque_principal || tabla[i][py1] == color_bloque)bandera = false;
                }
            }
            if(bandera)
            {
                temp.p2.x = cord.x;
                temp.p2.y = cord.y;
                system("cls");
                break;
            }
        }
        ejex = cord.x;
        ejey = cord.y;
        system("cls");
    }
    return temp;
}

char color(bool bloque_principal)
{
    if(bloque_principal)return color_bloque_principal;
    else return color_bloque;
}

void pintar_bloque(bloque temp, bool bloque_principal)
{
    if(temp.p1.x == temp.p2.x)for(int i = temp.p1.y ; i <= temp.p2.y ; i++)tabla[temp.p1.x][i] = color(bloque_principal);
    else for(int i = temp.p1.x ; i <= temp.p2.x ; i++)tabla[i][temp.p1.y] = color(bloque_principal);
    return;
}

void eliminar_bloque(bloque temp)
{
    if(temp.p1.x == temp.p2.x)
    {
        for(int i = temp.p1.y ; i <= temp.p2.y ; i++)
        {
            if(i+1&1)tabla[temp.p1.x][i] = color_columnas;
            else tabla[temp.p1.x][i] = ' ';
        }
    }
    else
    {
        for(int i = temp.p1.x ; i <= temp.p2.x ; i++)
        {
            if(i+1&1)tabla[i][temp.p1.y] = color_filas;
            else tabla[i][temp.p1.y] = ' ';
        }
    }
    return;
}

coordenadas leer_bloques(int ejex, int ejey)
{
    stack<bloque> pila;
    for(int i = 0 ; i < vect.est.size() ; i++)
    {
        bloque auxiliar = vect.est[i];
        auxiliar.p1.x = (auxiliar.p1.x*2)-1;
        auxiliar.p1.y = (auxiliar.p1.y*2)-1;
        auxiliar.p2.x = (auxiliar.p2.x*2)-1;
        auxiliar.p2.y = (auxiliar.p2.y*2)-1;
        pila.push(auxiliar);
    }
    vect.est.clear();
    while(1)
    {
        terminar = false;
        retornar = false;
        coordenadas cord = leer_coordenadas(ejex,ejey,pila.empty());
        if(terminar)
        {
            ejex = cord.x;
            ejey = cord.y;
            break;
        }
        if(retornar && !pila.empty())
        {
            ejex = cord.x;
            ejey = cord.y;
            bloque eliminar = pila.top();
            pila.pop();
            eliminar_bloque(eliminar);
            continue;
        }
        else if(retornar && pila.empty())continue;
        tabla[cord.x][cord.y] = color(pila.empty());
        bloque temp;
        temp.p1.x = cord.x;
        temp.p1.y = cord.y;
        temp = completar_bloque(temp,pila.empty());
        if(terminar)
        {
            ejex = temp.p2.x;
            ejey = temp.p2.y;
            tabla[temp.p1.x][temp.p1.y] = ' ';
            break;
        }
        if(retornar)
        {
            ejex = temp.p2.x;
            ejey = temp.p2.y;
            tabla[temp.p1.x][temp.p1.y] = ' ';
            continue;
        }
        int tempejex = temp.p2.x;
        int tempejey = temp.p2.y;
        if(temp.p1.x > temp.p2.x)swap(temp.p1.x,temp.p2.x), swap(temp.p1.y,temp.p2.y);
        if(temp.p1.y > temp.p2.y)swap(temp.p1.x,temp.p2.x), swap(temp.p1.y,temp.p2.y);
        pintar_bloque(temp,pila.empty());
        cout << "Unblock" << '\n';
        imprimir_tabla();
        pila.push(temp);
        ejex = tempejex;
        ejey = tempejey;
        system("cls");
    }
    while(!pila.empty())
    {
        bloque auxiliar = pila.top();
        auxiliar.p1.x = (auxiliar.p1.x+1)/2;
        auxiliar.p1.y = (auxiliar.p1.y+1)/2;
        auxiliar.p2.x = (auxiliar.p2.x+1)/2;
        auxiliar.p2.y = (auxiliar.p2.y+1)/2;
        vect.est.push_back(auxiliar);
        pila.pop();
    }
    reverse(vect.est.begin(),vect.est.end());
    return {ejex,ejey};
}

coordenadas leer_meta(int ejex, int ejey)
{
    retornar = false;
    char movimiento;
    while(1)
    {
        char temp;
        temp = tabla[ejex][ejey];
        tabla[ejex][ejey] = color_meta;
        system("cls");
        cout << "Inserta la meta: " << '\n';
        imprimir_tabla();
        tabla[ejex][ejey] = temp;
        movimiento = getch();
        if(movimiento == 'r' || movimiento == 'R')
        {
            retornar = true;
            return {ejex,ejey};
        }
        if(movimiento == ' ' && ((ejex == 1 || ejex == tamanio_fila*2-1) || (ejey == 1 || ejey == tamanio_columna*2-1)))break;
        if(movimiento == 'w' || movimiento == 'W')ejex-=2;
        else if(movimiento == 's' || movimiento == 'S')ejex+=2;
        else if(movimiento == 'a' || movimiento == 'A')ejey-=2;
        else if(movimiento == 'd' || movimiento == 'D')ejey+=2;
        if(ejex < 1)ejex+=2;
        else if(ejex >= tamanio_fila*2)ejex-=2;
        else if(ejey < 1)ejey+=2;
        else if(ejey >= tamanio_columna*2)ejey-=2;
    }
    return {(ejex+1)/2,(ejey+1)/2};
}

map<estado,bool> marcado;

map<estado,jugada> movimiento;

bool arr[MAXT][MAXT];

void llenar_arr()
{
    for(int i = 0 ; i < vect.est.size() ; i++)
    {
        if(vect.est[i].p1.x == vect.est[i].p2.x)
        {
            for(int j = vect.est[i].p1.y ; j <= vect.est[i].p2.y ; j++)arr[vect.est[i].p1.x][j] = true;
        }
        else
        {
            for(int j = vect.est[i].p1.x ; j <= vect.est[i].p2.x ; j++)arr[j][vect.est[i].p1.y] = true;
        }
    }
    return;
}

struct nodo
{
    estado state;
    bool arreglo[MAXT][MAXT];
};

estado fin;

void precalculo(estado mov)
{
    llenar_arr();

    nodo root;

    root.state = mov;

    for(int i = 1 ; i <= tamanio_fila ; i++)
    {
        for(int j = 1 ; j <= tamanio_columna ; j++)
        {
            root.arreglo[i][j] = arr[i][j];
        }
    }

    queue<nodo> Q;

    Q.push(root);

    while(!Q.empty())
    {
        nodo ini = Q.front();
        Q.pop();
        if(marcado[ini.state])continue;
        marcado[ini.state] = true;
        if((ini.state.est[0].p1.x == cord_meta.x && ini.state.est[0].p1.y == cord_meta.y) || (ini.state.est[0].p2.x == cord_meta.x && ini.state.est[0].p2.y == cord_meta.y))
        {
            fin = ini.state;
            break;
        }
        for(int i = 0 ; i < ini.state.est.size() ; i++)
        {
            if(ini.state.est[i].p1.x == ini.state.est[i].p2.x)
            {
                if(!ini.arreglo[ini.state.est[i].p1.x][ini.state.est[i].p1.y-1] && ini.state.est[i].p1.y-1 >= 1)
                {
                    nodo newn;
                    newn.state = ini.state;
                    for(int i = 1 ; i <= tamanio_fila ; i++)
                    {
                        for(int j = 1 ; j <= tamanio_columna ; j++)
                        {
                            newn.arreglo[i][j] = ini.arreglo[i][j];
                        }
                    }
                    newn.arreglo[ini.state.est[i].p1.x][ini.state.est[i].p1.y-1] = true;
                    newn.arreglo[ini.state.est[i].p1.x][ini.state.est[i].p2.y] = false;
                    newn.state.est[i].p1.y--;
                    newn.state.est[i].p2.y--;
                    if(!marcado[newn.state])
                    {
                        movimiento[newn.state].bloque = i;
                        movimiento[newn.state].direccion = 1;
                        Q.push(newn);
                    }
                }
                if(!ini.arreglo[ini.state.est[i].p1.x][ini.state.est[i].p2.y+1] && ini.state.est[i].p2.y+1 <= tamanio_columna)
                {
                    nodo newn;
                    newn.state = ini.state;
                    for(int i = 1 ; i <= tamanio_fila ; i++)
                    {
                        for(int j = 1 ; j <= tamanio_columna ; j++)
                        {
                            newn.arreglo[i][j] = ini.arreglo[i][j];
                        }
                    }
                    newn.arreglo[ini.state.est[i].p1.x][ini.state.est[i].p1.y] = false;
                    newn.arreglo[ini.state.est[i].p1.x][ini.state.est[i].p2.y+1] = true;
                    newn.state.est[i].p1.y++;
                    newn.state.est[i].p2.y++;
                    if(!marcado[newn.state])
                    {
                        movimiento[newn.state].bloque = i;
                        movimiento[newn.state].direccion = -1;
                        Q.push(newn);
                    }
                }
            }
            else
            {
                if(!ini.arreglo[ini.state.est[i].p1.x-1][ini.state.est[i].p1.y] && ini.state.est[i].p1.x-1 >= 1)
                {
                    nodo newn;
                    newn.state = ini.state;
                    for(int i = 1 ; i <= tamanio_fila ; i++)
                    {
                        for(int j = 1 ; j <= tamanio_columna ; j++)
                        {
                            newn.arreglo[i][j] = ini.arreglo[i][j];
                        }
                    }
                    newn.arreglo[ini.state.est[i].p1.x-1][ini.state.est[i].p1.y] = true;
                    newn.arreglo[ini.state.est[i].p2.x][ini.state.est[i].p1.y] = false;
                    newn.state.est[i].p1.x--;
                    newn.state.est[i].p2.x--;
                    if(!marcado[newn.state])
                    {
                        movimiento[newn.state].bloque = i;
                        movimiento[newn.state].direccion = 1;
                        Q.push(newn);
                    }
                }
                if(!ini.arreglo[ini.state.est[i].p2.x+1][ini.state.est[i].p1.y] && ini.state.est[i].p2.x+1 <= tamanio_fila)
                {
                    nodo newn;
                    newn.state = ini.state;
                    for(int i = 1 ; i <= tamanio_fila ; i++)
                    {
                        for(int j = 1 ; j <= tamanio_columna ; j++)
                        {
                            newn.arreglo[i][j] = ini.arreglo[i][j];
                        }
                    }
                    newn.arreglo[ini.state.est[i].p1.x][ini.state.est[i].p1.y] = false;
                    newn.arreglo[ini.state.est[i].p2.x+1][ini.state.est[i].p1.y] = true;
                    newn.state.est[i].p1.x++;
                    newn.state.est[i].p2.x++;
                    if(!marcado[newn.state])
                    {
                        movimiento[newn.state].bloque = i;
                        movimiento[newn.state].direccion = -1;
                        Q.push(newn);
                    }
                }
            }
        }
    }
    return;
}

void reconstruir_tabla(estado mov)
{
    for(int i = 0 ; i < tamanio_fila*2+1 ; i++)
    {
        for(int j = 0 ; j < tamanio_columna*2+1 ; j++)
        {
            tabla[i][j] = ' ';
            if(i+1&1)tabla[i][j] = color_filas;
            else if(j+1&1)tabla[i][j] = color_columnas;
        }
    }
    if(mov.est[0].p1.x == mov.est[0].p2.x)
    {
        for(int i = mov.est[0].p1.y*2-1 ; i <= mov.est[0].p2.y*2-1 ; i++)tabla[mov.est[0].p1.x*2-1][i] = color_bloque_principal;
    }
    else
    {
        for(int i = mov.est[0].p1.x*2-1 ; i <= mov.est[0].p2.x*2-1 ; i++)tabla[i][mov.est[0].p1.y*2-1] = color_bloque_principal;
    }
    for(int i = 1 ; i < mov.est.size() ; i++)
    {
        if(mov.est[i].p1.x == mov.est[i].p2.x)
        {
            for(int j = mov.est[i].p1.y*2-1 ; j <= mov.est[i].p2.y*2-1 ; j++)tabla[mov.est[i].p1.x*2-1][j] = color_bloque;
        }
        else
        {
            for(int j = mov.est[i].p1.x*2-1 ; j <= mov.est[i].p2.x*2-1 ; j++)tabla[j][mov.est[i].p1.y*2-1] = color_bloque;
        }
    }
    return;
}

vector<estado> infor;

void reconstruir_solucion(estado mov, int bl, int di)
{
    if(!movimiento[mov].direccion)
    {
        infor.push_back(mov);
        return;
    }

    int mov_bloque = movimiento[mov].bloque;
    int dir_bloque = movimiento[mov].direccion;

    if(bl != mov_bloque || di != dir_bloque)infor.push_back(mov);

    if(mov.est[mov_bloque].p1.x == mov.est[mov_bloque].p2.x)
    {
        mov.est[mov_bloque].p1.y += dir_bloque;
        mov.est[mov_bloque].p2.y += dir_bloque;
    }
    else
    {
        mov.est[mov_bloque].p1.x += dir_bloque;
        mov.est[mov_bloque].p2.x += dir_bloque;
    }

    reconstruir_solucion(mov,mov_bloque,dir_bloque);
}

int main()
{
    leer_dimensiones_tabla();
    llenar_tabla();
    cord_meta.x = 1;
    cord_meta.y = 1;
    while(1)
    {
        coordenadas temp = leer_bloques(cord_meta.x,cord_meta.y);
        cord_meta = leer_meta(temp.x,temp.y);
        if(!retornar)break;
    }
    precalculo(vect);
    system("cls");
    infor.push_back(fin);
    reconstruir_solucion(fin,movimiento[fin].bloque,movimiento[fin].direccion);
    reverse(infor.begin(),infor.end());
    int i = 0;
    reconstruir_tabla(infor[i]);
    cout << "Solucion:" << '\n';
    imprimir_tabla();
    while(1)
    {
        char mover = getch();
        if(mover == 'a' || mover == 'A')
        {
            if(i > 0)i--;
            else continue;
        }
        if(mover == 'd' || mover == 'D')
        {
            if(i < infor.size()-1)i++;
            else continue;
        }
        if(mover == 't' || mover == 'T')
        {
            break;
        }
        system("cls");
        reconstruir_tabla(infor[i]);
        cout << "Solucion:" << '\n';
        imprimir_tabla();
    }

    return 0;
}
