//by pter

#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int t, n , m, x;

    scanf("%d", &t);

    for(int i = 0; i< t; i++)
    {
        int s[6] = {0}, max = 0, cand;

        scanf("%d %d", &n, &m);

        for(int i = 0; i < m; i++)
            for(int j =1; j <= n; j++)
            {
                scanf("%d", &x);
                s[j]+=x;
                if(max < s[j])
                {
                    max = s[j];
                    cand = j;
                }
            }

        printf("%d\n", cand);
    }

    return 0;
}

