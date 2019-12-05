#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 500001;

int CD[MAXN];

int main()
{
    //precalculo:

    for (int i = 1 ; i <= MAXN ; i++)
        for (int j = i ; j <= MAXN ; j += i)
            CD[j] += i;

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int sum = CD[n] - n;

        cout << sum << endl;
    }

    return 0;
}
