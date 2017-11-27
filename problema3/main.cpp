#include <iostream>
using namespace std;
struct element {
    int info;
    float pondere;
};

int split(element elements[], int left, int right)
{
    element el = elements[right], aux, aux_el;
    int i = left, j;
    for(j = left; j <= right; j++)
    {
        if(elements[j].info <= el.info)
        {
            aux_el = elements[j];
            elements[j] = elements[i];
            elements[i] = aux_el;
            i++;
        }

    }
    aux_el = elements[j];
    elements[j] = elements[i];
    elements[i] = aux_el;
    return i;
}
void med(element *elements, int left, int right, int m)
{
    if(m >= 1 &&m <= right - left + 1)
    {
        int pos = split(elements,left,right),i;
        if(pos == right)
            {
                pos = split(elements,left,right);
            }
        float leftSum = 0, rightSum = 0;
        for(i = left; i <= right; i++)
        {
            if(i < pos)
            {
                leftSum+=elements[i].pondere;
            }
            if(i > pos)
            {
                rightSum+= elements[i].pondere;
            }
        }
        if(leftSum < 0.5 && rightSum<= 0.5)
        {
            cout <<"mediana este:"<<elements[pos].info<<"de pondere "<<elements[pos].pondere<<endl;
            return;
        }
        else if(leftSum >= 0.5)
        {
            elements[pos].pondere = rightSum;
            med(elements,left,pos,m);
        }
            else
            {
                elements[pos].pondere += leftSum;
                med(elements,pos,right,m-pos+left-1);
            }
            return;
    }
    return;
}

int main()
{
    int n, mid,i;
    cin >> n;
    mid = n/2;

    element *elements = new element[n+1];
    for(i = 1; i <= n; i++)
        cin >> elements[i].info >> elements[i].pondere;

    med(elements,1,n,mid);
    return 0;
}
