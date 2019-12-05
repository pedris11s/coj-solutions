#include <cstdio>
#include <queue>
#include <iostream>
#include <cstdlib>

using namespace std;

const int MAXN = 350;

int R, C, K;
int A[MAXN], TA_Array[MAXN];
int M[MAXN][MAXN], TA[MAXN][MAXN];

int main()
{
    while(cin >> R >> C >> K)
    {
        if(R == C && C == K && K == 0)
            break;

        for(int i = 1; i <= R + 5; i++)
        {
            for(int j = 1; j <= C; j++)
                M[i][j] = TA[i][j] = 0;
        }

        for(int i = 1; i <= C + 5; i++)
            A[i] = TA_Array[i] = 0;

        for(int i = 1; i <= R; i++)
            for(int j = 1; j <= C; j++)
            {
                char c;
                cin >> c;
                if(c == 'X')
                    M[i][j] = 0;
                else
                    M[i][j] = 1;
            }
        //Tabla Acumulativa
        for(int j = 1; j <= C + 1; j++)
            for(int i = 1; i <= R; i++)
                TA[i][j] = TA[i - 1][j] + M[i][j];

        int answer = MAXN * MAXN;
        for(int i = 1; i <= R; i++)
            for(int j = i; j <= R; j++)
            {
                for(int k = 1; k <= C + 1; k++)
                    A[k] = TA[j][k] - TA[i - 1][k];

                queue<int> q;
                while (!q.empty()) q.pop();
                int sum = 0;
                for (int k = 1 ; k <= C ; k++)
                {
                    q.push(A[k]);
                    sum += A[k];
                    while (!q.empty() && sum >= K){
                        if ((j - i + 1) * q.size() < answer)
                            answer = (j - i + 1) * q.size();

                        sum -= q.front();
                        q.pop();
                    }
                }
            }
            cout << answer  << endl;
        }


    return 0;
}
