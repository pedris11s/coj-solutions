#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 100005;

int A[MAXN];
int TA[MAXN];

int main()
{
    //freopen("triangles.in", "r", stdin);

    int n;
    while(cin >> n)
    {
        for(int i = 1; i <= n; i++)
            cin >> A[i];

        TA[1] = A[1];
        for(int i = 2; i <= n; i++)
            TA[i] = TA[i - 1] + A[i];

        int arco = TA[n] / 3;
        int sol = 0;
        for(int i = 1; i <= n; i++)
            if(binary_search(TA + 1, TA + n + 1, TA[i] + arco))
                if(binary_search(TA  + 1, TA + n + 1, TA[i] + 2 * arco))
                    sol++;

        cout << sol << endl;
    }

    return 0;
}

