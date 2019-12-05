#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

//const LL MAXN = 100;
const LL MAXN = 2e12 + 7;

int main(){

    vector <LL> T;
    T.push_back(1);
    for(int i = 2; ; i++){
        int n = T.size() - 1;
        LL val = T[n] + i;
        if(val > MAXN)
            break;
        T.push_back(val);
        //cout << val << endl;
    }

    LL a, b;
    while(cin >> a >> b){
        if(a == 0 && a == b)break;
        int i = lower_bound(T.begin(), T.end(), a) - T.begin();
        int j = upper_bound(T.begin(), T.end(), b) - T.begin();
        cout << j - i << "\n";
    }



    return 0;
}
