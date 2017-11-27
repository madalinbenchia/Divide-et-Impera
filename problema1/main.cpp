#include <iostream>
#include <string>
#include<cstdlib>
#include<stdio.h>
#include<stdlib.h>
#include <bits/stdc++.h>
#define CMAX 256
using namespace std;
struct Nod
{
    int info;
    Nod *left, *right;
};

bool ok = true;

void construire(Nod *n, char s[CMAX], bool fin)
{
    char s1[CMAX], s2[CMAX];
    if(fin == true)
    {
        n = NULL;
        return ;
    }
    fin = true;
    n -> info = atoi(s);
    cin >> s1;
    if(strcmp(s1,"null"))
    {
        fin = false;
        if(atoi(s1) < n -> info)
            ok = false;
    }
    n -> left = new Nod;
    construire(n -> left, s1,fin);
    cin >> s2;
    if(strcmp(s2,"null"))
    {
        fin = false;
        if(atoi(s2) < n -> info)
            ok = false;
    }
    n -> right = new Nod;
    construire(n -> right, s2, fin);
}

int main()
{
    Nod *n;
    n = new Nod;
    char s[CMAX];
    cin >> s;
    if(strcmp(s,"null"))
        construire(n,s,true);
    else
        construire(n,s,false);
    if(ok)
        cout <<"DA";
    else
        cout <<"NU";
    return 0;
}
