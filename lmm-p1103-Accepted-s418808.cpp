#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 7500;

int a[] = {1, 5, 10, 25, 50};
long long sol[MAX];
long long dp[MAX];

int main()
{
    int N = 5, K;

    for(int h = 1; h < MAX; h++)
    {
        dp[0] = 1;
        for(int i = 0; i < N; i++)
            for(int j = a[i]; j <= h; j++)
                dp[j] += dp[j - a[i]];

        sol[h] = dp[h];
        for(int i = 0; i <= h; i++)
            dp[i] = 0;
    }

    while(cin >> K)
        cout << sol[K] << endl;

    return 0;
}
