//by julio

#include  <cstdio>
#include  <iostream>
#include  <cmath>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int sum = a + b;
    int res = a - b;
    int mul = a * b;
    int amp = a / b;
    int mod = a % b;
    printf("%d\n%d\n%d\n%d\n%d\n", sum, res, mul, amp, mod);
    return 0;
}
