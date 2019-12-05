//by pter

/*
3 6
D...*.
.X.X..
....S.
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdlib>

using namespace std;

#define x first
#define y second
#define MKP(a, b) make_pair((a), (b))

typedef pair <int, int> pii;

const int oo = 9999;

int f, c;
char M[60][60];
int costo_aster[60][60];
int costo_slikar[60][60];
bool mkA[60][60];
bool mkS[60][60];

queue < pii > cA;
queue < pii > cS;

pii s_ini;
pii dest;
vector <pii> ast_ini;

int DX[4] = {-1, 0, 1, 0};
int DY[4] = {0, 1, 0, -1};

bool Valido(pii A)
{
    if(A.x <= f && A.y <= c && A.x >= 0 && A.y >= 0 && M[A.x][A.y] == '.')
        return true;

    return false;
}

void BFS_Aster()
{


    while( !cA.empty() )
    {
        pii actual = cA.front();
        cA.pop();

        for(int i = 0; i < 4; i++)
        {
            pii ast = MKP(actual.x + DX[i], actual.y + DY[i]);

            if(Valido(ast) && !mkA[ast.x][ast.y] )
            {
                mkA[ast.x][ast.y] = true;
                cA.push(ast);
                //M[ast.x][ast.y] = '*';
                costo_aster[ast.x][ast.y] = costo_aster[actual.x][actual.y] + 1;
            }
        }
    }
}

int BFS_Slikar()
{
    while( !cS.empty() )
    {
        pii actual = cS.front();
        cS.pop();

        if(actual == dest)
            return costo_slikar[actual.x][actual.y];

        for(int i = 0; i < 4; i++)
        {
            pii slk = MKP(actual.x + DX[i], actual.y + DY[i]);

            if( Valido(slk) && !mkS[slk.x][slk.y] )
            {
                costo_slikar[slk.x][slk.y] = costo_slikar[actual.x][actual.y] + 1;
                if(costo_slikar[slk.x][slk.y] < costo_aster[slk.x][slk.y])
                {
                    //cout << "entro" <<endl;
                    mkS[slk.x][slk.y] = true;
                    cS.push(slk);
                }
            }
        }
    }
    return -1;
}

int main()
{
    //freopen("slikar.in", "r", stdin);
    //freopen("slikar.out", "w", stdout);

    cin >> f >> c;

    for(int i = 0; i < f; i++)
        scanf("%s", M[i]);

    //inicializando costo_aster;
    for(int i = 0; i < f; i++)
        for(int j = 0; j < c; j++)
            costo_aster[i][j] = oo;

    for(int i = 0; i < f; i++)
        for(int j = 0; j < c; j++)
        {
            if(M[i][j] == '*')
            {
                //ast_ini.push_back(MKP(i, j));
                cA.push(MKP(i,j));
                mkA[i][j] = true;
                costo_aster[i][j] = 0;
                //cout << i << ' ' << j << endl;
            }
            else if(M[i][j] == 'S')
            {
                //s_ini = MKP(i,j);
                cS.push( MKP( i, j ) );
                mkS[i][j] = true;
            }
            else if(M[i][j] == 'D')
            {
                dest = MKP(i,j);
                M[i][j] = '.';
                mkA[i][j] = true;
                costo_aster[i][j] = oo;
            }
        }
    BFS_Aster();

    /*for(int i = 0; i < f; i++)
    {
        for(int j = 0; j < c; j++)
            cout << costo_aster[i][j];

        cout << endl;
    }
    cout << endl;*/

    int sol = BFS_Slikar();

    /*for(int i = 0; i < f; i++)
    {
        for(int j = 0; j < c; j++)
            cout << costo_slikar[i][j];

        cout << endl;
    }*/

    if(sol >= 0)
        cout << sol << endl;
    else
        cout << "KAKTUS\n";

    //fclose(stdin);
    //fclose(stdout);

    //system("pause");
    return 0;
}
