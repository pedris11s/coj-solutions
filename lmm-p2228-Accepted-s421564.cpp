#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int T;
long long N,sol;


void desc_fact_prim(long long num)
{
 sol=1;
 if(num%2==0) sol*=(long long)2;
 while(num%2==0)  num/=(long long)2;

 for(long long i=3;i*i<=num && num!=1;i+=2)
   {
      if(num%(long long)i==0)
        sol*=(long long)i;
    while(num%(long long)i==0)    num/=(long long)i;
   }
sol*= (long long)num;
}

int main()
{
  //freopen("a.in","r",stdin);
  scanf("%d",&T);

  while(T--){
  scanf("%lld",&N);

  desc_fact_prim((long long)N);

  printf("%lld\n",(long long)sol);
  }
      return 0;
}
