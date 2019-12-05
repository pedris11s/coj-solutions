#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;

const int MAX = 100000;
const ll MAX_INT = 4294967296;//2^32

ll bm[MAX] = {0, 1, 0};
ll bh[MAX] = {1, 1, 0};

void bee()
{
    ll i = 1;
    do
    {
        i++;
        bm[i] = bm[i - 1] + bh[i - 1];
        bh[i] = bh[i - 1] + bh[i - 2];

    } while( (bm[i] + bh[i]) < MAX_INT);
}

int main()
{
    //cout << MAX_INT << endl;

    int n;
    bee();

    while(true)
    {
        cin >> n;

        if(n == -1)
            break;

        cout<< bm[n] << " " << bm[n] + bh[n] << "\n";
    }

    return 0;
}
