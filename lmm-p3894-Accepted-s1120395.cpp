#include <bits/stdc++.h>

#define FOR(i,n) for (int i = 0; i < n; i++)
#define FAB(i,np,nr) for (int i = np; i < nr; i++)

#define Complex complex<double>

using namespace std;

const int MAXN  = 2e6 + 5;
typedef long long ll;

Complex step[2][23];

void fft_init() {
    for(int i = 1, M = 2; i <= 22; i++, M <<= 1) {
        step[0][i] = Complex(cos(2 * M_PI / M), sin(2 * M_PI / M));
        step[1][i] = Complex(cos(-2 * M_PI / M), sin(-2 * M_PI / M));
    }
}

Complex a[MAXN];
bool mark[MAXN];//primer polinomio
bool mark2[MAXN];//segund polinomio

void fft(int n, Complex A[], bool paso) {
    int p = __builtin_ctz(n), m, i, j, K;
    Complex w;
    for(i = 0; i < n; ++i)
        a[i] = A[i];
    for(i = 0; i < n; A[i++] = a[m])
        for(m = j = 0; j < p; j++)
            m <<= 1, m |= ((i >> j) & 1);
    for(i = K = 1; i <= p; i++, K <<= 1)
        for(j = 0; j < n; j += K << 1)
            for(w = 1, m = j; m < K + j; m++) {
                Complex t = w * A[m + K];
                A[m + K] = A[m] - t;
                A[m] = A[m] + t;
                w = w * step[paso][i];
            }
    if(paso)
        for(i = 0; i < n; i++)
            A[i].real() /= n, A[i].imag() /= n;
}

Complex A[MAXN], B[MAXN], C[MAXN];

void mult(int nP, ll P[], int nQ, ll Q[], int &nR, ll R[]) {
    nR = nP + nQ;
    while(__builtin_popcount(nR) > 1)
        nR += nR & -nR;
    FOR(i, nP) A[i] = Complex(P[i], 0);
    FOR(i, nQ) B[i] = Complex(Q[i], 0);
    FAB(i, nP, nR) A[i] = Complex(0, 0);
    FAB(i, nQ, nR) B[i] = Complex(0, 0);
    fft(nR, A, 0), fft(nR, B, 0);
    FOR(i, nR)
    C[i] = A[i] * B[i];
    fft(nR, C, 1);
    FOR(i, nR)
    R[i] = round(C[i].real());
}

int N, M, num, nR, degree;
ll P[MAXN], Q[MAXN], R[4 * MAXN];

string AA, BB;
vector <ll> sol;

int solve() {
    nR = 0;
    degree = 1;
    memset(P, 0, sizeof(P));
    memset(Q, 0, sizeof(Q));
    memset(R, 0, sizeof(R));
    P[0] = Q[0] = 1;
    for(int i = 1; i < MAXN; i++)
        if(mark[i] != 0)
            P[i] = Q[i] = 1, degree = i;
    degree++;
    int sol = 0;
    mult(degree, P, degree, Q, nR, R);
    for(int i = 0; i < MAXN; i++)
        if(R[i] && mark2[i])
            sol++;
    return sol;
}

int main(){

    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> N;
    FOR(i, N){
        int v;
        cin >> v;
        mark[v] = true;
    }

    cin >> M;
    FOR(i, M){
        int v;
        cin >> v;
        mark2[v] = true;
    }
    fft_init();
    cout << solve() << "\n";

    return 0;
}
