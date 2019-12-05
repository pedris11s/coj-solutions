#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int A[107];
int Xs[107], Ys[107];

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen();

    int X, Y;
    cin >> X >> Y;

    int ai;
    for(int i = 0; i < X; i++)
    {
        cin >> ai;
        Xs[ai]++;
    }
    for(int i = 0; i < Y; i++)
    {
        cin >> ai;
        Ys[ai]++;
    }

    /*for(int i = 1; i <= 5; i++)
        cout << Xs[i]<< ' ';
    cout << endl;
    for(int i = 1; i <= 5; i++)
        cout << Ys[i]<< ' ';
    cout << endl;*/

    int u = 0, w = 0, s = 0;
    for(int i = 1; i <= 100; i++)
        if((Xs[i] > 0 && Ys[i] == 0) || (Ys[i] > 0 && Xs[i] == 0))
            w++;
        else if(Xs[i] == 0 && Ys[i] == 0)
            u++;
        else
            s++;

    cout << "Unsolvable: " << u << "\n";
    cout << "Weakly solvable: " << w << "\n";
    cout << "Strongly solvable: " << s << "\n";

    return 0;
}
