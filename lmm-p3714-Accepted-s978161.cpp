#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXN = 1e5 + 7;

LL A[MAXN];
int id[256];
bool mk[256];

string to_str(int n)
{
    string num = "";
    if(n == 0)
        return "0";
    while(n > 0)
    {
        num = (char)((n % 10) + '0') + num;
        n /= 10;
    }
    return num;
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //cout << to_str(123) << "\n";

    string cad;
    while(cin >> cad)
    {
        fill(mk, mk + 256, false);
        fill(id, id + 256, false);

        int cont = 1;
        for(int i = 0; i < cad.size(); i++)
            if(!mk[cad[i]]){
                id[cad[i]] = cont++;
                mk[cad[i]] = true;
            }



        string sol = "";
        for(int i = 0; i < cad.size(); i++)
        {
            int x = id[cad[i]];
            sol += to_str(x);
        }
        //cout << sol << "\n";

        for(int i = 0; i < sol.size(); i++)
        {
            if(sol[i] == '2')sol[i] = '5';
            else if(sol[i] == '5')sol[i] = '2';
            else if(sol[i] == '6')sol[i] = '9';
            else if(sol[i] == '9')sol[i] = '6';
        }

        cout << sol << "\n";
    }



    return 0;
}
