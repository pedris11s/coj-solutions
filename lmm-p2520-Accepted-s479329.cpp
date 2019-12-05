#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int mk[10000];
vector <int> V;
set <int> set1;
set <int> set2;

int main()
{
    //freopen("asd.in", "r", stdin);
    int t;
    cin >> t;

    int N, P, J, F;
    while(t--)
    {
        set1.clear();
        set2.clear();
        V.clear();
        cin >> N >> P >> J >> F;

        fill(mk,mk + N + 1, 0);

        for( int i = 1+P; i <= N; i++ )
            set1.insert(i);

        int a;
        for( int i = 1; i <= J; i++ )
        {
            cin >> a;
            if( set1.find(a) != set1.end() )
                set1.erase(set1.find(a));
            V.push_back(a);
        }

        for( int i = 1; i <= F; i++ )
        {
            cin >> a;
            if(set1.find(a) != set1.end())
                set1.erase(set1.find(a));
            mk[a] = 1;
        }

        cout << set1.size();

        set <int> :: iterator it;
        for( it = set1.begin(); it != set1.end(); it++ )
            cout << ' ' << (*it);

        for( int i = 0; i < J; i++ )
            if( V[i] <= P || mk[V[i]])
                set2.insert(V[i]);

        cout << endl;

        cout << set2.size();
        for( it = set2.begin(); it != set2.end(); it++ )
            cout << ' ' << (*it);
        if( t >= 1 )
            cout << endl;
    }
    return 0;
}
