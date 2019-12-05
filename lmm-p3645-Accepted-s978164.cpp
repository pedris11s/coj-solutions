#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1007;

int mk[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int a, c, m, x;
    while(cin >> a >> c >> m >> x){

        fill(mk, mk + MAXN, 0);
        //cout << x << endl;
        int cont = 1;
        mk[x] = cont;
        int unavez = 0;
        while(true){
            int xn = (a * x + c) % m;
            if(mk[xn] != 0){
                unavez = mk[xn] - 1;
                break;
            }
            cont++;
            mk[xn] = cont;
            //cout << xn << endl;
            x = xn;
        }
        if(cont >= m)
            cout << "YES ";
        else
            cout << "NO ";

        cout << cont  << " " << unavez << " " << cont - unavez << "\n";
    }

    return 0;
}
