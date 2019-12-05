#include <bits/stdc++.h>

using namespace std;

long long dp[3];

int main()
{
    int N;
    cin >> N;
    string cad;
    cin >> cad;

    long long sol;
    for(int i = 0; i < N; i++)
        if(cad[i] == 'C')
            dp[0]++;
        else if(cad[i] == 'O')
            dp[1] += dp[0];
        else
            dp[2] += dp[1];

    cout << dp[2] << "\n";


    return 0;
}
