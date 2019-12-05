//by pter

#include <cstdio>
#include <cstdlib>

const int MAXN = 10002;

bool mk[MAXN];

int main()
{
    int t;
    scanf("%d",&t);
    int n;
    int cont;
    for(int i = 0; i < t; i++)
    {
         scanf("%d",&n);
         mk[n] = true;
         cont = 0;
         for(int j = 1; j <= t; j++)
              if(!mk[j])
                   cont++;
    }
    printf("%d\n",cont);
//    system("pause");
    return 0;
}
