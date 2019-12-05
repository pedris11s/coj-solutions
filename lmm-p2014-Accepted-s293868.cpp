//by pter & AVPS

#include <cstdio>
#include <cstring>

const int MAX = 101;

char s[MAX];
bool mk[MAX];

int main()
{
    int c;
    scanf("%d",&c);
    int d;
    for(int i = 0; i < c; i++)
    {
        scanf("%s%d", s, &d);
        
        int size = strlen(s); 
        
        int ind = 0;
        while(d > 0 && ind != size)
        {
             if(s[ind] == '1')
             {
                  s[ind] = '0';
                  mk[ind] = true;
                  d--;
             }
             ind++;        
        }
        if(d == 0)
             printf("Case #%d: %s\n", i + 1, s);
        else
        {
             ind = size - 1;
             while(d > 0)
             {
                  if(mk[ind] == false)
                  {
                       s[ind] = '1';
                       d--;
                  }
                  ind--;
             }
             printf("Case #%d: %s\n",i + 1,s);
        }   
        for(int K = 0; K < size; K++)
             mk[K] = false;
    }
    return 0;
}
