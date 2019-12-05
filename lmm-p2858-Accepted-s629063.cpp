#include <cstdio>
#include <iostream>

using namespace std;

const int MOD = 1e9 + 7;

string cad, str_sol;

int to_bin(int a, int b)
{
    int num = 0, p = 1;
    for(int i = b; i >= a; i--)
    {
        num = (num + (cad[i] - '0') * p) % MOD;
        p = (p * 2) % MOD;
    }
    return num;
}

string to_str(int num)
{
    string sol = "";
    if(num == 0)
        return sol = "0";

    while(num > 0)
    {
        sol = char((num % 10) + '0') + sol;
        num /= 10;
    }
    return sol;
}

int main()
{
    //freopen("bit.in", "r", stdin);
    cin >> cad;

    int i = 0, j = 0;
    while(i < cad.size())
    {
        while(cad[j] <= 'z' && cad[j] >= 'a')
            str_sol += cad[j++];

        i = j;
        while(cad[j] == '0' || cad[j] == '1')
            j++;
        str_sol += to_str(to_bin(i, j - 1));
        i = j;
    }
    cout << str_sol << endl;
    //cout << str_sol.substr(0, str_sol.size() - 1) << endl;

    return 0;
}
