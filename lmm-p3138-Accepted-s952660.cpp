#include <bits/stdc++.h>

using namespace std;

int m[107][107];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    //cout << "\n\n\n";
    while(t--){

        int f, c;
        cin >> f >> c;
        for(int i = 0; i < f; i++)
            for(int j = 0; j < c; j++)
                cin >> m[i][j];
        for(int i = 0; i < c; i++)
        {
            for(int j = 0; j < f; j++)
                cout << m[j][i] << " ";
            cout << '\n';
        }
    }

    return 0;
}
