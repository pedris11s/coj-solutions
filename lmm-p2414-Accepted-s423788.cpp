#include <cstdio>
#include <iostream>

using namespace std;

const int MAXD = 105;
const int MAXC = 1005;

int dest[MAXD];
int price[MAXC];
int ccruc[MAXC];


bool is_70(int n, int p)
{
    int s = (7 * n) / 10;
    if(p <= s)
        return true;

    return false;
}

int main()
{
    //freopen("d.in", "r", stdin);

    int t;
    cin >> t;
    while(t--)
    {
        int D, C;
        cin >> D >> C;
        for(int i = 1; i <= D; i++)
            cin >> dest[i];

        for(int i = 1; i <= C; i++)
        {
            int d, p;
            cin >> d >> p;
            if(is_70(dest[d], p) && p > price[d])
            {
                price[d] = p;
                ccruc[d] = 1;
            }
            else if(is_70(dest[d], p) && p == price[d])
                ccruc[d]++;
        }
        for(int i = 1; i <= D; i++)
            if(price[i] == 0 && ccruc[i] == 0)
                cout << "IMPOSSIBLE\n";
            else
                cout << price[i] << ' ' << ccruc[i] << endl;

        if(t != 0)
            cout << endl;

        fill(price + 1, price + D + 1, 0);
        fill(ccruc + 1, ccruc + D + 1, 0);
    }



    return 0;
}