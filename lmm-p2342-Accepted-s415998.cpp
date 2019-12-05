#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string A, B;

        cin >> n;
        cin >> A;

        int sum = 0;
        int s1 = (-1 << 30), s2 = (-1 << 30);
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            sum += x;
            s1 = max (sum, s1);
            if (sum < 1)
                sum = 0;
        }
        cin >> B;
        sum = 0;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            sum += x;
            s2 = max (sum, s2);
            if (sum < 1)
            sum = 0;
        }
        if (s1 == s2)
            cout << "Tied " << s1 << endl;
        else if (s1 < s2)
            cout << B << " " << s2 << endl;
        else
            cout << A << " " << s1 << endl;
    }

    return 0;
}
