//by pter

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

vector <int> sol(int n)
{
    int cont = 0;
    vector <int> p;
    while(n > 0)
    {
        if(n % 2)
            p.push_back(cont);
        cont++;
        n /= 2;
    }
    return p;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        vector <int> v = sol(n);
        for(int i = 0; i < v.size() - 1; i++)
            cout << v[i] << ' ';

        cout << v[v.size() - 1] << endl;
    }

    return 0;
}
