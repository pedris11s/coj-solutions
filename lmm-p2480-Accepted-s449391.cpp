#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef pair <int, int> par;
typedef long long huge;

const int MAXN = 100001;

huge X[MAXN], Y[MAXN];
par A[MAXN];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        X[x]++;
        Y[y]++;
        A[i] = par(x, y);
    }
    //sort(A, A + n);
    huge sol = 0;
    for(int i = 0; i < n; i++)
        sol += (X[A[i].first] - 1) * (Y[A[i].second] - 1);

    cout << sol << endl;

    return 0;
}
