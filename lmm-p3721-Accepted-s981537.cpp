#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;

ULL fact[25];
map <char, int> freq;

int main()
{
    fact[0] = 1;
    for(ULL i = 1; i <= 20; i++){
        fact[i] = fact[i - 1] * i;
        //cout << fact[i] << endl;
    }


    int k = 1;
    int t;
    cin >> t;
    while(t--){
        freq.clear();

        string cad;
        cin >> cad;
        for(int i = 0; i < cad.size(); i++)
            freq[cad[i]]++;

        ULL sol = fact[cad.size()];
        for(map <char, int> :: iterator it = freq.begin(); it != freq.end(); it++)
            sol /= fact[(*it).second];
        cout <<"Data set " << k++ << ": " <<  sol << "\n";

    }

    return 0;
}
