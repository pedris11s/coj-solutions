#include <bits/stdc++.h>

using namespace std;

int A[107];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> A[i];

    sort(A, A + n);
    int a = 0, b = 0, p = 0, sum = A[n - 1];
    for(int i = n - 2; i > -1; i--){
        if(p & 1)
            b += A[i] + sum;
        else
            a += A[i] + sum;
        sum += A[i];
        p++;
    }
    if(a > b)
        cout << "First\n";
    else if(b > a)
        cout << "Second\n";
    else
        cout << "Tie\n";
    //cout << a << ' ' << b << endl;

    return 0;
}
