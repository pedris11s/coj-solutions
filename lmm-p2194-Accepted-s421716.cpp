#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct par{
    int r;
    string q;
}A[105];

int main()
{
    //freopen("d.in","r",stdin);

    int N, M;
    cin >> N >> M;

    for(int i = 0; i < M; i++)
        cin >> A[i].q >> A[i].r;

    int sol = -1, csol = 0, flag = false;
    for(int mask = 1; mask < (1 << N); mask++)
    {
        for(int i = 0; i < M; i++)
        {
            int cont = 0;
            flag = false;
            for(int j = 0; j < N; j++)
                if(A[i].q[j] == '1' && (mask & (1 << j)))
                    cont++;

            if(cont != A[i].r)
            {
                flag = true;
                break;
            }
        }
        if(!flag)
        {
            sol = mask;
            csol++;
        }
        if(csol > 1)
        {
            printf("NOT UNIQUE\n");
            exit(0);
        }
    }
    if(sol != -1)
    {
        for( int i = 0; i < N; i++ )
            printf("%d",(sol & (1 << i)) ? 1 : 0);
    }
    else
        cout << "IMPOSSIBLE\n";

}
