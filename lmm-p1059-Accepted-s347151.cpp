#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string bin(int n)
{
    string bin;

    while(n > 0)
    {
        bin = ((n & 1) ? "1" : "0") + bin;
        n /= 2;
    }
    //reverse(bin.begin(), bin.end());
    return bin;
}

int main()
{
    while(true)
    {
        int n;
        cin >> n;

        if(n == 0)
            break;

        int cb = __builtin_popcount(n);
        string s = bin(n);
        cout << "The parity of " << bin(n) << " is " << cb  << " (mod 2)." << "\n";;
    }
    return 0;
}
