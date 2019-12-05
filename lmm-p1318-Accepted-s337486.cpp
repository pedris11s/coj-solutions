//by pter

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

string orden;

int main()
{
    int num[3];
    cin >> num[0] >> num[1] >> num[2];
    cin >> orden;

    int aux[3];

    sort(num, num + 3);

    for(int i = 0; i < orden.length(); i++)
    {
        if(orden[i] == 'A')
            aux[i] = num[0];
        else if(orden[i] == 'B')
            aux[i] = num[1];
        else
            aux[i] = num[2];
    }

    for(int i = 0; i < 3; i++)
        if(i == 2)
            cout << aux[i] <<endl;
        else
            cout << aux[i] << " ";

    return 0;
}
