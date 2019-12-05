#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int a[1005];

int main()
{
    int k;
    cin >> k;
    int cn, d;
    string t;
    for(int i = 0; i < k; i++)
    {
        cin >> cn >> d;
        cin >> t;
        for(int ind = 1; ind <= cn; ind++)
            cin >> a[ind];

        int sum = 0;
        sort(a + 1, a + cn + 1);
        //for(int k = 1; k <= cn; k++)
          //  cout << a[k] << " " ;
        if(t == "regulate")
            for(int j = cn; j >= cn - d + 1; j--)
            {
                sum += a[j];
                //cout << a[j] <<" ";
            }
        else
            for(int j = 1; j <= d; j++)
            {
                sum += a[j];
               // cout << a[j] << endl;
            }

        cout << sum << endl;
    }

    return 0;
}
