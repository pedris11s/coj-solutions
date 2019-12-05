#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100001;

struct par{
    int id, value;
    par(int a = 0, int b = 0)
    {
        id = a, value = b;
    }
    bool operator < (const par &X)const
    {
        if(value != X.value)
            return value < X.value;
        return  id < X.id;
    }
}A[MAXN];

int N, B[MAXN];
bool mk[MAXN];

int main()
{
    //freopen("d.in", "r", stdin);

    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        cin >> B[i];
        A[i].id = i;
        A[i].value = B[i];
    }
    sort(A + 1, A + N + 1);

    int sol = -1,  cisl = 1;
    mk[0] = mk[N + 1] = true;
    for(int i = 1; i <= N; i++)
    {
        int j = 1;
        while(B[A[i].id] == B[A[i].id + j] && A[i].id + j <= N)
        {
            mk[A[i].id + j] = true;
            j++;
        }
        if(!mk[A[i].id - 1] && !mk[A[i].id + j])
            cisl++;
        else if(mk[A[i].id - 1] && mk[A[i].id + j])
            cisl--;

        mk[A[i].id] = true;
        sol = max(sol, cisl);
    }
    cout << sol << endl;
    return 0;
}
