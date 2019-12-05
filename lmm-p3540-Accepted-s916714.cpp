#include <bits/stdc++.h>

using namespace std;

int K;
string cad;
map <string, int> freq;

bool issol(int n)
{
    freq.clear();

    for(int i = 0; i + n <= cad.size(); i++)
        freq[cad.substr(i, n)]++;

    map <string, int> :: iterator it;
    for(it = freq.begin(); it != freq.end(); it++)
        if((*it).second == K)
            return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> K >> cad;

    int x = cad.size();
    bool flag = false;
    while(x)
    {
        if(issol(x)){
            cout << x << "\n";
            flag = true;
            break;
        }
        x--;
    }
    if(!flag)
        cout << "-1\n";
    return 0;
}
