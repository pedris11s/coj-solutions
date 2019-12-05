#include <cstdio>
#include <iostream>

using namespace std;

typedef string BN;

BN sum(BN a, BN b){
    BN r = "";
    if (a.length() > b.length())
        swap(a, b);
    while (a.length() < b.length())
        a = "0" + a;
    int llevo = 0;
    for (int i = a.length() - 1 ; i > -1 ; i--){
        int s = (a[i] - '0') + (b[i] - '0') + llevo;
        r = ((char)((s % 10) + '0')) + r;
        llevo = s / 10;
    }
    if (llevo > 0)
        r = ((char)(llevo + '0')) + r;
    return r;
}

int main()
{
    int t;
    cin >> t;
    string num, sol = "0";
    while(t--)
    {
        cin >> num;
        sol = sum(sol, num);
    }
    cout << sol << endl;
    return 0;
}
