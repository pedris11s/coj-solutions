#include <cstdio>
#include <iostream>

using namespace std;

const int MAXT = 1000002;

int next[MAXT];
int n,t;

int main()
{
    scanf("%d %d",&n,&t);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if ( b + 1 > next[a])
           next[a] = b + 1;
    }

    for(int i = 1; i <= t; i++ )
    {
        if(next[i-1] > next[i])
           next[i] = next[i-1];

        if(next[i] <= i) break;
    }

    int i = 1;
    int sol = 0;
    do
    {
        sol++;
        i = next[i];

    }while(i <= t && next[i] > i);

    if (i <= t)
       sol = -1;

    cout << sol << endl;

    return 0;
}
