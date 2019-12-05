#include <cstdio>
#include <cstring>

#define mod 1000000007LL

#define MAXN (1 << 10)
#define MAXX (1 << 20)

using namespace std;

typedef long long ll;

int n;
int a[MAXN];

int dp[MAXX];
int add[MAXX];
int fact[MAXX];

inline ll solve() {
    int sum = a[0];

    for (int i = 1; i < n; ++i) {

        add[sum+a[i]-1] ++;
        add[sum] --;
        add[a[i]-1] --;

        sum += a[i];
    }

    ll result = 1LL;
    int current = 0;
    for (int i=sum; i >= 2; --i) {
        current += add[i];
        dp[i] += current;

        if (fact[i] == 0) {
            for (int p=0; p < dp[i]; ++p) {
                result *= (ll) i;
                if (result >= mod)
                    result %= mod;
            }
        } else {
            dp[ i / fact[i] ] += dp[i];
            dp[ fact[i] ] += dp[i];
        }
    }

    return result;
}


inline void read () {
    scanf ("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf ("%d", &a[i]);
}

inline void pre () {
    fact[1] = 1;

    for (int i = 2; i * i < MAXX; ++i)
        if (fact[i] == 0)
            for (int j = i * i; j < MAXX; j += i)
                fact[j] = i;
}

int main () {
    pre ();
    read ();
    printf("%lld\n", solve ());
    return 0;
}