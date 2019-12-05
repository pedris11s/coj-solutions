//by pter

#include <cstdio>

const int NUMERAZO = 500;

int main()
{
    int t;
    scanf("%d", &t);

    int a, b, c;
    int min = NUMERAZO;

    for(int i = 0; i < t; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        if( (a + b) > c && (a + c) > b && (b + c) > a )
        {
            int p = a + b + c;
            if(p < min)
                min = p;
        }
    }
    printf("%d\n", min);

    return 0;
}
