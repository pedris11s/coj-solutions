#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

typedef pair <int, int> coo;
typedef pair <int, string> par;


int n;
string L[3], word;
vector <par> A;

coo dame_coo(char a)
{
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < L[i].size(); j++)
            if(L[i][j] == a)
                return coo(i, j);
}

int mod(int n)
{
    if(n < 0)
        return -n;
    return n;
}

int dist(coo a, coo b)
{
    int dx = mod(a.first - b.first);
    int dy = mod(a.second - b.second);
    return dx + dy;
}

int main()
{
    L[0] = "qwertyuiop";
    L[1] = "asdfghjkl";
    L[2] = "zxcvbnm";

    //coo x = dame_coo('o');
    //cout << x.first << ' ' << x.second << endl;

    int t;
    cin >> t;
    while(t--)
    {
        A.clear();
        cin >> word >> n;
        for(int i = 0; i < n; i++)
        {
            string cad;
            cin >> cad;
            A.push_back(par(0, cad));
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < word.size(); j++)
            {
                coo a = dame_coo(word[j]);
                coo b = dame_coo(A[i].second[j]);
                //cout << "dist " << word[i] << ' ' << A[i].second[j] << ' ' << dist(a, b) << endl;
                A[i].first += dist(a, b);
            }
        }

        sort(A.begin(), A.end());
        for(int i = 0; i < n; i++)
            cout << A[i].second << ' ' << A[i].first << endl;
    }


    return 0;
}
