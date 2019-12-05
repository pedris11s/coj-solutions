#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

typedef pair <int, int> par;

#define x first
#define y second

const int MAXN = 150;
const int INF = 1000000;

int N;
par ini, fin;
vector <par> A;
bool dist[MAXN][MAXN];
vector <par> adlist[MAXN];

int mod(int n)
{
    return (n < 0) ? -n : n;
}

int dm(par a, par b)
{
    return mod(a.x - b.x) + mod(a.y - b.y);
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        A.clear();

        int cities;
        cin >> cities;
        int a, b;
        cin >> a >> b;
        A.push_back(par(a, b));
        for(int i = 0; i < cities; i++)
        {
            int a, b;
            cin >> a >> b;
            A.push_back(par(a, b));
        }
        cin >> a >> b;
        A.push_back(par(a, b));
        N = A.size();

        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                dist[i][j] = (i == j) ? true : false;

        for(int i = 0; i < N - 1; i++)
            for(int j = i + 1; j < N; j++)
            {
                int d = dm(A[i], A[j]);
                dist[i][j] = dist[j][i] = (d <= 1000) ? true : false;
            }

        for(int k = 0; k < N; k++)
            for(int i = 0; i < N; i++)
                for(int j = 0; j < N; j++)
                    if(dist[i][k] && dist[k][j])
                        dist[i][j] = true;

        if(dist[0][N - 1])
            cout << "happy\n";
        else
            cout << "sad\n";
    }

    return 0;
}
