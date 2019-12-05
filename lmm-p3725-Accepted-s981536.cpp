#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        if(a == b)
            cout << 1 << "\n";
        else{
            int mcd = __gcd(a, b);
            int sol = (a * b) / (mcd * mcd);
            cout << sol << "\n";
        }
    }

    return 0;
}
