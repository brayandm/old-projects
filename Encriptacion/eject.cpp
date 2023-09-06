#include <bits/stdc++.h>

using namespace std;

char sys[] = "start krypto.exe";
char read[] = "";

int main()
{
    cin >> read;
    strcat(sys," ");
    strcat(sys,read);
    cin >> read;
    strcat(sys," ");
    strcat(sys,read);
    cin >> read;
    strcat(sys," ");
    strcat(sys,read);
    system(sys);

    return 0;
}
