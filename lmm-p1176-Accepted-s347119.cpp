#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> ternary(int n)
{
    vector <int> sol;

    while(n > 0)
    {
        sol.push_back(n % 3);
        n /= 3;
    }
    reverse(sol.begin(), sol.end());
    return sol;
}

int main()
{
    while(true)
    {
        int n;
        cin >> n;

        if(n == -1)
            break;

        vector <int> sol = ternary(n);
        for(int i = 0; i < sol.size(); i++)
            cout << sol[i];
        cout << endl;
    }
    return 0;
}
