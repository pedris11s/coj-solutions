//by pter

#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 1005;

int a[MAXN];
int ta[MAXN];

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> a[i];

        ta[0] = 1;
        int sol = 1;
        for(int i = 1; i < n; i++)
        {
            int max = 0;
            for(int j = 0; j < i; j++)
                if(a[j] < a[i] && ta[j] > max)
                    max = ta[j];

            ta[i] = max + 1;
            if(ta[i] > sol)
                sol = ta[i];
        }
        cout << sol << endl;
    }
    return 0;
}
