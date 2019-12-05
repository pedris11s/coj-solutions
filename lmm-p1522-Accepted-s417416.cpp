#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 1100;

const int DX[] = {-1, 0, 1, 0};
const int DY[] = {0, 1, 0, -1};

typedef pair <int, int> par;

#define f first
#define c second

int R, C;
int M[MAX][MAX];
int costo_ini[MAX][MAX], costo_fin[MAX][MAX];
queue <par> cola;
vector <par> apples;
par ini, fin;

bool valido(par aux)
{
    return aux.f < R && aux.c < C && aux.f > -1 && aux.c > -1 && M[aux.f][aux.c] == 0;
}


void bfs_ini()
{
    cola.push(ini);
    costo_ini[ini.f][ini.c] = 1;
    while(!cola.empty())
    {
        par actual = cola.front();
        cola.pop();

        for(int i = 0; i < 4; i++)
        {
            par coo = make_pair(actual.f + DX[i], actual.c + DY[i]);
            if(valido(coo) && costo_ini[coo.f][coo.c] == 0)
            {
                cola.push(coo);
                costo_ini[coo.f][coo.c] = costo_ini[actual.f][actual.c] + 1;
            }
        }
    }
}

void bfs_fin()
{
    cola.push(fin);
    costo_fin[fin.f][fin.c] = 1;
    while(!cola.empty())
    {
        par actual = cola.front();
        cola.pop();

        for(int i = 0; i < 4; i++)
        {
            par coo = make_pair(actual.f + DX[i], actual.c + DY[i]);
            if(valido(coo) && costo_fin[coo.f][coo.c] == 0)
            {
                cola.push(coo);
                costo_fin[coo.f][coo.c] = costo_fin[actual.f][actual.c] + 1;
            }
        }
    }
}

int main()
{
    cin >> C >> R;
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
        {
            cin >> M[i][j];
            if(M[i][j] == 2)
            {
                ini = make_pair(i, j);
                M[i][j] = 0;
            }
            else if(M[i][j] == 3)
            {
                fin = make_pair(i, j);
                //M[i][j] = 0;
            }
            else if(M[i][j] == 4)
            {
                apples.push_back(make_pair(i, j));
                M[i][j] = 0;
            }
        }

    bfs_ini();
    bfs_fin();
    /*cout << endl << endl;
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
            cout << costo_ini[i][j] << ' ';
        cout << endl;
    }

    cout << endl << endl;
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
            cout << costo_fin[i][j] << ' ';
        cout << endl;
    }*/


    int sol = (1 << 30);
    for(int i = 0; i < (int)apples.size(); i++)
    {
        if(costo_ini[apples[i].f][apples[i].c] == 0 || costo_fin[apples[i].f][apples[i].c] == 0)
            continue;

        int d1 = costo_ini[apples[i].f][apples[i].c];
        int d2 = costo_fin[apples[i].f][apples[i].c];
        if(d1 + d2 < sol)
            sol = d1 + d2;
    }

    cout << sol - 2 << endl;

    return 0;
}
