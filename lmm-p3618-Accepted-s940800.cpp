#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cases;
    long long p;
    cin >> cases;
    while(cases--) {
        cin >> p;
        if(p == 3) cout << 12 << "\n";
        else cout << p+3 << "\n";
    }
    return 0;
}