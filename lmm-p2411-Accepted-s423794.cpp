#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

const int MAX = 100100;
int n, k, A[MAX];
map <string, int> M;

int Dist(int n) {
    int mod = n % 100;
    n /= 100;

    int p = 1 << n;

    return p + ((mod * p) / 100);
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) {
        char s[10];
        int d;

        scanf("%s", &s);
        scanf("%d", &d);

        string ss = s;

        M[ss] = d, A[i] = d;
    }

    sort(A + 1, A + n + 1);
    for(int i = 1; i <= k; i++) {
        char s[10]; int w;
        scanf("%s", &s);
        scanf("%d", &w);

        string ss = s;

        int dp = M[ss];
        int d = Dist(w);

        if(d >= dp && dp > 0) {
            printf("Yes\n");
            continue;
        }

        int p = upper_bound(A + 1, A + n + 1, d) - A;

        if(p > n) p = n;

        if(A[p] > d) p--;

        printf("No %d\n", p);
    }

    return 0;
}