#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000007;

int A[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int N;
    cin >> N;
    for(int i = 0; i < N ; i++)
        cin >> A[i];

    sort(A, A + N);
    cout << A[0];
    for(int i = 1; i < N; i++)
        cout << "\n"<< A[i];


    return 0;
}
