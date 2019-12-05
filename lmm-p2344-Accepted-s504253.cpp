#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct country{
    string pais;
    int gold, silver, bronze;

    country(string x, int a, int b, int c)
    {
        pais = x;
        gold = a;
        silver = b;
        bronze = c;
    }

    bool operator < (const country &X)const
    {
        if(gold != X.gold)
            return gold > X.gold;

        if(silver != X.silver)
            return silver > X.silver;

        if(bronze != X.bronze)
            return bronze > X.bronze;

        return pais < X.pais;
    }
};

vector <country> A;

int main()
{
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    string cad, sol = "";
    int g, s, b;
    bool flag = false;
    while(true)
    {
        A.clear();
        while(true)
        {
            cin >> cad;
            if(cad == "@" || cad == "#")
            {
                if(cad == "#")
                    flag = true;

                sort(A.begin(), A.end());
                for(int i = 0; i < A.size(); i++)
                    if(i != A.size() - 1)
                        cout << A[i].pais << "\n";
                    else
                        cout << A[i].pais;
                    //sol += A[i].pais + "\n";
                //sol += "@\n";
                break;
            }
            else
            {
                cin >> g >> s >> b;
                A.push_back(country(cad, g, s, b));
            }
        }
        if(!flag)
        {
            cout << "\n@\n";
            //cout << sol.substr(0, sol.size() - 2);
        }
        else
            exit(0);
    }

    return 0;
}
