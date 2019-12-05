//by pter

#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for(int i = 0; i < t; i++)
    {
        int B, ntrans, money;
        char trans;
        cin >> B >> ntrans;
        for(int j = 0; j < ntrans; j++)
        {
            cin >> trans >> money;
            if(trans == 'C')
                B += money;
            else
                B -= money;
        }
        cout << B << endl;
    }
    return 0;
}
