#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000;

int sol[MAX + 7];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    for(int a = 1; a <= MAX; a++)
        for(int b = a + 1; b <= MAX; b++)
        {
            int c = (int)(sqrt(a * a + b * b));
            if(c > MAX)break;

            if(c * c == a * a + b * b)
                sol[c]++;
        }
    for(int i = 1; i <= MAX; i++)
        sol[i] += sol[i - 1];

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout <<sol[n] << '\n';
    }

    return 0;
}
