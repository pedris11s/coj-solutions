#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXN = 50000000;
const int MAX = 10007;

LL tp[MAX][10];
vector <LL> val, pos;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    for(int i = 0; i < MAX; i++)
        tp[i][0] = 1;

    bool flag = false;
    for(int i = 1; i < MAX && !flag; i++)
        for(int j = 1; j <= 2; j++){
            tp[i][j] = tp[i - 1][j] + tp[i - 1][j - 1];
            if(tp[i][j] > MAXN){
                //cout << i << " " << j << endl;
                flag = true;
                break;
            }
        }
    for(int i = 0; i < MAX; i++)
        if(tp[i][2] != 0){
            val.push_back(tp[i][2]);
            pos.push_back(i - 2);
        }
    sort(val.begin(), val.end());
    /*for(int i = 0; i < 15; i++){
        for(int j = 0; j <= i; j++)
            cout << tp[i][j] << ' ';
        cout << endl;
    }*/
    //(n + k - 1, k - 1)
    //(n + 2, 2)

    int t;
    cin >> t;
    while(t--){
        LL n;
        cin >> n;

        if(binary_search(val.begin(), val.end(), n)){
            int p = lower_bound(val.begin(), val.end(), n) - val.begin();
            cout << pos[p] << "\n";
        }
        else
            cout << "No solution\n";

    }

    return 0;
}
