#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string to_bin(int n)
{
    string bin = "";
    while(n > 0)
    {
        char c = (n % 2 == 0) ? '0' : '1';
        bin = c + bin;
        n /= 2;
    }
    return bin;
}

int to_dec(string n)
{
    int p = 0;
    int num = 0;
    for(int i = n.length() - 1; i > -1; i--)
    {
        if(n[i] == '1')
            num += (1 << p);

        p++;
    }
    return num;
}

int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        string nbin = '0' + to_bin(n);
        next_permutation(nbin.begin(), nbin.end());
        cout << to_dec(nbin) << endl;
    }


    return 0;
}
