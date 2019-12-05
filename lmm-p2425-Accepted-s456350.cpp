#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long huge;

const int MAX = 245001;

typedef pair <int, int> par;

par A[MAX];

bool mycomp(const par &X, const par &Y)
{
    double x = ((double)X.second) * ((double)log2(X.first));
    double y = ((double)Y.second) * ((double)log2(Y.first));

    if(x <= y)
        return true;
    return false;
}

int main()
{
    //freopen("d.in", "r", stdin);

    int n;
    while(cin >> n)
    {
        if(n == 0)
            break;

        for(int i = 0; i < n; i++)
            cin >> A[i].first >> A[i].second;

        int ind = max_element(A, A + n, mycomp) - A;
        cout << A[ind].first << ' ' << A[ind].second << endl;
    }

    return 0;
}
