#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int F, L, S, A1, N, D;
        cin >> F >> L >> S;
        N = (2 * S) / (F + L);
        D = (L - F) / (N - 5);
        A1 = F - 2 * D;

        //cout << A1 << ' ' << N << ' ' << D << endl;

        vector <int> SOL;

        int v = A1;
        int sum = v, ind = 0;
        while(true)
        {
            SOL.push_back(v);
            v += D;
            sum += v;
            if(sum > S)
                break;
        }
        cout << SOL.size() << endl;
        for(int i = 0; i < SOL.size(); i++)
            if(i == SOL.size() - 1)
                cout << SOL[i] << endl;
            else
                cout << SOL[i]  << ' ';

    }

    return 0;
}
