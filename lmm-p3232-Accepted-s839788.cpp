#include <bits/stdc++.h>

using namespace std;

typedef pair <int, string> par;

par A[115];

int main()
{
    //freopen(".en", "r", stdin);

    int N;
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        int x;string cad;
        cin >> x >> cad;
        A[i] = par(x, cad);
    }

    sort(A, A + N);
    int p = 0, time = 0;
    for(int i = 0; i < N; i++)
        if(A[i].second == "AC")
        {
            time = p * 20 + A[i].first;
            break;
        }
        else
            p++;

    cout << time << endl;


    return 0;
}
