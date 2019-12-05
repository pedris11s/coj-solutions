#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1007;

struct trio{
    int a, b, c;
};

bool my_comp(const trio &x, const trio &y)
{
    return x.c > y.c;
}

int N, E;
int Set[MAX];
int R[MAX];
trio edge[100007];

void make_set()
{
    for(int i = 0; i < N; i++)
        R[i] = 1, Set[i] = i;
}

int find_set(int x)
{
    if(x != Set[x])
        return find_set(Set[x]);
    return x;
}

void join_set(int x, int y)
{
    if(R[x] > R[y])
        Set[y] = x, R[x] += R[y];
    else
        Set[x] = y, R[y] += R[x];
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("in", "r", stdin);

    while(true){

        cin >> N >> E;
        if(N + E == 0)break;

        for(int i = 0; i < E; i++)
            cin >> edge[i].a >> edge[i].b >> edge[i].c;

        make_set();
        sort(edge, edge + E, my_comp);

        int cont = 0, sol = (1 << 30);
        for(int i = 0; i < E; i++)
        {
            int x = find_set(edge[i].a);
            int y = find_set(edge[i].b);
            if(x != y)
            {
                cont++;
                join_set(x, y);
                sol = min(sol, edge[i].c);
            }
        }
        if(cont == N - 1)
            cout << sol << "\n";
        else
            cout << "IMPOSSIBLE\n";
    }
    return 0;
}
