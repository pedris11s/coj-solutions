#include <bits/stdc++.h>

using namespace std;

int Q;
const int MAXN  = 1e7 + 1;
bool cmp[MAXN];
vector<int> P;

void Criba(){
    cmp[1] = cmp[0] = 1;
    for(int i = 4; i < MAXN; i += 2)
        cmp[i] = 1;

    for(int i = 3; i * i < MAXN; i += 2){
        if(!cmp[i]){
            for(int k = i * i; k < MAXN; k += 2 * i)
                cmp[k] = 1;
        }
    }

    P.push_back(2);
    for(int i = 3; i < MAXN; i += 2)
        if(!cmp[i])
            P.push_back(i);
}

bool pal(int n){
    int mirror = 0;
    int aux = n;

    while(aux > 0){
        int d = aux % 10;
        mirror = mirror * 10 + d;
        aux /= 10;
    }
    if(mirror == n)
        return 1;
    return 0;
}

int TA[MAXN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Criba();

    for(int i = 0; i < P.size(); i++)
        if(pal(P[i]))
            TA[P[i]] ++;

    for(int i = 1; i < MAXN; i++)
        TA[i] += TA[i - 1];

    cin >> Q;
    for(int i = 0; i < Q; i++){
        int a, b;

        cin >> a >> b;

        if(a > b)
            swap(a, b);
        cout << TA[b] - TA[a - 1] << '\n';
    }
    return 0;
}