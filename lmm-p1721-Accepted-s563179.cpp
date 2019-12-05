#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 7;

const string D[] = {"out", "output", "puton", "in", "input", "one"};


int N;
string A[MAXN];
bool mk[MAXN];

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string cad;
        cin >> cad;

        int Size = cad.size();
        cad = " " + cad;

        fill(mk, mk + Size + 2, false);

        mk[0] = true;
        bool flag = false;
        for(int i = 1; i <= Size; i++)
        {
            for(int j = 0; j < 6; j++)
                if(cad.substr(i, D[j].size()) == D[j] && mk[i - 1])
                {
                    mk[i + D[j].size() - 1] = true;
                    flag = true;
                }
            if(!flag)
            {
                cout << "NO\n";
                break;
            }
        }
        if(!flag)
            continue;

        if(mk[Size])
            cout << "YES\n";
        else
            cout << "NO\n";

    }


    return 0;
}
