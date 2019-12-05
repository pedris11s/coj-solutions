//by pter

#include <cstdio>
#include <cstdlib>

void h(int n,char A,char B,char C)
{
    if(n == 1)
         printf("Move ring from stick %c to stick %c.\n",A,C);
    else
    {
         h(n - 1, A, C, B);
         printf("Move ring from stick %c to stick %c.\n",A,C);
         h(n - 1, B, A, C);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int moves = (1 << n) - 1;
    h(n, '1', '2', '3');
    printf("You needs %d moves.\n",moves);
    system("pause");
    return 0;
}
