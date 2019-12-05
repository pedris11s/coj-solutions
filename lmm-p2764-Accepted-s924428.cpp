#include <bits/stdc++.h>

using namespace std;

int N;
map <int, int> mk;
map <int, vector <int> > adlist;
map <int, vector <int> > :: iterator it;;

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int x, r;
        cin >> x >> r;
        int a = x - r;
        int b = x + r;
        adlist[a].push_back(b);
        adlist[b].push_back(a);
    }

    int comp = 0;
    for(it = adlist.begin(); it != adlist.end(); it++)
        if(!mk[(*it).first])
        {
            comp++;
            mk[(*it).first] = true;
            queue <int> cola;
            cola.push((*it).first);
            while(!cola.empty())
            {
                int nod = cola.front();
                cola.pop();

                for(int i = 0; i < adlist[nod].size(); i++)
                {
                    int nn = adlist[nod][i];
                    if(!mk[nn]){
                        mk[nn] = true;
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
