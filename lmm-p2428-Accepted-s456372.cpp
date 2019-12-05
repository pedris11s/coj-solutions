#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 2 * 1000000001;

vector <int> squares;

int main()
{
    int fin = sqrt(MAXN) + 2;

    for(int i = 0; i <= fin; i++)
        squares.push_back(i * i);

    while(true)
    {
        int n;
        cin >> n;
        if(n == 0)
            break;

        if(binary_search(squares.begin(), squares.end(), n))
            cout << sqrt(n) << endl;
        else
        {
            int ind = upper_bound(squares.begin(), squares.end(), n) - squares.begin();
            cout << sqrt(squares[ind]) << endl;
        }
    }
    return 0;
}
