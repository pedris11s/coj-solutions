#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    while(cin >> n && n){
        int c = 1, sol = 0;
        while(c * c * c <= n){
            if(n % (c * c * c) == 0)
                sol++;
            c++;
        }
        cout << sol << '\n';
    }



    return 0;
}
