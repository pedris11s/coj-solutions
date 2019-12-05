#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        string cad;
        cin >> cad;

        sort(cad.begin(), cad.end());
        do{
            cout << cad << "\n";
        }while(next_permutation(cad.begin(), cad.end()));

    }
    return 0;
}
