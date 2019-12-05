#include <cstdio>
#include <iostream>

using namespace std;

#define PI 3.14

char w[9];
double A ,B;

int main()
{
    while(scanf("%s",&w) != EOF)
    {
        if(w[0]== 'c')
        {
            scanf("%lf",&A);
            printf("%.2lf\n",PI * A * A);
        }
        else
        {
            scanf("%lf %lf", &A, &B);
            printf("%.2lf\n", (A * B) / 2);
        }
    }

    return 0;
}
