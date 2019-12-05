#include <bits/stdc++.h>

using namespace std;

string S;

int main()
{
    cin >> S;

    cout << S << '\n';

    int Y = count(S.begin(), S.end(), '1');

    do{
        bitset<20> X = Y;
        S = X.to_string();
        int pos = S.find('1');
        S = S.substr(pos);
        cout << S << '\n';
        Y = X.count();
    }while(Y > 1);

    return 0;
}
