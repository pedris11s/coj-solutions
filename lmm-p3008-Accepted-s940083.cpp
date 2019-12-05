#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int dx[] = {-1, 0, 0, 1, 0};
const int dy[] = {0, -1, 1, 0, 0};

bool mk[(1 << 9)];
int id[3][3], costo[(1 << 9)];

int bfs(int sf)
{
    fill(mk, mk + (1 << 9), 0);
    fill(costo, costo + (1 << 9), 0);

    queue <int> cola;
    cola.push(0);
    //costo[0] = 1;
    mk[0] = true;

    while(!cola.empty())
    {
        int ne = cola.front();
        cola.pop();

        if(ne == sf)
            return costo[ne];

        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
            {
                int nn = ne;
                for(int k = 0; k < 5; k++)
                {
                    int x = i + dx[k];
                    int y = j + dy[k];

                    if(x < 3 && x >= 0 && y < 3 && y >= 0)
                        nn ^= (1 << id[x][y]);
                }
                if(!mk[nn]){
                    cola.push(nn);
                    costo[nn] = costo[ne] + 1;
                    mk[nn] = true;
                }
            }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int cont = 0;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            id[i][j] = cont++;

    int t;
    cin >> t;
    while(t--)
    {
        int ef = 0;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++){
                char x;
                cin >> x;
                if(x == '*')
                    ef |= (1 << id[i][j]);
            }
        cout << bfs(ef) << "\n";
    }
    return 0;
}
