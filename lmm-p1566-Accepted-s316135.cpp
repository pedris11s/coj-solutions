#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    long long n;
    while(true)
    {
         cin >> n;
         if(n == 0)
              break;
         
         cout << (n * (2 * n + 1) * (n + 1)) / 6 << endl;
    }
    return 0;
}
