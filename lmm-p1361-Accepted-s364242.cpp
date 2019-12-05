#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    int a, b;
    while(scanf("%d%d", &a, &b) != EOF)
        cout<< ( (int)sqrt( cbrt(b) ) - (int)sqrt( cbrt(a - 1) ) )<<endl;

    return 0;
}
