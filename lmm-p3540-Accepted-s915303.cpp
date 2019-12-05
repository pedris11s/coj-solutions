#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;

const int NB = 4;
const int MAXN = 1e3 + 1;
const ULL PB[NB] = {17, 23, 31, 41};

#define V(c) ((c) - 'a' + 1)

int K, N;
string S;
ULL P[MAXN];
ULL H[MAXN];
ULL BASE;
map<ULL, int> F;

void precalc(){
    BASE = PB[NB - 1]; //randomize if WA

    P[0] = 1ULL;
    for (int i = 1 ; i <= N ; i++){
        P[i] = P[i - 1] * BASE;
        H[i] = H[i - 1] * BASE + V(S[i]);
    }
}

ULL h(int a, int b){
    ULL r = H[b] - H[a - 1] * P[b - a + 1];
    return r;
}

int main()
{
    cin >> K;
    cin >> S;
    N = S.size();
    S = " " + S;

    precalc();

    int sol = -1;
    for (int L = 1 ; L <= N ; L++){
        F.clear();
        for (int j = L ; j <= N ; j++){
            ULL x = h(j - L + 1, j);
            if (F.find(x) == F.end())
                F[x] = 1;
            else
                F[x]++;
        }
        map<ULL, int> :: iterator it;
        for (it = F.begin() ; it != F.end() ; it++){
            int f = (*it).second;
            if (f == K)
                sol = L;
        }
    }

    cout << sol;

    return 0;
}
