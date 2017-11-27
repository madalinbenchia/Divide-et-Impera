#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#define NMAX 1000
using namespace std;
ifstream f("date.in");

struct punct {
    int x,y;
}v[NMAX],w[NMAX];

struct distanta {
    punct a,b;
    long long d;
};

bool comp_x(punct a, punct b)
{
    return a.x < b.x;
}

bool comp_y(punct a, punct b)
{
    return a.y < b.y;
}

distanta dist(punct a, punct b)
{
    distanta d;
    d.a = a;
    d.b = b;
    long long dif_x = (long long)(a.x - b.x );
    long long dif_y = (long long)( a.y - b.y );
    d.d = dif_x * dif_x + dif_y * dif_y ;

    return d;
}

distanta dist_minim(distanta a, distanta b)
{
    if(a.d < b.d)
        return a;
    return b;
}

distanta divide(int st, int dr)
{
    if(dr - st == 1)
            return dist(v[st],v[dr]);
    if(dr - st == 2)
            return dist_minim(dist(v[st],v[st+1]), dist_minim(dist(v[st+1],v[dr]),dist(v[st],v[dr])));

    int m = (st + dr)/2;
    distanta D1 = divide(st,m);
    distanta D2 = divide(m+1,dr);

    distanta d = dist_minim(D1,D2);
    int i,j,k = 0;
    long long eps = ceil(sqrt(d.d));

    for(i = st; i <= dr; i++)
    {
        if(abs(v[i].x - v[m].x) <= eps)
        {
            w[k].x = v[i].x;
            w[k].y = v[i].y;
            k++;
        }
    }
    sort(w,w+k,comp_y);

    for(i = 0; i < k; i++)
        for(j = i + 1; j <= (i+7) && j < k; j++)
            d = dist_minim(d,dist(w[i],w[j]));
    return d;
}
int main()
{
    int n;
    f >> n;

    for(int i = 0; i < n; i++)
            f >> v[i].x >> v[i].y;

    sort(v,v+n,comp_x);
    distanta d = divide(0,n-1);
    cout << fixed << setprecision(6) << sqrt(d.d);
    cout << "\n" << d.a.x << ' ' << d.a.y << '\n';
    cout << d.b.x << ' ' << d.b.y;

    f.close();
    return 0;
}
