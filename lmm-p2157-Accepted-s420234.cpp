#include <cstdio>
#include <iostream>

using namespace std;

int csq[200];

int sumsq(int n)
{
    return (n * (2 * n + 1) * (n + 1)) / 6;
}

void sol()
{
    csq[1] = 0;
    for(int i = 2; i <= 110; i++)
        csq[i] = csq[i - 1] + sumsq(i - 1);
}

int main()
{
    sol();

    int N;
    cin >> N;
    cout << csq[N] << endl;

    return 0;
}
