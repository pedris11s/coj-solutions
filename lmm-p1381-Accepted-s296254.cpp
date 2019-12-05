//by pter

#include <cstdio>

int main()
{
    int t;
    scanf("%d",&t);
    float d, v1, v2, m;
    float time;
    float desp;
    for(int i = 0; i < t; i++)
    {
         scanf("%f%f%f%f", &d, &v1, &v2, &m);
         time = d / (v1 + v2);
         desp = m * time;
         printf("%.2f\n",desp);
    }
    return 0;
}
