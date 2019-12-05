#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXN = 1e5 + 7;

vector <int> T; LL sol[MAXN];
queue <LL> cola;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    fill(sol, sol + MAXN, (1 << 30));
    for(int i = 1; i < MAXN; i++){
        LL x = i;
        LL val = x * (x + 1) / 2;

        if(val > MAXN)break;

        T.push_back(val);
        cola.push(val);
        sol[val] = 1;
    }

    /*for(int i = 0; i < 20; i++)
        cout << T[i] << ' ';
    cout << endl << T.size() << endl;*/

    while(!cola.empty()){
        LL num = cola.front();
        cola.pop();

        for(int i = 0; i < T.size(); i++)
        {
            LL nn = num + T[i];
            if(nn > MAXN)break;

            if(sol[num] + 1 < sol[nn]){
                cola.push(nn);
                sol[nn] = sol[num] + 1;
            }
        }
    }

    LL n;
    while(cin >> n){
        cout << sol[n] << "\n";
    }


    return 0;
}
