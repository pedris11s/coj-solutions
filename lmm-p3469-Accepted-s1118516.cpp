#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;

int N, Q;
int TA[MAXN], A[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> N;
    for(int i = 0 ; i < N; i++)
        cin >> A[i];

    TA[0] = A[0];
    for(int i = 1; i < N; i++)
        TA[i] += TA[i - 1] + A[i];

    cin >> Q;
    while(Q--){

        int x;
        cin >> x;
        int p = lower_bound(TA, TA + N, x) - TA;
        if(p == N)
            cout << "none\n";
        else
            cout << p + 1 << "\n";
    }


    return 0;
}
