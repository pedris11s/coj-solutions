//by pter

#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string n;
        cin >> n;
        int size = n.length();
        n = "-" + n;
        int ini = (int)sqrt(size);
        string sol = "";
        for(int i = ini; i > 0; i--)
        {
            for(int j = i; j <= size; j += ini)
                sol += n[j];
        }
        cout << sol << endl;

    }

    return 0;
}
