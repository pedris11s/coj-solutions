#include <cstdio>
#include <algorithm>


using namespace std;

#define MAX 105

int N, M;
int dp[MAX][MAX];
bool marked[MAX][MAX];

int main() {

	scanf("%d %d", &N, &M);

	for(int i = 0; i < M; ++i)
	{
		int x,y;
		scanf("%d %d", &x, &y);
		marked[x][y]=1;
	}

	for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= N; ++j)
            dp[i][j] = marked[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];


	int sol = -1;
	for(int i = 1; i <= N; ++i)
        for(int j = i; j <= N; ++j)
            if(M % (j-i+1)==0)
            {
                int c = M / (j-i+1);
                for(int k = c; k <= N; ++k)
                {
                    int col = k-c+1;
                    int cant = dp[j][k] - dp[i-1][k] - dp[j][col-1] + dp[i-1][col-1];
                    if(sol==-1 || M-cant < sol) sol = M-cant;
			}
		}

	printf("%d\n", sol);

	return 0;
}
