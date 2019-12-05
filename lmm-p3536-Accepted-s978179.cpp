#include <cstdio>
#include <map>
#include <cassert>

#define forn(i, n) for (int i = 0; i < int(n); ++i)

using namespace std;

const int N = 1000;

map <int, int> cnt;
int ans[N];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int n;
    scanf("%d", &n);

    forn(i, n * n) {
        int a;
        scanf("%d", &a);
        cnt[-a]++;
    }

    int pos = n - 1;

    for (map <int, int> :: iterator it = cnt.begin(); it != cnt.end(); ++it) {
        int x = -it->first;

        while (it->second) {
            ans[pos] = x;
            --it->second;

            for (int i = pos + 1; i < n; ++i)
                cnt[-gcd(ans[pos], ans[i])] -= 2;

            pos--;
        }
    }

    forn(i, n)
        printf("%d ", ans[i]);
    return 0;
}