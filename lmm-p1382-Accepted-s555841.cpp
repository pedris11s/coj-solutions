#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const LL MAXN = 1000007;

LL cubes[MAXN];
LL ta[MAXN];

int main()
{
    for(LL i = 1; i < MAXN; i++)
        cubes[i] = (LL)i * i * i;

    for(LL i = 1; i < MAXN; i++)
        ta[i] = (LL)(ta[i - 1] + cubes[i]) % MAXN;

    /*for(int i = 1; i <= 5; i++)
        cout << i << ") " << cubes[i] << endl;*/

    int t;
    cin >> t;
    while(t--)
    {
        LL a, b;
        cin >> a >> b;

        int ind_a = lower_bound(cubes, cubes + MAXN, a) - cubes;
        int ind_b = upper_bound(cubes, cubes + MAXN, b) - cubes;

        //cout << ind_a << ' ' << ind_b << endl;
        cout << (ta[ind_b - 1] - ta[ind_a - 1] + MAXN) % MAXN << endl;
    }


	return 0;
}
