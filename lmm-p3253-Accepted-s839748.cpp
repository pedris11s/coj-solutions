#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;

    set <int> Conj;
    for(int i = 0; i < N; i++)
    {
        int C;
        cin >> C;
        for(int j = 0; j < C; j++)
        {
            int x;cin >> x;
            Conj.insert(x);
        }
    }

    cout << Conj.size() << endl;


    return 0;
}
