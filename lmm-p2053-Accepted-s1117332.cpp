#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);cin.tie(0);

    while(true){
        int n;
        cin >> n;
        if(n == -1)break;
        int sol = 0;
        for(int i = 0; i <= n; i++){
            for(int j = i; j <= n; j++){
                if(i * j > n)break;
                for(int k = j; k <= n; k++){
                    if(k * j > n || k * i > n) break;
                    if(k * j + k * i + j * i == n)
                        sol++;
                }
            }
        }
        cout << sol << "\n";
    }
    return 0;
}
