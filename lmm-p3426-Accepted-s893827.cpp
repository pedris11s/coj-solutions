#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;

typedef long long LL;

/*int A[MAXN], TA[MAXN];

bool is_triangle(LL a, LL b, LL c)
{
    if(a + b > c && a + c > b && b + c > a)
        return true;
    return false;
}*/

LL sum(LL n)
{
    if(n % 2 == 0)return (n / 2) * (n + 1);
    return ((n + 1) / 2) * n;
}
LL sumInt(LL a, LL b)
{
    return sum(b) - sum(a - 1);
}


int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);


    LL a, b, c;
    cin >> a >> b;
    /*c = a + b;
    while(!is_triangle(a, b, c))
        c--;

    LL sum = 0;
    for(LL i = c; i >= 1; i--)
        if(is_triangle(a, b, i)){
            sum += i;
            //cout << i << endl;
        }
        else
            break;
*/
    LL minc = abs(a - b) + 1;
    LL maxc = a + b - 1;

    LL sol = sumInt(minc, maxc);
    cout << sol << "\n";
    //cout << "FAST: " << sol << endl;
    //cout << "BRUTE FORCE: " << sum << "\n";
    //if(sol == sum)
    //    cout << "CORRECTO!!\n";
    //else
    //    cout << "ERROR\n";

    return 0;
}
