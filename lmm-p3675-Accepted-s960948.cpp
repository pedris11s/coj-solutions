#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXN = 30;
const double EPS = 1e-8;

int N;
LL P, B;
LL A[MAXN];
map <LL, int> mk;

LL toLong(string cad)
{
    LL sol = 0;
    for(int i = 0; i < cad.size(); i++)
        if(cad[i] != '.')
            sol = sol * 10 + (cad[i] - '0');
    return sol;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    //cout << toLong("123.44") << endl;

    //scanf("%d%lf%lf", &N, &P, &B);
    string p, b;
    cin >> N >> p >> b;
    P = toLong(p);
    B = toLong(b);
    for(int i = 0; i < N; i++){
        cin >> p;
        A[i] = toLong(p);
    }

    int cont = 0;
    for(int mask = 0; mask < (1 << N); mask++){
        LL sum = 0;
        for(int bit = 0; bit < N; bit++){
            if(mask & (1 << bit))
                sum += A[bit] * 2;
        }
        sum += B;
        if(mk.find(sum) != mk.end());
        else{
            if(sum >= P)
                cont++;
            mk[sum]++;
        }
    }
    if(cont == 0)
        cout << "Strong\n";
    else
        cout << cont << "\n";


    return 0;
}
