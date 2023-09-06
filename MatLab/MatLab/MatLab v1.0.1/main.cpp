#include <bits/stdc++.h>
#include "function.h"

using namespace std;

string select;
string selecthelp;
bool siz;
bool sizhelp;

void subst(string &str)
{
    while(str.size() && (str.substr(0,1) == " " || str.substr(0,1) == "\t"))
    {
        str.erase(0,1);
    }

    while(str.size() && (str.substr(str.size()-1,1) == " " || str.substr(str.size()-1,1) == "\t"))
    {
        str.erase(str.size()-1,1);
    }

    return;
}

void convert(string &str)
{
    for(int i = 0 ; i < str.size() ; i++)
    {
        str[i] = tolower(str[i]);
    }

    return;
}

int main()
{
    system("color 6e");

    cout << "Consola MatLab [Version 1.0.1](Teclea \"ayuda\" o \"creditos\" para mas informacion)\n\n";

    cout << ">>> ";

    while(getline(cin,select))
    {

        if(select.size())siz = 1;
        else siz = 0;

        subst(select);
        convert(select);

        if(select == "" && siz)
        {
            cout << "... ";
            continue;
        }
        else if(select == "at")
        {
            area_del_triangulo();
        }
        else if(select == "ec")
        {
            ecuacion_cuadratica();
        }
        else if(select == "rf")
        {
            ruffini();
        }
        else if(select == "an")
        {
            angulos_notables();
        }
        else if(select == "rt")
        {
            resolver_triangulo();
        }
        else if(select == "fp")
        {
            factorizar_polinomio();
        }
        else if(select == "creditos")
        {
            cout << '\n' << "    Gracias a Code::Blocks, \"How to Program in C++, por Deitel\", y un gran";
            cout << '\n' << "    saludos a mis entrenadores. Creado por Brayan Duran Medina.";
            cout << '\n' << '\n';
        }
        else if(select == "ayuda")
        {
            cout << '\n' << "Usa \"ayuda()\" para abrir el menu de ayuda interactiva." << '\n' << '\n';
        }
        else if(select == "ayuda()")
        {
            cout << '\n' << "Bienvenido a MatLab 1.0! Este es el menu de ayuda interactiva." << '\n';
            cout << '\n' << "Si esta es tu primera vez usando MatLab, tu deberias conocer";
            cout << '\n' << "las funciones principales escribiendo en la consola de ayuda el";
            cout << '\n' << "comando \"funciones\"." << '\n';
            cout << '\n' << "Si tu en este momento conoces alguna funcion y necesitas";
            cout << '\n' << "saber mas de ella, tu puedes escribir en la consola de ayuda su";
            cout << '\n' << "comando especificado en los parentesis a su lado y de esta forma";
            cout << '\n' << "puedes conocer mas informacion sobre esta funcion." << '\n';
            cout << '\n' << "Para quitar el menu de ayuda interactiva y retornar a la Consola";
            cout << '\n' << "MatLab, sencillamente teclea \"quitar\" o presiona la tecla \"enter\"." << '\n' << '\n';
            cout << "ayuda> ";

            while(getline(cin,selecthelp))
            {

                if(selecthelp.size())sizhelp = 1;
                else sizhelp = 0;

                subst(selecthelp);
                convert(selecthelp);

                if((selecthelp == "" && !sizhelp) || selecthelp == "quitar")
                {
                    cout << '\n' << "Tu estas ahora dejando el menu de ayuda y retornando a la Consola MatLab." << '\n' << '\n';
                    break;
                }
                else if(selecthelp == "funciones")
                {
                    cout << '\n' << "area_del_triangulo (\"at\").";
                    cout << '\n' << "ecuacion_cuadratica (\"ec\").";
                    cout << '\n' << "ruffini (\"rf\").";
                    cout << '\n' << "angulos_notables (\"an\").";
                    cout << '\n' << "resolver_triangulo (\"rt\").";
                    cout << '\n' << "factorizar_polinomio (\"fp\").";
                    cout << '\n';
                }
                else if(selecthelp == "at")
                {
                    area_del_trianguloAYUDA();
                }
                else if(selecthelp == "ec")
                {
                    ecuacion_cuadraticaAYUDA();
                }
                else if(selecthelp == "rf")
                {
                    ruffiniAYUDA();
                }
                else if(selecthelp == "an")
                {
                    angulos_notablesAYUDA();
                }
                else if(selecthelp == "rt")
                {
                    resolver_trianguloAYUDA();
                }
                else if(selecthelp == "fp")
                {
                    factorizar_polinomioAYUDA();
                }
                else if(selecthelp != "")
                {
                    cout << '\n' << "MatLab no encuentra documentacion para '" << selecthelp << "'." << '\n' ;
                }

                cout << '\n' << "ayuda> ";
            }
        }
        else if(select == "salir")
        {
            cout << '\n' << "Usa \"salir()\" o \"Ctrl-Z\" para salir del programa." << '\n' << '\n';
        }
        else if(select == "salir()")
        {
            return 0;
        }
        else if(select != "")
        {
            cout << '\n' << "Error (ultimo comando mas reciente):" << '\n';
            cout << "Comando incorrecto: '" << select << "' no esta definido." << '\n' << '\n';
        }

        cout << ">>> ";

    }

}
