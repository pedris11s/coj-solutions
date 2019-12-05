//by pter



#include <cstdio>



const int MAXN = 1000005;

const int MOD = 10000;



int array[MAXN];

int ta[MAXN];



int main()

{

    int N, U, Q;

    scanf("%d%d%d", &N, &U, &Q);

    for(int i = 0; i < U; i++)

    {

        int a, b;

        scanf("%d%d", &a, &b);

        if(a > 1)

            array[a - 1] = (array[a - 1] + b) % MOD;

        if(a < N)

            array[a + 1] = (array[a + 1] + b) % MOD;

         

        array[a] = (array[a] + b + 1) % MOD;

    }

    ta[1] = array[1];

    for(int i = 2; i <= N; i++)

        ta[i] = (ta[i - 1] + array[i]) % MOD;

    

    for(int i = 0; i < Q; i++)

    {

        int a, b;

        scanf("%d%d", &a, &b);

        printf("%d\n", (ta[b] - ta[a - 1] + MOD) % MOD);

    }

    return 0;

}

