#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 25;

int N, A[MAXN], P[MAXN];
bool mk[MAXN];

bool is_ok()
{
    fill(mk, mk + N, false);
    for(int i = 0; i < N; i++)
        for(int k = 0; k < N; k++)
        {
            int card = (P[A[i]] + k) % N;
            if(!mk[card])
            {
                mk[card] = true;
                if(A[i] == 0 && P[0] == card)
                    return true;
                break;
            }
        }
    return false;
}

int main()
{
    //freopen(".in", "r", stdin);

    int t;
    cin >> t;
    while(t--)
    {
        cin >> N;
        for(int i = 0; i < N; i++)
            cin >> P[i];

        for(int i = 0; i < N; i++)
            A[i] = i;

        int sol = 0;
        do
        {
            //cout << endl;
            if(is_ok())
            {
                sol++;
                //for(int i = 0; i < N; i++)
                //    cout << A[i] << ' ';
                //cout << endl;
            }

        }while(next_permutation(A, A + N));
        cout << sol << endl;
    }

    return 0;
}

