#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 1007;

int N;
int A[MAXN];
int LIS[MAXN], LDS[MAXN];

int main()
{
    //freopen(".in", "r", stdin);

    int N;
    while(cin >> N)
    {
        for(int i = 0; i < N; i++)
            cin >> A[i];

        LIS[0] = 1, LDS[0] = 1;
        for(int i = 1; i < N; i++)
        {
            LIS[i] = 1, LDS[i] = 1;
            for(int j = 0; j < i; j++)
            {
                if(A[j] < A[i] && LIS[j] + 1 > LIS[i])
                    LIS[i] = LIS[j] + 1;
                if(A[j] > A[i] && LDS[j] + 1 > LDS[i])
                    LDS[i] = LDS[j] + 1;
            }
        }
        int lis = 1, lds = 1;
        for(int i = 0; i < N; i++)
        {
            lis = max(lis, LIS[i]);
            lds = max(lds, LDS[i]);
        }

        if(lis == lds)
            cout << "Caution. I will not intervene.\n";
        else
            cout << "Don't worry. I must intervene.\n";
    }

    return 0;
}
