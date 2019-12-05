#include <cstdio>
#include <iostream>

using namespace std;

typedef long long huge;

bool comp[100];

void criba()
{
    for(int i = 2; i * i <= 60; i++)
        if(!comp[i])
            for(int j = i * i; j <= 60; j += i)
                comp[j] = i;
}

int main()
{
    criba();

    huge n;
    while(cin >> n)
    {
        if(n == 0)
            break;

        huge sol = 1;
        for(int i = 2; i <= n; i++)
            if(!comp[i])
                sol *= i;

        cout << sol << endl;
    }

    return 0;
}
