//by pter

#include <cstdio>

int main()
{
    int a1,a2,a3;

    int next,c = 0;
    
    while(true)
    {
         scanf("%d%d%d",&a1,&a2,&a3);
         if(a1 == 0 && a2 == 0 && a3 == 0)break;      
    
         if(a3 - a2 == a2 - a1)
         {
              c = a3 - a2;
              next = a3 + c;
              printf("AP %d\n",next);      
         }
         else
         {
              c = a3 / a2;
              next = a3 * c;
              printf("GP %d\n",next);     
         }
    }
    return 0;
}
