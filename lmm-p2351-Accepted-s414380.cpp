#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 251;

int cow[MAXN];
bool mk[MAXN];

int main()
{
    //freopen("bfire.in", "r", stdin);
    //freopen("bfire.out", "w", stdout);

    int N;
    scanf("%d", &N);

    for(int i = 1; i <+ N; i++)
        cow[i] = i;

    int v = 1, p = 1;
    while(true)
    {
        //printf("%d %d ", p, cow[p]);
        p = (p + v) % N;
        if(p == 0)
            p = N;

        swap(v, cow[p]);
        //printf("%d %d\n", p, cow[p]);
        if(mk[p])
        {
            if(cow[p] != 0)
                printf("%d\n", cow[p]);
            else
                printf("%d\n", p);
            break;
        }
        mk[p] = true;
        if(p == 1)
        {
            printf("%d\n", cow[p]);
            break;
        }
    }


    return 0;
}
