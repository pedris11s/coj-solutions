#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXN = 1e4 + 7;

int A[MAXN], freq[MAXN];
map <string, int> id;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N;
    cin >> N;

    int x = 1;
    for(int i = 0; i < N; i++)
    {
        string cad;
        cin >> cad;
        sort(cad.begin(), cad.end());

        if(!(id.find(cad) != id.end())){
            id[cad] = x;
            x++;
        }
        A[i] = id[cad];
    }

    for(int i = 0; i < N; i++)
    {
        cout << freq[A[i]] << "\n";
        freq[A[i]]++;
    }
    return 0;
}
