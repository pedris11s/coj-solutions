#include <bits/stdc++.h>

using namespace std;

string A[10005];

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int N;
        cin >> N;

        for(int i = 0; i < N; i++)
            cin >> A[i];

        sort(A, A + N);
        bool flag = false;
        for(int i = 1; i < N; i++)
            if(A[i].substr(0, A[i - 1].size()) == A[i - 1])
            {
                cout << "NO\n";
                flag = true;
                break;
            }

        if(!flag)
            cout << "YES\n";
    }


    return 0;
}
