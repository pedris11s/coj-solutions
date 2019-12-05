#include <cstdio>
#include <algorithm>

using namespace std;

int freq[10];

int main()
{
    int t;
    scanf ("%d", &t);
    while (t--)
    {
        fill(freq + 1, freq + 10, 0);
        int n;
        scanf ("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            int x;
            scanf ("%d", &x);
            freq[x]++;
        }
        int sol = freq[4] + freq[3];
        if (freq[1] > freq[3])
        {
            freq[1] -= freq[3];
            freq[1] = freq[1] / 2 + freq[1] % 2;
            sol += ((freq[1] + freq[2]) / 2 + (freq[1] + freq[2]) % 2);
        }
        else
            sol += (freq[2] / 2 + freq[2] % 2);

        printf ("%d\n", sol);
    }

    return 0;
}
