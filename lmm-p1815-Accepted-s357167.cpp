//by pter

#include <cstdio>
#include <iostream>
#include <set>

using namespace std;

int a[25];
int q[105];

int main()
{
    int n;
    cin >> n;
    set <int> sum;
    set <int>::iterator it;

    sum.insert(0);

    for(int i = 0; i < n; i++)
        cin >> a[i];
    int query;
    cin >> query;
    for(int i = 0; i < query; i++)
        cin >> q[i];

    for(int i = 0; i < n; i++)
    {
        set <int> aux;
        aux.clear();

        for(it = sum.begin(); it != sum.end(); it++)
        {
            int s = a[i] + (*it);
            if( !(sum.find(s) != sum.end()) )
                aux.insert(s);
        }
        for(it = aux.begin(); it != aux.end(); it++)
            sum.insert(*it);
    }
    for(int i = 0; i < query; i++)
    {
        if(sum.find(q[i]) != sum.end())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
