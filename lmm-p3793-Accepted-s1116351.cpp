#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e3 + 5;

typedef long long LL;

struct par {
	LL first, second;
	bool operator < (const par &X)const {
        if(first == X.first)
            return second > X.second;
        return first > X.first;
    }
};

priority_queue <par> cola;

int ad[MAXN];
string med[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;

        string cad;
        for(int i = 1; i <= n ; i++)
        {
            int x;
            cin >> cad >> x;
            med[i] = cad;
            ad[i] = x;
            par p; p.first = x; p.second = i;
            cola.push(p);
        }
        int i = 0;
        while(i < k)
        {
            par p = cola.top();
            cola.pop();
            cout << p.first << " " << med[p.second] << "\n";
            p.first += (LL)(ad[p.second]);
            cola.push(p);
            i++;
        }
        while(!cola.empty())
            cola.pop();
    }

    return 0;
}

