#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair <int, int> par;

int a[4];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);

    int h = a[2] * a[2];
    int l1 = a[1] * a[1];
    int l2 = a[0] * a[0];

    if(l1 + l2 == h)
        cout << "rectangulo\n";
    else if(h > l1 + l2)
        cout << "obtusangulo\n";
    else
        cout << "acutangulo\n";

    return 0;
}
