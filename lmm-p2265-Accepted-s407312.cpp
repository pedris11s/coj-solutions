#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

int a[21];
map <long long, bool> mk;

int main()
{
    long long n, po;
    cin >> n >> po;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    int sol = 0;
    mk[0] = true;
    for(int i = 1; i <= n; i++)
        for(int j = po; j >= a[i]; j--)
            if(mk[j - a[i]])
                mk[j] = true;

    if(mk[po] == true)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
