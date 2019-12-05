#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1005;
const int MAXFin = 90005;

int items[MAXN];
int sumit;
int m = (1 << 30);
int N, money;

int costo(int k)
{
    int sum = 0;
    for(int i = 0; i < N; i++)
        sum += max(items[i] - k * 10, items[i] / 10);

    return sum;
}

int main()
{
    /*int x = 1000005;
    cout << (x - x /10) / 10 << endl;*/
    int t;
    cin >> t;
    while(t--)
    {
        cin >> N >> money;
        int max = 0;
        for(int i = 0; i < N; i++)
        {
            cin >> items[i];
            if(items[i] > max)
                max = items[i];
        }
        if(money < costo((max - max / 10) / 10))
            cout << "-1" << endl;
        else
        {
            int ini = 0;
            int fin = MAXFin;

            while(fin - ini >= 10)
            {
                int mid = (ini + fin) / 2;
                if (costo(mid) > money)
                    ini = mid + 1;
                else
                    fin = mid;
            }
            int d = ini;
            while(costo(d) > money)
                d++;
            cout << d << endl;
            /*int i = 0;
            while(costo(i) > money)
                i++;
            cout << i <<endl;*/
        }
    }

    return 0;
}
