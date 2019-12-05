#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

const int MAX = 13000;

int dp[MAX + 1];

int main()
{
    int n, m;
    cin >> n >> m;

    /*for(int k = 1; k <= m; k++)
        cout << k << '\t';
    cout << endl;*/
    for(int i = 0; i < n; i++)
    {
        int w, c;
        cin >> w >> c;
        for(int j = m; j >= w; j--)
        {
            dp[j] = max(dp[j], dp[j - w] + c);
            //for(int k = 1; k <= m; k++)
            //    cout << dp[k] << '\t';
            //cout << endl;
            //system("pause");

        }
    }
    int best = dp[0];
    for(int i = 1; i <= m; i++)
    {
        best = max(best, dp[i]);
        //cout << dp[i] << ' ';
    }
    //cout << endl;

	cout << best << endl;
}
