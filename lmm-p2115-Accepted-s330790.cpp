//by pter

#include <cstdio>

int main()
{
    float a,b;
    while(scanf("%f%f", &a, &b) != EOF)
    {
        printf("%.2f\n", a / b);
    }
    return 0;
}
