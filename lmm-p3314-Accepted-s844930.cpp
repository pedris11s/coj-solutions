#include <bits/stdc++.h>

using namespace std;

int Pos[17];
int Tab[107];
int Dados[1007];
bool mk[17];

int main()
{
    //freopen("x.in", "r", stdin);
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int N, S, D;
        scanf("%d%d%d", &N, &S, &D);
        for(int i = 1; i <= S; i++)
            scanf("%d", &Tab[i]);

        for(int i = 1; i <= D; i++)
            scanf("%d", &Dados[i]);

        for(int i = 1; i <= N; i++)
            Pos[i] = 1;

        fill(mk, mk + N + 1, false);

        int player = 1;
        vector <int> sol;
        for(int i = 1; i <= D; i++)
        {
            while(mk[player])
            {
                player++;
                if(player > N)
                    player = 1;
            }
            Pos[player] += Dados[i];
            Pos[player] += Tab[Pos[player]];
            if(Pos[player] == S)
            {
                mk[player] = true;
                sol.push_back(player);
                if(sol.size() == N)
                    break;
            }
            player++;
            if(player > N)
                player = 1;
        }
        if(sol.size() == 0)
            printf("-1\n");
        else
        {
            printf("%d", sol[0]);
            for(int i = 1; i < sol.size(); i++)
                printf(" %d", sol[i]);
            printf("\n");
        }
    }

    return 0;
}
