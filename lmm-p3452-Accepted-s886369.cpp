#include <bits/stdc++.h>

using namespace std;

const int MAXN = 250;
const int A[] = {1, 3, 9, 27};

int sol[MAXN];
int costo[MAXN];
int wayf[MAXN];

int bfs(int n){

    fill(wayf, wayf + MAXN, 0);
    fill(costo, costo + MAXN, (1 << 20));

    queue <int> cola;
    cola.push(n);
    costo[n] = 0;
    while(!cola.empty())
    {
        int num = cola.front();
        cola.pop();

        if(num == 0)
            return costo[0];

        for(int i = 3; i > -1; i--)
        {
            int nn = num - A[i];
            if(num >= 0 && costo[num] + 1 < costo[nn])
            {
                cola.push(nn);
                costo[nn] = costo[num] + 1;
                wayf[nn] = A[i];
            }
        }
    }
    return -1;
}

void dame_sol(int n)
{
    if(wayf[n] == 0)
        return;

    sol[wayf[n]]++;
    dame_sol(n + wayf[n]);
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        int n;
        scanf("%d", &n);

        int x = bfs(n);
        dame_sol(0);
        //for(int i = 0; i <= n; i++)
        //    cout << i << ") " << wayf[i] << '\n';
        printf("Case #%d: %d Coppers %d Triads %d Nonas %d Cubics\n", i, sol[1], sol[3], sol[9], sol[27]);
        sol[1] = 0;sol[3] = 0;sol[9] = 0;sol[27] = 0;
    }
    return 0;
}
