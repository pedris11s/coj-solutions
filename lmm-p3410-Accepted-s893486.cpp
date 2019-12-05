#include <bits/stdc++.h>

using namespace std;

int year[3000];
bool mk[3000];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        year[a] += b;
        mk[a] = true;
    }

    for(int i = 1; i <= 2014; i++)
        if(mk[i])
            cout << i << ' ' << year[i] << "\n";

    return 0;
}
