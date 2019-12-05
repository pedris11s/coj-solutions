#include <cstdio>
#include <algorithm>
#include <vector>

const int MAX = 9999;

using namespace std;

bool mycomp(int a, int b)
{
    if(a < b)
        return true;

    return false;
}

int A[1001];
int C[1001];
bool P[1001];

void eliminar(int n)
{
    int sol, cont = 0;
    sol = n;
    while(sol > 2)
    {
        cont = 0;
        for(int i = 1;i <= sol; i *= 2)
        {
            A[i] = MAX;
            cont++;
        }
        sol -= cont;
        sort( A + 1, A + (n + 1));
    }
    if(sol == 2)
        printf("%d\n", A[2]);
    else
        printf("%d\n", A[1]);
}

int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {

        if(n == 1)
        {
           printf("1\n");
           continue;
        }
        if(n == 2)
        {
           printf("2\n");
           continue;
        }
        else
        {
            for(int i = 1;i <= n;i++)
                A[i] = i;

            eliminar(n);
        }
    }
    return 0;
}
