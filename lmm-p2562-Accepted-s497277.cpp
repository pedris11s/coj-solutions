#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> primes;
vector <int> exp;

int N;

void factoriza(int n)
{
    primes.clear();
    exp.clear();
    int e = 0;
    if(n % 2 == 0)
    {
        primes.push_back(2);
        while(n % 2 == 0)
        {
            n /= 2;
            e++;
        }
        exp.push_back(e);
    }
    for(int i = 3; i * i <= n; i += 2)
        if(n % i == 0)
        {
            e = 0;
            primes.push_back(i);
            while(n % i == 0)
            {
                n /= i;
                e++;
            }
            exp.push_back(e);
        }
    if(n > 1)
    {
        primes.push_back(n);
        exp.push_back(1);
    }
}

int main()
{

    while(cin >> N)
    {
        factoriza(N);
        for(int i = 0; i < primes.size(); i++)
            printf("(%d(%d))", primes[i], exp[i]);
        printf("\n");
    }

    return 0;
}
