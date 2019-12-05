#include <cstdio>
#include <iostream>
#include <algorithm>


using namespace std;

const int MAXN = 1000100;

int min_v(int a, int b, int c)
{
    return min(min(a, b), c);
}

int max_v(int a, int b, int c)
{
    return max(max(a, b), c);
}

int N, Q;
int maxgx=-1, maxgy=-1;
int sumx[MAXN], sumy[MAXN];

int main()
{
    //freopen("asdv.in", "r", stdin);

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        int minx = min_v(x1, x2, x3);
        int maxx = max_v(x1, x2, x3);

        int miny = min_v(y1, y2, y3);
        int maxy = max_v(y1, y2, y3);

        maxgx = max(maxx, maxgx);
        maxgy = max(maxy, maxgy);

        sumx[minx + 1]++;
        sumx[maxx]--;

        sumy[miny + 1]++;
        sumy[maxy]--;
    }


    for(int i = 1; i <= maxgx; i++)
        sumx[i] += sumx[i-1];


    for(int i = 1; i <= maxgy; i++)
        sumy[i] += sumy[i-1];

    cin >> Q;
    scanf("\n");
    while(Q--)
    {
        char a;
        int b;
        scanf("%c = %d\n", &a, &b);
        if(a == 'x')
            cout << sumx[b] << endl;
        else if(a == 'y')
            cout << sumy[b] << endl;
    }

    return 0;
}
