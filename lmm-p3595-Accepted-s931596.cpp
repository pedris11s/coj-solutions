#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#define FOR(i,n) for(int i = 0; i < n; i++)
#define ll long long
#define endl '\n'
#define MAXN 10002
#define eps 1>>30
#define mod 1000003

using namespace std;
int n;
int mat[5200][5200];
int tabla[5200][5200];
int SUM(int i, int j, int ii, int jj)
{
    return tabla[ii][jj]-tabla[i-1][jj] - tabla[ii][j-1]+tabla[i-1][j-1];
}

int fun(int i, int j)
{
    int izq = 0, der = min(n - i + 1, n - j + 1);
    int sol = 0;
    while(izq <= der)
    {
        int mit = (izq + der) / 2;
        int suma = SUM(i, j, i + mit-1, j + mit-1);
        int val = mit;
        if(val * val == suma)
            izq = mit + 1, sol = mit;
        else
            der = mit - 1;
    }
    return sol;
}
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);

    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            tabla[i][j] = mat[i][j]+tabla[i-1][j]+tabla[i][j-1]-tabla[i-1][j-1];
        }
    }
    int maxi = 0;
    int contador = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            int k = fun(i, j);
            if(k > maxi){
                maxi = k;
                contador = 1;
            }
            else if(k == maxi)
                contador++;
        }
    }
    printf("%d\n", maxi*contador);
    return 0;
}
