#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string a, b;
        cin >> a >> b;
        int sol = 0;
        for(int i = 0; i < a.size(); i++)
            if(a[i] != b[i])
                sol++;

        cout << sol << endl;

    }


    return 0;
}
