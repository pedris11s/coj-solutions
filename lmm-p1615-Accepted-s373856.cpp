//by pter

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int dig[10];

void count(int n)
{
    while(n > 0)
    {
        dig[n % 10]++;
        n /= 10;
    }
}

int main()
{
    int k = 1;
    while(true)
    {
        int a, b;
        cin >> a >> b;
		
		if(a == 0)
            break;

		if(a > b)
			swap(a, b);
		
        fill(dig, dig + 10, 0);

        for(int i = a; i <= b; i++)
            count(i);

        cout << "Case " << k << ": ";
        for(int i = 0; i < 9; i++)
            cout << i << ":" <<dig[i] << ' ';

        cout << "9:" << dig[9] << '\n';
        k++;
    }

    return 0;
}
