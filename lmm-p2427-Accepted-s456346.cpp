#include <cstdio>
#include <iostream>

using namespace std;

typedef long long huge;

const int MAXN = 1000001;

bool comp[MAXN];

void criba()
{
    for(int i = 4; i < MAXN; i += 2)
        comp[i] = true;

    for(int i = 3; i * i <= MAXN; i += 2)
        if(!comp[i])
            for(int j = i * i; j <= MAXN; j += i)
                comp[j] = true;
}

int main()
{
    criba();

    huge a, b;
    while(cin >> a >> b)
    {
        if(a == b && a == 0)
            break;

        huge sol = 0;
        for(int i = a; i <= b; i++)
            if(!comp[i])
                sol++;

        cout << sol << endl;
    }

    return 0;
}
