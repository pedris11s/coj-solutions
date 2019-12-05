#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXN = 1e5 + 7;
const int MOD = 1e9 + 7;

int N;
int A[MAXN], abi[MAXN];

void update(int pos, int val){
    for(int i = pos; i <= N; i += (i & -i)){
        abi[i] += val;
        abi[i] %= MOD;
        if(abi[i] < 0)abi[i] += MOD;
    }
}

int query(int pos){
    int sum = 0;
    for(int i = pos; i > 0; i -= (i & -i)){
        sum += abi[i];
        sum %= MOD;
        if(sum < 0)sum += MOD;
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N;

    for(int i = 1; i < N; i++){
        cin >> A[i];
    }

    reverse(A + 1, A + N);

    if(A[1] == 0){
        cout << 0 << "\n";
        return 0;
    }

    update(2, 1);
    update(2 + A[1], -1);

    //cout << query(N) << "\n";

    for(int i = 2; i < N; i++){

        int sum = query(i);
        //cout << i << " " << sum << "\n";

        update(i + 1, sum);
        update(i + A[i] + 1, -sum);
    }
    cout << query(N) << "\n";


    return 0;
}
