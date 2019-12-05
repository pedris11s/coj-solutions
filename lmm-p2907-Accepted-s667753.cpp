#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 1e6 + 7;
/*
struct par{
    int x, c;
    bool operator < (const par &R)const
    {
        return x < R.x;
    }

}A[MAXN];


7
16 3
5 4
6 5
7 15
1 7
10 3
12 5
*/

int X[MAXN], C[MAXN], A[MAXN];
int main()
{
    //freopen(".in", "r", stdin);;
    int N;
    while(cin >> N)
    {
        for(int i = 0; i < N; i++)
        {
            cin >> X[i] >> C[i];
            A[i] = X[i];
        }

        sort(A, A + N);
        int max_cities = -1, city = 0;
        for(int i = 0; i < N; i++)
        {
            int a = upper_bound(A, A + N, X[i] + C[i]) - A;
            int b = lower_bound(A, A + N, X[i]) - A;
            if(a - b - 1 > max_cities)
            {
                max_cities = a - b - 1;
                city = X[i];
            }
        }
        cout << city << ' ' << max_cities << endl;
    }
    return 0;
}
