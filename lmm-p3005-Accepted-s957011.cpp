#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50005;

int N, M;
int sol[3], T[MAXN];
queue <int> cola;
vector <int> adlist[MAXN];

int main()
{
    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        if(a == b){
            cout << "-1";
            return 0;
        }
        adlist[a].push_back(b);
        adlist[b].push_back(a);
    }

    int answer = 0;
    for(int i = 1; i <= N; i++)
    {
        if(T[i] != 0 )continue;
        T[i] = 1;
        sol[1]++;
        cola.push(i);
        while(!cola.empty()){
            int nodo = cola.front();
            cola.pop();
            for(int j = 0; j < adlist[nodo].size(); j++)
            {
                int nn = adlist[nodo][j];
                if(T[nn] == 0){
                    cola.push(nn);
                    T[nn] = (T[nodo] == 1 ? 2 : 1);
                    sol[T[nn]]++;
                }
                if(T[nn] == T[nodo]){
                    cout << "-1\n";
                    return 0;
                }
            }
        }

        answer += max(sol[1], sol[2]);
        sol[1] = sol[2] = 0;
    }

    cout << answer << "\n";
    return 0;
}
