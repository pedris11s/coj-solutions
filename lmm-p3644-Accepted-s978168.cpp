#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXN = 1e7 + 7;
const int MILLON = 1e6 + 7;

vector <int> T;
queue <LL> cola;
LL sol[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    for(int i = 1; i < MAXN; i++){
        LL x = i;
        LL val = x * (x + 1) / 2;

        if(val > MAXN)break;

        T.push_back(val);
        sol[val] = 1;
    }

    for(int i = 0; i < T.size(); i++)
        for(int j = i; j < T.size(); j++)
        {
            LL val = T[i] + T[j];

            if(val > MAXN)break;

            if(sol[val] == 0)
                sol[val] = 2;
        }

    LL n;
    while(cin >> n){
        if(sol[n] != 0)
            cout << sol[n] << "\n";
        else
            cout << "3\n";
    }


    return 0;
}
