#include <cstdio>
#include <iostream>

using namespace std;

typedef long long huge;

const int MAXN = 100005;

huge T[MAXN];

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int N, Q;
        cin >> N >> Q;

        for(int i = 1; i <= N; i++)
        {
            cin >> T[i];
            T[i] += T[i - 1];
        }
        while(Q--)
        {
            int a, b;
            cin >> a >> b;
            cout << T[b + 1] - T[a] << endl;
        }
        if(t > 0)
            cout << endl;

    }


    return 0;
}
