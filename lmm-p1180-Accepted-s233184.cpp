//by pter

#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int chess_show[6] = {1,1,2,2,2,8};
    int cases;
    int cw;    
    scanf("%d",&cases);
    for(int i = 0; i < cases; i++)
    {
         for(int j = 0; j < 6; j++) 
         {
              scanf("%d",&cw);
              printf("%d",chess_show[j] - cw);
              if (j < 5) printf(" ");
         }
         printf("\n");
    }
    return 0;
}
