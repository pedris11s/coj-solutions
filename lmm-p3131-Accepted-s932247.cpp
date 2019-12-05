#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAX = 100005;
const LL MAXN = 5000000000000000007;

LL N, Q, A[MAX], ABI[MAX];
vector <LL> fib;
set<LL> fibsum;

void update(int pos, int val)
{
    for(int i = pos; i <= N; i += (i & -i))
        ABI[i] += val;
}

LL query(int pos)
{
    LL sum = 0;
    for(int i = pos; i > 0; i -= (i & -i))
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
    for(int i = 2; ; i++)
    {
        LL f = fib[i - 1] + fib[i - 2];
        if(f < MAXN)
            fib.push_back(f);
        else
            break;
    }
    for(int i = 0; i < fib.size() - 1; i++)
        for(int j = i + 1; j < fib.size(); j++)
        {
            LL x = fib[i] + fib[j];
            if(x < MAXN)
                fibsum.insert(x);
        }

    fibsum.erase(2LL);

    cin >> N >> Q;
    for(int i = 1; i <= N; i++)
    {
        cin >> A[i];
        if(isFibSum(A[i]))
            update(i, 1);
    }

    while(Q--)
    {
        LL tp, i, j;
        cin >> tp >> i >> j;
        if(tp == 1)
        {
            if(i > j)
                swap(i,j);

            LL sol = query(j) - query(i - 1);
            cout << sol << "\n";
        }
        else{
            if(isFibSum(j)){
                if(!isFibSum(A[i]))
                    update(i, 1);
            }
            else{
                if(isFibSum(A[i]))
                    update(i, -1);
            }
            A[i] = j;
        }
    }

    return 0;
}
