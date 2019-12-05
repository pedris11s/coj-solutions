#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    long long n, t;

    cin>> t;
    for(int i = 0;i < t;i++){
        cin>> n;
        cout<< -250 + 192 + 250 * n << "\n";
    }
    return 0;
}
