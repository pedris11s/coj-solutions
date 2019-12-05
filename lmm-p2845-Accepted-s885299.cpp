#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(true)
    {
        double x, y;
        cin >> x >> y;
        if(x == 0 || y == 0){
            cout << "AXIS\n";
            if(x == y)
                break;
        }
        if(x > 0 && y > 0)
            cout << "Q1\n";
        else if(x < 0 && y > 0)
            cout << "Q2\n";
        else if(x < 0 && y < 0)
            cout << "Q3\n";
        else if(x > 0 && y < 0)
            cout << "Q4\n";

    }
    return 0;
}
