#include <cstdio>
#include <iostream>

using namespace std;

typedef long long huge;

const int MAXN = 180001;

int n;
huge p, A[MAXN], TA[MAXN];

bool check(int k)
{
    //if(TA[k - 1] > p)
    //    return false;
    for(int i = k; i <= n; i ++)
        if(TA[i] - TA[i - k] > p)
            return false;
    return true;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> p >> n;

        for(int i = 1; i <= n; i++)
            cin >> A[i];

        TA[1] = A[1];
        for(int i = 1; i <= n; i++)
            TA[i] = TA[i - 1] + A[i];

        int ini = 1, fin = n;
        while(fin - ini >= 5)
        {
            int mid = (ini + fin) / 2;
            if(check(mid))
                ini = mid;
            else
                fin = mid - 1;
        }
        int sol = 0;
        for(int i = fin; i >= ini; i--)
            if(check(i))
            {
                sol = i;
                break;
            }
        printf("%d\n", sol);
    }

    return 0;
}

