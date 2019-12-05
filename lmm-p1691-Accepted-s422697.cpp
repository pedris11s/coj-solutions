#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const int MAXN = 10001;

int N;
vector<int> adlist[MAXN];
int d[MAXN];
bool mk[MAXN];

int dfs(int nodo)
{
    mk[nodo] = true;
    d[nodo] = 0;

    int sol = 1;
    for(int i = 0; i < (int)adlist[nodo].size(); i++)
    {
        int newn = adlist[nodo][i];
        if(!mk[newn])
        {
            int sv = dfs(newn);
            sol += sv;

            d[nodo] = max(d[nodo], sv);
        }
    }
    d[nodo] = max(d[nodo], N - sol);
    return sol;
}

int main()
{
    scanf("%d",&N);
    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        scanf("%d %d",&u, &v);
        adlist[u].push_back(v);
        adlist[v].push_back(u);
    }
    dfs(1);
    bool sol = false;
    for(int i = 1; i <= N; i++)
    {
        if(d[i] <= (N / 2))
        {
            printf("%d\n", i);
            sol = true;
        }
    }
    if(!sol)
       printf("NONE\n");

}
