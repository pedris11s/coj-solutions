#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 20005;

int divp[MAXN];

bool prime(int n)
{
    if(n == 0 || n == 1)return false;
    if(n == 2)return true;
    if(n % 2 == 0)return false;

    for(int i = 3; i * i <= n; i +=  2)
        if(n % i == 0)
            return false;

    return true;
}

int main()
{
    //precalculo:
    for (int i = 1 ; i <= MAXN ; i++)
        for (int j = i ; j <= MAXN ; j += i)
            if(prime(i))
                divp[j] = i;

    int t;
    cin >> t;
    int maxf = 0;
    int maxn = 0;
    for(int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        if(divp[n] > maxf)        
        {
            maxn = n;
            maxf = divp[n];
        }   
        //cout << divp[n] << endl;
    }
    cout << maxn << endl;
    cin >> t;
    return 0;
}
