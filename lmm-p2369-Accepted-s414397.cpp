#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long huge;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        huge a, b, c;
        cin >> a >> b >> c;

        huge A[6];
        A[0] = (a + b) * c;
        A[1] = (a + c) * b;
        A[2] = (b + c) * a;
        A[3] = (a * b) + c;
        A[4] = (a * c) + b;
        A[5] = (b * c) + a;

        sort(A, A + 6);
        cout << A[0] << ' ' << A[5] << endl;
    }

    return 0;
}
