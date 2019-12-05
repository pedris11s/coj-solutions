#include <cstdio>
#include <iostream>

using namespace std;

int sum_div(int n)
{
    int sum = 0;
    for(int i = 1; i <= n / 2; i++)
        if( n % i == 0)
            sum += i;

    return sum;
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        int sum = sum_div(n);

        if(sum < n)
            cout << "Deficient" << endl;
        else if(sum == n)
            cout << "Perfect" << endl;
        else
            cout << "Abundant" << endl;
    }

    return 0;
}
