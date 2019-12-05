#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N, A, B;
vector <LL> V;
int P[20];

void sol(int pos, LL mul)
{
    if(mul >= A)
        V.push_back(mul);

    for(int i = pos; i < N; i++)
        if(mul * P[i] <= B)
            sol(i, mul * P[i]);
}

int main()
{
    while(true)
    {
        scanf("%d", &N);
        if(N == 0)break;
        V.clear();

        for(int i = 0; i < N; i++)
            scanf("%d", &P[i]);

        scanf("%d%d", &A, &B);

        sol(0, 1);

        if(V.empty()){
            printf("none\n");
            continue;
        }
        sort(V.begin(), V.end());
        for(int i = 0; i < V.size(); i++){
            if(i != 0)
                printf(",");
            printf("%d", V[i]);
        }
        printf("\n");
    }

    return 0;
}
