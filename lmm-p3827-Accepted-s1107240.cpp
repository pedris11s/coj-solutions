#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int N, X;
    cin >> N >> X;
    int sol = 0;
    for(int i = 0; i < N; i++){
        int a, b, c;
        cin >> a >> b;
        int val = abs(a - b);

        if(X < val){
            cin >> c;
            sol += c;
        }else
            sol += max(a, b);
    }
    cout << sol << "\n";


    return 0;
}
