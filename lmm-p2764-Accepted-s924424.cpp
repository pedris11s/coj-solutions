#include <bits/stdc++.h>

using namespace std;

typedef pair <bool, vector <int> > par;

int N;
map <int, par> adlist;
map <int, par> :: iterator it;

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int x, r;
        cin >> x >> r;
        int a = x - r;
        int b = x + r;
        adlist[a].second.push_back(b);
        adlist[b].second.push_back(a);
    }

    int comp = 0;
    for(it = adlist.begin(); it != adlist.end(); it++)
        if(!(*it).second.first)
        {
            comp++;
            (*it).second.first = true;
            queue <int> cola;
            cola.push((*it).first);
            while(!cola.empty())
            {
                int nod = cola.front();
                cola.pop();

                for(int i = 0; i < adlist[nod].second.size(); i++)
                {
                    int nn = adlist[nod].second[i];
                    if(!adlist[nn].first)
                    {
                        adlist[nn].first = true;
                        cola.push(nn);
                    }
                }
            }
        }
    int nod = adlist.size();
    int sol = 2 * N + comp + 1 - nod;
    cout << sol << "\n";

    return 0;
}
