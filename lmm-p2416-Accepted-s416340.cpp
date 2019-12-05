#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char S[8], S1[8];
int n, r, sum, m, m1;

int main()
{
    int t;
    scanf ("%d\n", &t);
    while (t--)
    {
        scanf ("%d", &n);
        sprintf (S ,"%d", n);
        int sum = 54;//poner 6 nuves
        while (sum--)
        {
            int r = n * 10 + sum;
            sprintf (S1, "%d", r);
            for (int i = 0; i < 6; i++)
                r -= (S1[i]-'0');

            m = 0;
            sprintf (S1, "%d", r);
            for (int i = 0; i < 5; i++)
                if (S1[i] != S[i])
                    m = 1;

            if (m == 0)
            {
                printf ("%d\n", r % 10);
                sum=0;
            }
        }
    }
    return 0;
}
