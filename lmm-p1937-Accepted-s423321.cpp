#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

typedef long long huge;

int main()
{
    huge N;
    int k = 1;
    while(true)
    {
        cin >> N;
        if(N == 0)
            break;

        huge sol = (3 + sqrt(9.0 + 8.0 * (N - 1))) / 2;
        cout << "Case " << k++ << ": "<< sol + 1 << endl;
    }

    return 0;
}
