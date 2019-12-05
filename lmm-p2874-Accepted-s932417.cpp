#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;

int G, A;
int TA[MAXN], TG[MAXN];

int main()
{
    cin >> G >> A;

    for(int i = 1; i < MAXN; i++){
        if(__gcd(i, G) == 1)
            TG[i]++;
        if(__gcd(i, A) == 1)
            TA[i]++;
    }
    for(int i = 1; i < MAXN; i++){
        TA[i] += TA[i - 1];
        TG[i] += TG[i - 1];
    }

    int t, anders = 0, garfield = 0;
    cin >> t;
    while(t--)
    {
        int gi, gj, ai, aj, solg, sola;
        cin >> gi >> gj >> ai >> aj;
/*
        int x = 0;
        for(int i = gi; i <= gj; i++)
            if(__gcd(i, G) == 1)
                x++;

        int y = 0;
        for(int i = ai; i <= aj; i++)
            if(__gcd(i, A) == 1)
                y++;

        cout << "BRUTE FORCE " << x << " " << y << endl;
        */
        cin >> sola >> solg;

        int g = TG[gj] - TG[gi - 1];
        int a = TA[aj] - TA[ai - 1];
        //cout << g << " " << a << endl;
        if(g == sola)
            anders += 2;
        else
            anders--;

        if(a == solg)
            garfield += 2;
        else
            garfield--;

    }
    //cout << garfield << " " << anders << endl;

    if(anders == garfield)
        cout << "Draw\n";
    else if(anders > garfield)
        cout << "Anders wins\n";
    else
        cout << "Garfield wins\n";

    return 0;
}
