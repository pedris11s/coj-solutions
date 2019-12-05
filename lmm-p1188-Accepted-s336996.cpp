#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int sum(string a, string b)
{
    int sol = 0;
    for(int i = 0; i < a.length(); i++)
        for(int j = 0; j < b.length(); j++)
            sol += (a[i] - 48) * (b[j] - 48);

    return sol;
}

int main()
{
    string a, b;
    cin >> a >> b;

    int sol = sum(a,b);
    cout << sol << endl;

    return 0;
}

