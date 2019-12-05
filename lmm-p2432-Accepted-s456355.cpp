#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long huge;

double A[100001];

int main()
{
    int n;
    while(cin >> n)
    {
        if(n == 0)
            break;

        for(int i = 0; i < n; i++)
            cin >> A[i];

        sort(A, A + n);
        if(n & 1)
            printf("%.1lf\n", A[n / 2]);
        else
            printf("%.1lf\n", (A[n / 2] + A[n / 2 - 1]) / 2);
    }

    return 0;
}
