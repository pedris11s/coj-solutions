#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 30005;

char cows[MAXN];

int main()
{
    //freopen("d.in", "r", stdin);

    int N;
    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> cows[i];

    int begin = 1, end = N;
    vector <char> sol;
    sol.push_back('0');
    for(int i = 1; i <= N; i++)
    {
        int b = begin;
        int e = end;

        while(cows[b] == cows[e] && b < e)
            b++, e--;

        if(cows[b] <= cows[e])
        {
            sol.push_back(cows[begin]);
            begin++;
        }
        else if(cows[b] > cows[e])
        {
            sol.push_back(cows[end]);
            end--;
        }
    }

    //for(int i = 0; i < sol.size(); i++)
    //    cout << sol[i];

    //cout << endl;

    for(int i = 1; i <= N; i++)
    {
        cout << sol[i];
        if(i % 80 == 0)
            cout << endl;
    }
    return 0;
}

