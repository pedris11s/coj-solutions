#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000007;

int N, A[MAXN];
bool mk[MAXN];
vector <int> adlist[2][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    while(true)
    {
        cin >> N;
        if(N == 0)break;

        for(int i = 0; i < N; i++)
        {
            adlist[0][i].clear();
            adlist[1][i].clear();
            mk[i] = false;
        }

        for(int i = 0; i < N; i++)
        {
            cin >> A[i];
            if(i + A[i] < N)adlist[0][i + A[i]].push_back(i);
            if(i - A[i] >= 0)adlist[1][i - A[i]].push_back(i);
        }

        queue <int> cola;
        cola.push(0);
        mk[0] = true;

        while(!cola.empty()){
            int nodo = cola.front();
            cola.pop();

            int mid = nodo + A[nodo];
            if(mid < N){
                for(int i = 0; i < adlist[1][mid].size(); i++)
                {
                    int nn = adlist[1][mid][i];
                    if(mk[nn])continue;

                    cola.push(nn);
                    mk[nn] = true;
                }
            }

            mid = nodo - A[nodo];
            if(mid >= 0){
                for(int i = 0; i < adlist[0][mid].size(); i++)
                {
                    int nn = adlist[0][mid][i];
                    if(mk[nn])continue;
                    cola.push(nn);
                    mk[nn] = true;
                }
            }
        }

        int sol = N - 1;
        while(!mk[sol])--sol;
        cout << sol << '\n';
    }
    return 0;
}
