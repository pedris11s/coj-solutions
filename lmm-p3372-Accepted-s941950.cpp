#include <bits/stdc++.h>

using namespace std;

 typedef long long LL;

 vector <LL> p, e;

 void factoriza(LL n)
 {
     p.clear(); e.clear();
     int exp = 0;
     if(n % 2 == 0)
     {
        while(n % 2 == 0)
            exp++, n /= 2;
        p.push_back(2);
        e.push_back(exp);
     }

     for(int i = 3; i * i <= n; i += 2)
        if(n % i == 0)
        {
            exp = 0;
            while(n % i == 0)
                n /= i, exp++;
            p.push_back(i);
            e.push_back(exp);
        }
    if(n > 1){
        p.push_back(n);
        e.push_back(1);
    }
 }

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout << n - 1 << "\n";
    }

    return 0;
}
