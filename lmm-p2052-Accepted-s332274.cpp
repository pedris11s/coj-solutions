#include <cstdio>

using namespace std;

int F[501];
int s;

int comprueba(int n)
{
    for(int i = 1; i <= n;i++)
        if(F[i] == i)
        {
          F[i] = 0;
          return i - 1;
        }
        return -1;
}

bool jugar()
{
     int r;
     r = comprueba(s);
     if( r == -1)
        return false;
     else
     {
        for(int i = 1;i <= r;i++)
            F[i]++;

        jugar();
     }
}

int main()
{
    int i;

    while(true)
    {
         scanf("%d",&s);
         if(s == -1)
            break;
         else
         {
            for(int i = 1;i <= s;i++)
                 scanf("%d",&F[i]);

            if(!jugar())
            {
               int cont = 0;
               for(int i = 1;i <= s;i++)
                   if(F[i] != 0)
                     cont++;

               if(cont == 0)
                   printf("S\n");
               else
                   printf("N\n");
            }
         }
    }
    return 0;
}
