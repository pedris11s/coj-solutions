#include <bits/stdc++.h>

//18446744073709551615 (2 ^ 64 - 1)
//5000000000000000000 (5 * 10 ^ 18)

using namespace std;

typedef long long LL;

const LL MAXN = 5 * 1e18 + 7;
const int MAX = 1e5 + 7;

vector <LL> fib;
set <LL> fibsum;
LL N, Q, A[MAX], ABI[MAX];

void update(int i, int x){
    for ( ; i <= N; i += (i & -i))
        ABI[i] += x;
}

LL query(int i) {
    LL sum = 0;
    for ( ; i > 0; i -= (i & -i))
        sum += ABI[i];
    return sum;
}

bool isFibSum(LL val)
{
    if(fibsum.find(val) != fibsum.end())
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    fib.push_back(1LL);
    fib.push_back(1LL);
    for(int i = 2; i <= 91; i++){
        LL f = fib[i - 1] + fib[i - 2];
        //if(f < MAXN)
            fib.push_back(f);
        //else
        //    break;
        //cout << fib[i] << endl;
    }
    //cout << fib.size() << endl;

    for(int i = 0; i < fib.size() - 1; i++)
        for(int j = i + 1; j < fib.size(); j++){
            LL x = (LL)fib[i] + (LL)fib[j];
            //if(x < MAXN){
                fibsum.insert(x);
                //cout << x << endl;
            //}
            //else break;
        }
    fibsum.erase(2LL);

    cin >> N >> Q;
    for(int i = 1; i <= N; i++){
        cin >> A[i];
        if(isFibSum(A[i]))
            update(i, 1LL);
    }

    while(Q--)
    {
        LL tp, i, j;
        cin >> tp >> i >> j;
        if(tp == 1){
            if(i > j)
                swap(i, j);

            LL sol = (LL)query(j) - (LL)query(i - 1);
            cout << sol << "\n";
        }
        else{
            if(isFibSum(j)){
                if(!isFibSum(A[i]))
                    update(i, 1LL);
            }
            else{
                if(isFibSum(A[i]))
                    update(i, -1LL);
            }
            A[i] = j;
        }
    }


    return 0;
}
