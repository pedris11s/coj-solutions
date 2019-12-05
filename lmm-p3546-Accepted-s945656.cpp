#include <cstdio>
#include <iostream>

using namespace std;

const int MAX = 1005;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    int ind; double sol = (1 << 30);
    for(int i = 1; i <= n; i++)
    {
        double p, c;
        cin >> p >> c;

        double pr = (double)(p / c);
        if(pr < sol)
        {
            sol = pr;
            ind = i;
        }
    }
    cout << ind << "\n";

    return 0;
}
