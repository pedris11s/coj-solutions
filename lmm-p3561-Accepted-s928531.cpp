#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 7;

int primo[MAXN];
int TA[20][MAXN];

void criba()
{
    for(int i = 2; i * i < MAXN ; i++)
        if(!primo[i])
        {
            primo[i] = i;
            for(int j = i + i; j < MAXN; j +=i)
                primo[j] = i;
        }

    for(int i = 2; i < MAXN; i++)
        if(!primo[i])
            primo[i] = i;
}

int A[MAXN];

void factor()
{
    for(int i = 2; i < MAXN; i++)
    {
        bool flag = true;
        int n = i, cant = 1, anterior = primo[n];
        while(primo[n] != n)
        {
            n /= primo[n];
            if(primo[n] == anterior)
            {
                A[i] = 0;
                flag = false;
                break;
            }
            cant++;
            anterior = primo[n];
        }
        if(flag)A[i] = cant;
    }
}

int main()
{
    criba();
    factor();

    for(int i = 1; i < MAXN; i++)
    {
        for(int j = 1; j <= 10; j++)
        {
            if(j == A[i])
                TA[j][i] = TA[j][i - 1] + 1;
            else
                TA[j][i] = TA[j][i - 1];
        }
    }

    int t;
    scanf("%d", &t);
    while(t--)
    {
        int a, b, k;
        scanf("%d%d%d", &a,&b,&k);

        if(k>10)printf("0\n");
        else printf("%d\n", TA[k][b] - TA[k][a - 1]);
    }
    return 0;
}
