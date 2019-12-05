//by pter

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    char n[50];
    cin >> n;

    if( next_permutation(n, n + strlen(n)) )
	cout << n << endl;
    else
	cout << "0" << endl;


    return 0;
}
