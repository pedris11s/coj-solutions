#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int n, sol = 0;
    while (scanf ("%d", &n) != EOF)
    {
        if (__builtin_popcount(n) % 2 == 0)
            sol++;
    }
    printf ("%d\n", sol);

    return 0;
}
