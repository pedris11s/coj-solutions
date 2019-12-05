#include <cstdio>
#include <iostream>

using namespace std;

typedef long long huge;

huge cat[100];

int main()
{
    cat[0] = 1;
    cat[1] = 1;
    for(int i = 1; i < 35; i++)
    {
        for(int j = 0; j <= i; j++)
            cat[i + 1] += cat[j] * cat[i - j];
    }
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout << cat[n / 2] << endl;
    }



    return 0;
}
