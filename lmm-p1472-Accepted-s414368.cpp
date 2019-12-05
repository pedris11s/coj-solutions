#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

typedef long long huge;

int dig[5] = {0, 2, 3, 5, 7};
huge T[100];

huge cant_dig(huge n)
{
    huge i = 4, sum = 0, sol = 0;
    while(n - sum > 0)
    {
        sum += i;
        i*= 4;
        sol++;
        T[sol] = sum;
    }
    return sol;
}

string sol(int n)
{
    char N[30];
    huge sum = 0;

    int size = cant_dig(n);
    n -= T[size - 1];
    for(int i = 0; i < size; i++)
        for(int j = 1; j <= 4; j++)
        {
            huge p = pow(4, size - i - 1);
            if(sum + p >= n)
            {
                N[i] = dig[j] + '0';
                break;
            }
            else
                sum += p;
        }
    N[size] = '\0';
    return N;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        huge N;
        cin >> N;
        cout << sol(N) << endl;;
    }

    return 0;
}
