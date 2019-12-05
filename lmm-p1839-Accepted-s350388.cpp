#include <cstdio>

using namespace std;

int main()
{
    int n, t;
    scanf("%d",&t);
    for(int i = 0;i < t;i++){
         scanf("%d",&n);
         printf("%d\n",8 * (n - 1) + 50);
    }
    return 0;
}
