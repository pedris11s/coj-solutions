#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int A[] = {1, 3, 5, 6};

int dp[100001];

int main(){
    int n, cas;

    cin >> cas;

    int k = 1;
    while(cas--){
        cin >> n;

        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            dp[i] = (1 << 30);
            for(int j = 0; j < 4; j++){
                if(i - A[j] >= 0){
                    dp[i] = min(dp[i], dp[i - A[j]] + 1);
                }
            }
        }
        cout <<"Case " << k <<": "<< dp[n] << endl;
        k ++;
    }
    return 0;
}
