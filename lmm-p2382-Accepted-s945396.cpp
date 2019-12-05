#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
    string N; int B, D;
    cin >> N >> B >> D;

    int sum = 0;
    for(int i = 0; i < N.size(); i++)
        sum = (sum * B + (N[i] - '0')) % D;

    if(sum == 0)
        cout << "YES\n";
    else
        cout << "NO\n";


    return 0;
}
