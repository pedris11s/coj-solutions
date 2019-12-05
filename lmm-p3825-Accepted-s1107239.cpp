#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500007;

int IT[MAXN];
bool mk[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    fill(IT, IT + MAXN, 1);
    int cont = 2, last = 1;
    for(int i = 2; i < MAXN; i *= 2){
        last = i;
        IT[i] = cont;
        for(int j = i + i; j < MAXN; j += i){
            IT[j] = cont;
        }
        cont++;
    }

    int N, Q;
    while(cin >> N >> Q){




    /*   for(int i = 1; i <= N; i++)
            cout << i << ") " << IT[i] << "\n";
*/

        int it2 = log2(N) + 1;
        int last2 = 1 << (it2 - 1);/*
        int x = log2(Q) + 1;*/

        //cout << cont - 1 << " " << last << " " << IT[Q] << "\n";
        cout << it2 << " " << last2 << " " << IT[Q] << "\n";
    }
    return 0;
}
