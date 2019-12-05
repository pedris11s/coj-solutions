//by pter

#include <cstdio>
#include <iostream>

using namespace std;

int searchingR2(int r1,int s)
{
    return 2 * s - r1;    
}

int main()
{
    int r1,r2,s;
    scanf("%d%d",&r1,&s);
    int sol = searchingR2(r1,s);    
    printf("%d\n",sol);

    return 0;
}
