#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int A[1000007];

int main (){

    ios_base::sync_with_stdio(0); cin.tie(0);

    LL N, K;
    cin >> N >> K;

    int i = 0;
    for(i = 1; i <= N; i++)
    {
         if(K == 0)
            break;

         if(K >= N - i)
             K -= N - i;
         else
            break;
    }

    for(int j = 0; j < i - 1; j++)
         A[N - j] = j + 1;

    if(K > 0)
    {
        int pos = 1, num = i + 1;
        for(int j = i; j <= N; j++)
        {
            if(pos - 1 == K)
                 A[pos] = i;
            else
            {
                A[pos] = num;
                num ++;
            }
            pos++;
        }
    }
    else
    {
        int pos = 1;
        for(int j = i; j <= N; j++)
             A[pos++] = j;
    }
    cout << A[1];
    for (int i = 2; i <= N; i++)
         cout << " " << A[i];
    cout << "\n";
    return 0;
}
