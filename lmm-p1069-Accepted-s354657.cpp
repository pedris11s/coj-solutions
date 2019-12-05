//by pter

#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int e, f, c;
        cin >> e >> f >> c;
        int sum = e + f;
        if(sum == 0 || c == 1)
        {
            cout << "0\n";
            continue;
        }
        else
        {
            int cont = 0;
            while(sum >= c)
            {
                cont += sum / c;
                sum =sum / c + (sum % c);
            }
            cout << cont << endl;
        }
    }
    return 0;
}
