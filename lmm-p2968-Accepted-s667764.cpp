#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <vector>

using namespace std;

const int SIZE = 6;
int A[SIZE + 1];

bool check()
{
    for(int mask = 1; mask < (1 << SIZE) - 1; mask++)
    {
        int sum1 = 0, sum2 = 0;
        for(int bit = 0; bit < SIZE; bit++)
            if(mask & (1 << bit))
                sum1 += A[bit];
            else
                sum2 += A[bit];

        if(sum1 == sum2)
            return true;
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        for(int i = 0; i < SIZE; i++)
            cin >> A[i];

        if(check())
            cout << "Tobby puede cruzar\n";
        else
            cout << "Tobby no puede cruzar\n";
    }


    return 0;
}
