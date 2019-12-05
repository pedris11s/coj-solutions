//by pter

#include <cstdio>

int t_sqr(int n)
{
     return n * n;
}

bool is_pythagorean(int a,int b,int c)
{
    if(t_sqr(a) + t_sqr(b) == t_sqr(c))
         return true;
    else if(t_sqr(b) + t_sqr(c) == t_sqr(a))
         return true;
    else if(t_sqr(a) + t_sqr(c) == t_sqr(b))
         return true;
    else
         return false;
}

int main()
{
    int a,b,c;
    
    while(true)
    {
        scanf("%d%d%d", &a, &b, &c);
         
         if(a == 0 && b == 0 && c == 0)
              break;
         
         if(is_pythagorean(a,b,c))
              printf("right\n");
         else
              printf("wrong\n");
    }
    return 0;
}
