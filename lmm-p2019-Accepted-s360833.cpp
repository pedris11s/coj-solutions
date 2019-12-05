//by pter

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

bool prime(int n)
{
    if(n == 0 || n == 1)return false;
    if(n == 2)return true;
    if(n % 2 == 0)return false;
    for(int i = 3; i * i <= n; i += 2)
        if(n % i == 0)
            return false;

    return true;
}

int to_int(char a[])
{
    int sum = 0;
    int p = 1;
    for(int i = strlen(a) - 1; i >= 0; i--)
    {
        sum += (a[i] - 48) * p;
        p *= 10;
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;

    char a[15];
    sprintf(a, "%d", n);
    sort(a, a + strlen(a));

    int sol = 0;
    do
    {
        int aux = to_int(a);
        if(prime(aux))
            sol++;

    }while(next_permutation(a, a + strlen(a)));

    cout << sol << endl;
    return 0;
}
