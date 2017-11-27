#include<iostream>
using namespace std;
#define NMAX
int n,dimen = 1,x,y, m[257][257], piece = 0;

int cautare(int x, int y, int dimensiune)
{
    while(x > dimensiune) x -= dimensiune;
    while(y > dimensiune) y -= dimensiune;
    if(x <= dimensiune/2 && y <= dimensiune/2)
            return 1;
    if(x <= dimensiune/2)
            return 2;
    if(y <= dimensiune/2)
            return 3;
    return 4;
}

void umplere(int x, int y, int dim, int dif_x, int dif_y)
{
    if(dim == 1)
        return;

    if(dim == 2)
    {
        piece++;
        if(x % 2 == 1 && y % 2 == 1)
        {
            m[x+1][y] = piece;
            m[x][y+1] = piece;
            m[x+1][y+1] = piece;
            return;

        }
        if(x % 2 == 1 && y % 2 == 0)
        {
            m[x+1][y] = piece;
            m[x][y-1] = piece;
            m[x+1][y-1] = piece;
            return;
        }
        if(x % 2 == 0 && y % 2 == 1)
        {
            m[x-1][y] = piece;
            m[x][y+1] = piece;
            m[x-1][y+1] = piece;
            return;
        }
        if(x % 2 == 0 && y % 2 == 0)
        {
            m[x-1][y] = piece;
            m[x][y-1] = piece;
            m[x-1][y-1] = piece;
            return;
        }
        return;
    }
    int k = cautare(x,y,dim);
    if(k == 1)
    {
        umplere(x,y,dim/2,dif_x,dif_y);
        umplere(dif_x+dim/2, dif_y+dim/2+1, dim/2,dif_x, dif_y+dim/2);
        umplere(dif_x+dim/2+1, dif_y+dim/2, dim/2,dif_x+dim/2, dif_y);
        umplere(dif_x+dim/2+1, dif_y+dim/2+1, dim/2, dif_x+dim/2, dif_y+dim/2);
        piece++;
        m[dif_x+dim/2][dif_y+dim/2+1] = piece;
        m[dif_x+dim/2+1][dif_y+dim/2] = piece;
        m[dif_x+dim/2+1][dif_y+dim/2+1] = piece;
    }
    if(k == 2)
    {
        umplere(x,y,dim/2,dif_x,dif_y+dim/2);
        umplere(dif_x+dim/2, dif_y+dim/2, dim/2,dif_x,dif_y);
        umplere(dif_x+dim/2+1, dif_y+dim/2, dim/2,dif_x+dim/2,dif_y);
        umplere(dif_x+dim/2+1, dif_y+dim/2+1, dim/2,dif_x+dim/2,dif_y+dim/2);
        piece++;
        m[dif_x+dim/2][dif_y+dim/2] = piece;
        m[dif_x+dim/2+1][dif_y+dim/2] = piece;
        m[dif_x+dim/2+1][dif_y+dim/2+1] = piece;
    }
    if(k == 3)
    {
        umplere(x,y,dim/2,dif_x+dim/2,dif_y);
        umplere(dif_x+dim/2, dif_y+dim/2, dim/2,dif_x,dif_y);
        umplere(dif_x+dim/2, dif_y+dim/2+1, dim/2,dif_x,dif_y+dim/2);
        umplere(dif_x+dim/2+1, dif_y+dim/2+1, dim/2,dif_x+dim/2,dif_y+dim/2);
        piece++;
        m[dif_x+dim/2][dif_y+dim/2] = piece;
        m[dif_x+dim/2][dif_y+dim/2+1] = piece;
        m[dif_x+dim/2+1][dif_y+dim/2+1] = piece;
    }
    if(k == 4)
    {
        umplere(x,y,dim/2,dif_x+dim/2,dif_y+dim/2);
        umplere(dif_x+dim/2, dif_y+dim/2, dim/2,dif_x,dif_y);
        umplere(dif_x+dim/2, dif_y+dim/2+1, dim/2,dif_x,dif_y+dim/2);
        umplere(dif_x+dim/2+1, dif_y+dim/2, dim/2,dif_x+dim/2,dif_y);
        piece++;
        m[dif_x+dim/2][dif_y+dim/2] = piece;
        m[dif_x+dim/2][dif_y+dim/2+1] = piece;
        m[dif_x+dim/2+1][dif_y+dim/2] = piece;
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        dimen = dimen *2;
    cin >> x >> y;

    umplere(x,y,dimen,0,0);

     for (int i = 1; i<=dimen; i++)
    {
        for (int j = 1; j<=dimen; j++)
            cout << m[i][j] << '\t';
    cout << '\n';
    }
    cout << '\n';
    return 0;
}
