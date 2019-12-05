#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int base_n(string cad, int b)
{
    int p = 1;
    int num = 0;
    for(int i = cad.size() - 1; i > -1; i--)
    {
        num = num + int(cad[i] - '0') * p;
        //cout << cad[i] - '0' << endl;
        p *= b;
        //cout << num << ' ' << p << endl;
    }
    return num;
}

int main()
{
//    freopen("digits.in", "r", stdin);
//    freopen("digits.out", "w", stdout);

    string b2, b3;
    cin >> b2 >> b3;

    for(int i = 0; i < b2.size(); i++)
        for(int j = 0; j < b3.size(); j++)
            for(int k = 1; k < 3; k++)
            {
                char a = b2[i], b = b3[j];
                b2[i] = ((b2[i] - '0') + 1) % 2 + '0';
                b3[j] = ((b3[j] - '0') + k) % 3 + '0';
                if(base_n(b2, 2) == base_n(b3, 3))
                {
                    cout << base_n(b3, 3) << endl;
                    exit(0);
                }
                b2[i] = a;
                b3[j] = b;
            }
    return 0;
}
