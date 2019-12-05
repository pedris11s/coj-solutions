#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 21;

bool mk[MAXN];
int A[MAXN], N, Q, Array[MAXN];
long long fact[MAXN];

void build_fact()
{
    fact[0] = 1;
    for(long long i = 1; i < MAXN; i++)
        fact[i] = fact[i - 1] * i;
}

void find_permutation(long long k)
{
    fill(mk, mk + N + 1, false);
    for(int i = 0; i < N; i++)
    {
        long long q = k / fact[N - 1 - i];
        int c = 0, j = 0;
        while(c <= q && j < N)
        {
            if(!mk[j])
                c++;
            j++;
        }
        A[i] = j;
        mk[j - 1] = true;
        k = k % fact[N - 1 - i];
    }
}

long long find_range(int X[])
{
    fill(mk, mk + N + 1, false);

    long long sol = 0;
    for(int i = 0; i < N; i++)
    {
        int c = 0;
        for (int j = 0; j < X[i] - 1; j++)
            if (!mk [j])
                c++;

        mk[X[i] - 1] = true;
        sol += fact [N - 1 - i] * c;
    }
    return sol;
}

int main()
{
    build_fact();
    cin >> N >> Q;
    while(Q--)
    {
        char q;
        cin >> q;
        if(q == 'P')
        {
            long long k;
            cin >> k;

            find_permutation(k - 1);
            for(int i = 0; i < N; i++)
                if(i == N - 1)
                    cout << A[i] << endl;
                else
                    cout << A[i] << ' ';
        }
        else
        {
            for(int i = 0; i < N; i++)
                cin >> Array[i];

            cout << find_range(Array) + 1 << endl;
        }
    }

    return 0;
}
