#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 7;

int sol[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin >> t;
    while(t--){

        for(int i = 0; i < 5; i++)
            cin >> sol[i];

        bool flag = false;
        for(int i = 0; i < 4; i++)
            if(sol[i] + 1 != sol[i + 1]){
                cout << "N\n";
                flag = true;
                break;
            }
        if(!flag)
            cout << "Y\n";

    }

    return 0;
}
