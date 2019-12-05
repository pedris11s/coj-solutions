#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> par;

const int MAXN = 20000;

par A[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int N;
        cin >> N;
        for(int i = 0, a, b; i < N; i++){
            cin >> a >> b;
            A[i] = par(a, b);
        }
        sort(A, A + N);
        bool flag = false;
        for(int i = 1; i < N; i++)
            if(A[i].first <= A[i - 1].second){
                flag = true;
                break;
            }
        if(flag)
            cout << "Conflict\n";
        else
            cout << "No Conflict\n";

    }

    return 0;
}


