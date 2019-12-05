#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1007;

char CadAux[MAXN];
//string M[MAXN][3];
map <string, int> Freq;

int main()
{
    //freopen(".in", "r", stdin);

    int N;
    cin >> N;
    int sol = 0;
    for(int i = 0; i < N; i++)
    {
        string a, b, c;
        cin >> a >> b >> c;
        vector <string> V;
        V.push_back(a);
        V.push_back(b);
        V.push_back(c);
        sort(V.begin(), V.end());
        string cad = V[0] + " " + V[1] + " " + V[2];
        Freq[cad]++;
        if(Freq[cad] > sol)
            sol = Freq[cad];

        //cout << cad << endl;
    }
    cout << sol << endl;
    return 0;
}

