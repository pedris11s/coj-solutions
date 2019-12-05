#include <cstdio>
#include <iostream>

using namespace std;

typedef long long huge;

const int MOD = 1e9 + 7;

huge cat[2003];

int main()
{
    //cout << MOD << endl;

    cat[0] = 1;
    cat[1] = 1;
    for(int i = 1; i < 2003; i++)
        for(int j = 0; j <= i; j++)
            cat[i + 1] = (cat[i + 1] + cat[j] * cat[i - j]) % MOD;

    int t;
    cin >> t;
    while(t--)
    {
        huge n;
        cin >> n;
        cout << cat[n] << endl;
    }



    return 0;
}
