#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

int dist(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    return dx + dy;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;

        if(n == 0 || m == 0)
        {
            cout << "0\n";
            continue;
        }
        int c1 = (n + 1) / 2;
        int c2 = (m + 1) / 2;

        int sol = max(c1 - 1, n - c1) + max(c2 - 1, m - c2);
        cout << sol + 1 << endl;
    }

    return 0;
}
