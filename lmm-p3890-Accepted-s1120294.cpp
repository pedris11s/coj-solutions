#include <bits/stdc++.h>

using namespace std;


typedef long long LL;

const LL MAX = 1e18;

vector <LL> B, TA;

int main(){

    ios_base::sync_with_stdio(0);cin.tie(0);


    B.push_back(1);
    B.push_back(1);
    TA.push_back(0);
    TA.push_back(1);
    for(int i = 2; ; i++){
        LL v = B[i - 1] + 4 * (i - 1);
        B.push_back(v);
        v = TA[i - 1] + v;
        //if(v < 0)
        //    cout << "PEDRO ES UN COMEMIERDA\n";
        if(v > MAX)
            break;
        TA.push_back(v);
    }

    /*cout << TA.size() << "\n";

    for(int i = TA.size() - 10; i < TA.size(); i++)

        cout <<  i << ") " << B[i] << " " << TA[i] << "\n";*/

    LL n;
    cin >> n;

    int p = lower_bound(TA.begin(), TA.end(), n) - TA.begin();
    if(TA[p] != n)
        p--;
    cout << p << "\n";



    return 0;
}
