#include <iostream>

using namespace std;

const int C[2] = {4, 7};

int main()
{
    int K;
    cin >> K;

    int e = 1;
    while ((1 << e) - 2 < K)
        e++;
    e--;

    K -= ((1 << e) - 1);
    for (int i = e - 1 ; i > -1 ; i--)
        cout << C[((1 << i) & K) != 0];

    return 0;
}