#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e4 + 7;

int N, A[MAXN];
map <int, bool> mk;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> A[i];
        mk[A[i]] = true;
    }

    sort(A + 1, A + 1 + N);
    int q1, q2;
    cin >> q1 >> q2;
    while(q1--)
    {
        int x;
        cin >> x;
        if(!mk[x])
            cout << ":(\n";
        else
            cout << ":)\n";
    }
    while(q2--)
    {
        int x;
        cin >> x;
        cout << A[x] << "\n";
    }




    return 0;
}

