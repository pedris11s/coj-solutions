#include <bits/stdc++.h>

using namespace std;

int F[100000];

int main()
{
    int a, b, c, val = 0, sol = 0, maxi = 0;
    cin >> a >> b >> c;
    for(int i = 1; i <= a; i++)
        for(int j = 1; j <= b; j++)
            for(int k = 1; k <= c; k++){
                int x = i + j + k;
                F[x]++;
                maxi = max(maxi, x);
            }
    for(int i = 1; i <= maxi; i++)
        if(F[i] > val){
            val = F[i];
            sol = i;
        }

    cout << sol << "\n";

    return 0;
}
