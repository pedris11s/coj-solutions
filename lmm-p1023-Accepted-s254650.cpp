#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    float n;
    float sum = 0;
    for(int i = 0; i < 12; i++)
    {
         scanf("%f",&n);
         sum += n;
    }
    printf("$%.2f\n",sum / 12);
    return 0;
}

