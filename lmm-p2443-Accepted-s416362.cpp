#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 150;

struct par{
    int id, v;
    bool operator < (const par &x)const
    {
        if(x.v != v)
            return v > x.v;
        return id < x.id;
    }
}A[MAXN];

bool comp[MAXN];

void criba()
{
    for(int i = 2; i * i < MAXN; i++)
        if(!comp[i])
            for(int j = i * i; j < MAXN; j += i)
                comp[j] = true;
}

int main()
{
    //freopen("d.in", "r", stdin);

    criba();

    int N, K;
    cin >> N >> K;
    for(int i = 1; i <= N; i++)
    {
        int cont = 0;
        for(int j = 0; j < K; j++)
        {
            int n;
            cin >> n;
            if(!comp[n])
                cont++;
        }
        A[i].id = i;
        A[i].v = cont;
    }
    sort(A + 1, A + N + 1);

    if(A[1].v == A[2].v)
        cout << "No winner" << endl;
    else
        printf("Object %d wins with %d rare characteristics\n", A[1].id, A[1].v);

    return 0;
}
