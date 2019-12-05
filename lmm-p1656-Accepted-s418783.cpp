#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 501;
const int MAXH = 45001;

int a[MAXN];
bool mk[MAXH];

int main()
{
    int h, n;
    cin >> h >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    int sol = 0;
    mk[0] = true;
    for(int i = 1; i <= n; i++)
        for(int j = h; j >= a[i]; j--)
            if(mk[j - a[i]])
            {
                mk[j] = true;
                if(j > sol)
                    sol = j;
            }
    cout << sol << endl;
    return 0;
}