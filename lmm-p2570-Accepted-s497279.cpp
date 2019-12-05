#include <cstdio>
#include <iostream>

using namespace std;

int N;

int reverse()
{
    int num = 0;
    while(N > 0)
    {
        num = num * 10 + N % 10;
        N /= 10;
    }
    return num;
}

int main()
{
    while(cin >> N)
    {
        int aux = N;
        if(reverse() > aux)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
