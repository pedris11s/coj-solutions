#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;

bool crib[MAX];
vector <int> fac;
int t, n, a, b, pos, prim[MAX];

int f(int x) {
    int ret = 0;
    int k = fac.size();
    for(int i = 1; i < (1 << k); i++) {
        int prod = 1, c = 0;
        for(int j = 0; j < k; j++)
            if(i & (1 << j))
                prod *= fac[j], c++;
        if(c & 1)
            ret += x / prod;
        else
            ret -= x / prod;
    }
    return x - ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 4; i < MAX; i += 2)
        crib[i] = true;
    for(int i = 3; i * i < MAX; i += 2)
        if(!crib[i])
            for(int j = i * i; j < MAX; j += 2 * i)
                crib[j] = true;
    prim[pos++] = 2;
    for(int i = 3; i < MAX; i += 2)
        if(!crib[i])
            prim[pos++] = i;

    cin >> t;
    while(t--) {
        cin >> n >> a >> b;
        fac.clear();
        for(int i = 0; prim[i] <= n && i < pos; i++) {
            if(!(n % prim[i])) {
                fac.push_back(prim[i]);
                while(!(n % prim[i]))
                    n /= prim[i];
            }
        }
        if(n != 1)
            fac.push_back(n);
        cout << f(b) - f(a - 1) << "\n";
    }
}