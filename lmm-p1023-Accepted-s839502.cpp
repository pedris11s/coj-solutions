#include <bits/stdc++.h>

using namespace std;

float M[13];

int main()
{
    //freopen(".in", "r", stdin);

    int ind = 1;
    while(ind <= 12)
    {
        cin >> M[ind];
        ind++;
    }

    ind = 1;float suma = 0;
    while(ind <= 12)
        suma = suma + M[ind++];

    cout << "$" << suma / 12 << endl;



    return 0;
}
