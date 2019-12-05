#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1007;

int X[MAXN], Y[MAXN];

int main()
{
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> X[i] >> Y[i];

    for(int i = 3; i <= N; i++)
    {
        int v = ((X[i - 1] - X[i - 2]) * (Y[i] - Y[i - 2])) - ((X[i] - X[i - 2]) * (Y[i - 1] - Y[i - 2]));
        //cout << X[i] << ' ' << Y[i] << endl;
        if(v > 0)
            cout << "left\n";
        else if(v < 0)
            cout << "right\n";
        //else
        //    cout << "collinear\n";
    }

    return 0;
}
