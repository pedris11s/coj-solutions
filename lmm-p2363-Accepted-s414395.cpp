//by pter

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    char a[10];
    cin >> a;
    if(next_permutation(a, a + strlen(a)))
        cout << a << endl;
    else
        cout << "0" << endl;

    return 0;
}
