#include <cstdio>
#include <iostream>

using namespace std;

string A[3] = {"OIE\0", "IEO\0", "EOI\0"};

int main()
{
    int f, c;
    cin >> f >> c;
    for(int i = 0; i < f; i++)
    {
        int j = 0, k = 0;
        while(j < c)
        {
                cout << A[i % 3][k % 3];
                j++, k++;
        }
        cout << endl;
    }
    return 0;
}
