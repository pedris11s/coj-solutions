#include <bits/stdc++.h>

using namespace std;

int n, sol, A[100002];

int main(){

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];

    sort (A, A+n);

    for (int i = n - 1; i >= 0; i--)
        sol = max (sol, n - i + A[i] + 1);

    cout << sol << "\n";

    return 0;
}
