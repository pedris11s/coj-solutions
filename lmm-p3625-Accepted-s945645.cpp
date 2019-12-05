#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5007;
const int MOD = 1e9 + 7;

bool sol[MAXN];
vector <int> F;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    F.push_back(1);
    F.push_back(1);
    //sol[2] = true;
    for(int i = 2; ; i++)
    {
        int x = F[i - 1] + F[i - 2];
        if(x <= 5000){
            sol[x] = true;
            F.push_back(x);
        }
        else
            break;
    }
    //cout << F[F.size() - 1] << "\n";

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        if(sol[n])
            cout << "Harry wins\n";
        else
            cout << "Ron wins\n";
    }
    return 0;
}
