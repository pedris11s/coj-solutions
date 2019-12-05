//by pter

#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 2000005;
const int MAXNi = 1000005;

int a[MAXN];
int freq[MAXNi];

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int x;
    cin >> x;

    int sol = 0;
    for(int i = 0; i < n; i++)
    {
        if(x >= a[i])
		sol += freq[x - a[i]];
			
		freq[a[i]]++;
	}

    cout << sol << endl;
    return 0;
}
