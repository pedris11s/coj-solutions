#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL MAXN = 1000007;
const LL MOD = 1000000009;

LL N, Q;
LL A[MAXN];

struct NODO{
    bool prop;
    LL val, lazy;
    NODO(){}
}ST[4 * MAXN];

void build(LL nod, LL a, LL b){
    if(a == b){
        ST[nod].val = A[a];
        ST[nod].lazy = 1;
        ST[nod].prop = false;
        return;
    }

    LL mid = (a + b) / 2;
    build(2 * nod, a, mid);
    build(2 * nod + 1, mid + 1, b);

    ST[nod].val = ST[2 * nod].val + ST[2 * nod + 1].val;
    ST[nod].val %= MOD;
    ST[nod].lazy = 1;
   // ST[nod].prop = false;
}

void propagate(LL nod, LL a, LL b, LL lazy){
    ST[nod].lazy *= lazy;
    ST[nod].lazy %= MOD;
    ST[nod].val *= lazy;
    ST[nod].val %= MOD;
    ST[nod].prop = true;
}

LL query(LL nod, LL a, LL b, LL x, LL y){
    if(a > y || b < x)
        return 0;

    if(a >= x && b <= y){
        return ST[nod].val;
    }

    LL mid = (a + b) / 2;
    if(ST[nod].prop){
        propagate(2 * nod, a, mid, ST[nod].lazy);
        propagate(2 * nod + 1, mid + 1, b, ST[nod].lazy);
        ST[nod].lazy = 1;
        ST[nod].prop = false;
    }

    LL v1 = query(2 * nod, a, mid, x, y);
    LL v2 = query(2 * nod + 1, mid + 1, b, x, y);
    LL sol = (v1 + v2) % MOD;
    return sol;
}

void update(LL nod, LL a, LL b, LL x, LL y, LL num){
    if(a > y || b < x)
        return;

    if(a >= x && b <= y){
        ST[nod].val *= num;
        ST[nod].val %= MOD;
        ST[nod].lazy *= num;
		ST[nod].lazy %= MOD;
        ST[nod].prop = true;
        return;
    }

    LL mid = (a + b) / 2;
    if(ST[nod].prop){
        propagate(2 * nod, a, mid, ST[nod].lazy);
        propagate(2 * nod + 1, mid + 1, b, ST[nod].lazy);
        ST[nod].lazy = 1;
        ST[nod].prop = false;
    }
    update(2 * nod, a, mid, x, y, num);
    update(2 * nod + 1, mid + 1, b, x, y, num);
    ST[nod].val = ST[2 * nod].val + ST[2 * nod + 1].val;
    ST[nod].val %= MOD;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    while(cin >> N >> Q){

        fill(A + 1, A + N + 1, 0);
        for(LL i = 0; i <= 4 * N + 10; i++){
            ST[i].lazy = 1;
            ST[i].prop = false;
            ST[i].val = 0;
        }

        for(LL i = 1; i <= N; i++)
            A[i] = 1;

        build(1, 1, N);
        /*for(LL i = 1; i <= 2 * N; i++)
            cout << ST[i].val << " ";
        cout << endl;
    */
        while(Q--){
            LL p, a, b, v;
            cin >> p;
            if(p == 0){
                //update
                cin >> a >> b >> v;
                if(a > b)swap(a, b);
                update(1, 1, N, a, b, v);
            }else{
                //query;
                cin >> a >> b;
                if(a > b)swap(a, b);
                cout << query(1, 1, N, a, b) << "\n";
            }
        }
    }

    return 0;
}
