//by pter

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

const string C[] = { "MechaGodzilla", "Godzilla" };

int sa, sb;
int a, b;
int ng, nm;

vector <int> god;
vector <int> mgod;

int main()
{

    int t;
    cin >> t;
    while(t--)
    {
        cin >> ng >> nm;

        god.clear();
        for(int i = 0 ; i < ng ; i++)
        {
            cin >> a;
            god.push_back(a);
        }

        mgod.clear();
        for(int i = 0 ; i < nm ; i++)
        {
            cin >> a;
            mgod.push_back(a);
        }

        sort(god.begin(), god.end());
        sort(mgod.begin(), mgod.end());

        a = 0, b = 0;
        while(a < ng && b < nm)
        {
            sa = god[a];
            sb = mgod[b];
            if(sa < sb)
                a++;
            else
                b++;
        }
        cout << C[a != ng] << endl;
    }
    return 0;
}
