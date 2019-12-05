#include <bits/stdc++.h>

using namespace std;

double kWhToMoney(double n)
{
    double sol = 0; double x = 0;

    if(n > 5000){
        x = n - 5000;
        sol += x * 5.0;
        n -= x;
    }
    if(n <= 5000 && n > 1000){
        x = n - 1000;
        sol += x * 3.0;
        n -= x;
    }
    if(n <= 1000 && n > 500){
        x = n - 500;
        sol += x * 2.0;
        n -= x;
    }
    if(n <= 500 && n > 350){
        x = n - 350;
        sol += x * 1.80;
        n -= x;
    }
    if(n <= 350 && n > 300){
        x = n - 300;
        sol += x * 1.50;
        n -= x;
    }
    if(n <= 300 && n > 250){
        x = n - 250;
        sol += x * 0.80;
        n -= x;
    }

    if(n <= 250 && n > 200){
        x = n - 200;
        sol += x * 0.60;
        n -= x;
    }

    if(n <= 200 && n > 150){
        x = n - 150;
        sol += x * 0.40;
        n -= x;
    }
    if(n <= 150 && n > 100){
        x = n - 100;
        sol += x * 0.30;
        n -= x;
    }
    if(n <= 100){
        x = n;
        sol += x * 0.09;
        //n -= x;
    }

    return sol;
}

int main()
{
    //freopen(".in", "r", stdin);

    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        int ini = 0, fin = 300000, sol;
        while(ini <= fin)
        {
            int mit = (ini + fin) / 2;
            if(kWhToMoney(mit) > n)
                fin = mit - 1;
            else
                ini = mit + 1, sol = mit;
        }
        cout << sol << "\n";
    }
    return 0;
}
