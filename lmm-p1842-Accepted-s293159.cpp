#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
  int x1,x2,y1,y2,t,sol;
  scanf("%d",&t);
  for(int i = 0;i < t;i++){
      scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
      sol = abs(x1 - x2) + abs((y1 - y2));
      printf("%d\n",sol);
  }
    return 0;
}
