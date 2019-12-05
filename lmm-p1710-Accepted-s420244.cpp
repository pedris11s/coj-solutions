#include <cstdio>
#include <iostream>

using namespace std;

int factoriza(int n)
{
    int sol = 0;
    if(n % 2 == 0)
    {
        sol++;
        while(n % 2 == 0)
            n /= 2;
    }
    for(int i = 3; i * i <= n; i += 2)
        if(n % i == 0)
        {
            sol++;
            while(n % i == 0)
                n /= i;
        }
    if(n > 1)
        sol++;
    return sol;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout << factoriza(n) << endl;;
    }
    return 0;
}
