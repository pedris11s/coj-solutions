#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000;

int sol[10000];

int main()
{
    //freopen(".in", "r", stdin);

    char c;
    while(cin >> c)
    {
        c = tolower(c);
        if(c == 'a')sol[0]++;
        if(c == 'e')sol[1]++;
        if(c == 'i')sol[2]++;
        if(c == 'o')sol[3]++;
        if(c == 'u')sol[4]++;
    }
    for(int i = 0; i < 5; i++)
        cout << sol[i] << ' ';


    /*fib[1] = 1;
    fib[2] = 1;
    for(int i = 3; i <= 9999; i++)
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;

    for(int i = 1; i <=  9999; i++)
        if(fib[i] == 73)
            cout << i << "\n";
/*
    for(int i = 1; i <= 150; i++)
        cout << i << ") " << fib[i] << "\n";
*/
    return 0;
}
