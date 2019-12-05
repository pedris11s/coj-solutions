//by pter

#include <cstdio>
#include <iostream>
#include <set>

using namespace std;

int a[100];

int main()
{
    int n;
    cin >> n;
    set <int> sum;
    set <int>::iterator it;

    sum.insert(0);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int sol = 0;
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
        {
            sum.insert(*it);
            if((*it) % 2 != 0 && (*it) > sol)
                sol = (*it);
        }

    }
    if(sol != 0)
        cout << sol << endl;
    else
        cout << "-1\n";


    return 0;
}
