#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 1001;

int N;
int F[MAXN];
int mk[MAXN];
queue <int> cola;

bool bfs(int nod)
{
    fill(mk + 1, mk + N + 1, false);
    while(!cola.empty())
        cola.pop();

    cola.push(nod);
    while(!cola.empty())
    {
        int nodo = cola.front();
        cola.pop();

        int nn = F[nodo];
        if(mk[nn])
            return false;

        if(nn == 0)
            return true;

        cola.push(nn);
        mk[nn] = true;
    }
}

int main()
{
    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> F[i];

    int cont = 0;
    for(int i = 1; i <= N; i++)
        if(bfs(i))
            cont++;

    cout << cont << endl;


    return 0;
}
