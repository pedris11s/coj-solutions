//by pter

#include <cstdio>
#include <iostream>

using namespace std;

int pow(int base,int exp)
{
    int pow = 1;

    for(int i = 1; i <= exp; i++)
         pow *= base;    

    return pow;
}

int squares(int n)
{
    return ((n * ((2 * n) + 1)) * (n + 1)) / 6; 
}

int rectangles(int n)
{
    int aux = (n * (n + 1)) / 2;
    return pow(aux,2);
}

int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
         int solSQ = squares(n);
         int solR = rectangles(n);
         printf("%d %d\n",solSQ,solR);
    }
    return 0;
}
