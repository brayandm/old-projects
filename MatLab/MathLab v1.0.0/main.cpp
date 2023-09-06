#include <bits/stdc++.h>
#include "function.cpp"

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

}

void convert(string &str)
{

    for(int i = 0 ; i < str.size() ; i++)
    {
        str[i] = tolower(str[i]);
    }

}

int main()
{
    system("color 6e");

    cout << "MathLab Console [Version 1.0.0] (Type \"help\" or \"credits\" for more information)\n\n";

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
        else if(select == "ta"){
            area_triangle();
        }
        else if(select == "qe"){
            eq_squared();
        }
        else if(select == "rf"){
            ruffini();
        }
        else if(select == "na"){
            not_angle();
        }
        else if(select == "ts"){
            sol_triangle();
        }
        else if(select == "fp"){
            fact_polynomial();
        }
        else if(select == "credits")
        {
            cout << '\n' << "    Thanks to Code::Blocks, \"How to Program in C++, by Deitel\" and a cast of";
            cout << '\n' << "    thousands for supporting Durmed development. Create by Brian Duran Medina.";
            cout << '\n' << '\n';
        }
        else if(select == "help")
        {
            cout << '\n' << "Use help() for interactive help" << '\n' << '\n';
        }
        else if(select == "help()")
        {
            cout << '\n' << "Welcome to MathLab 1.0! This is the help utility." << '\n';
            cout << '\n' << "If this is your first time using MathLab, you should know";
            cout << '\n' << "the functions principals writing in the help console the";
            cout << '\n' << "keyword \"functions\"." << '\n';
            cout << '\n' << "If you in this moment know some function and you need to";
            cout << '\n' << "know more of it, your can writing in the help console it";
            cout << '\n' << "keyword specify in the brackets to his side and appear";
            cout << '\n' << "information about this function." << '\n';
            cout << '\n' << "For to quit this help utility and return to the MathLab";
            cout << '\n' << "console, just type \"quit\" or push the key \"enter\"." << '\n' << '\n';
            cout << "help> ";

            while(getline(cin,selecthelp))
            {

                if(selecthelp.size())sizhelp = 1;
                else sizhelp = 0;

                subst(selecthelp);
                convert(selecthelp);

                if((selecthelp == "" && !sizhelp) || selecthelp == "quit")
                {
                    cout << '\n' << "You are now leaving help and returning to the MathLab console." << '\n' << '\n';
                    break;
                }
                else if(selecthelp == "functions"){
                    cout << '\n' << "area_triangle (\"ta\").";
                    cout << '\n' << "equation_squared (\"qe\").";
                    cout << '\n' << "ruffini (\"rf\").";
                    cout << '\n' << "not_angle (\"na\").";
                    cout << '\n' << "sol_triangle (\"ts\").";
                    cout << '\n' << "fact_polynomial (\"fp\").";
                    cout << '\n';
                }
                else if(selecthelp == "ta"){
                    area_triangleHELP();
                }
                else if(selecthelp == "qe"){
                    eq_squaredHELP();
                }
                else if(selecthelp == "rf"){
                    ruffiniHELP();
                }
                else if(selecthelp == "na"){
                    not_angleHELP();
                }
                else if(selecthelp == "ts"){
                    sol_triangleHELP();
                }
                else if(selecthelp == "fp"){
                    fact_polynomialHELP();
                }
                else if(selecthelp != "")
                {
                    cout << '\n' << "No MathLab documentation found for '" << selecthelp << "'" << '\n' ;
                }

                cout << '\n' << "help> ";
            }
        }
        else if(select == "exit")
        {
            cout << '\n' << "Use exit() or Ctrl-Z plus Return to exit" << '\n' << '\n';
        }
        else if(select == "exit()")
        {
            return 0;
        }
        else if(select != "")
        {
            cout << '\n' << "Error (most recent call last):" << '\n';
            cout << "NameIncorrect: name '" << select << "' is not defined" << '\n' << '\n';
        }

        cout << ">>> ";

    }

}
