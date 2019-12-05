#include <cstdio>
#include <iostream>

using namespace std;

const int MAX = 30;

long long L[MAX];

char sol(int n, int k)
{
    if(n > L[k])
        return sol(n, k + 1);

    if(n <= L[k - 1])
        return sol(n, k - 1);
    n = n - L[k - 1];
    if (n <= k + 3)
        return (n == 1) ? 'm' : 'o';
    n = n - (k + 3);
    return sol(n, k - 1);
}

int main()
{
    L[0] = 3;
    for(long long i = 1; i < 30; i++)
        L[i] = 2 * L[i - 1] + i + 3;

    int n;
    cin >> n;
    cout << sol(n, 0) << endl;

    return 0;
}
