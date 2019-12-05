#include <cstdio>
#define i64 long long

const int
      MaxV = 10000 + 10,
	  MaxE = 100000 + 10;

const i64
      MOD = 1000000000LL;
	  
int V, E;
int i, j;
int node;
i64 dp[MaxV];
int dest[MaxE];
int next[MaxE];
bool bio[MaxV];
bool exc[MaxV];
int first[MaxV];
int color[MaxV];

void dfs(int x) {
    color[x] = 1;
	for (int k = first[x]; k != -1; k = next[k])
	    if (!color[dest[k]])
		     dfs(dest[k]);
		else if (color[dest[k]] == 1) {
		    node = dest[k];
			return;
		}
	color[x] = 2;
}

void traverse(int x) {
    bio[x] = true;
	for (int k = first[x]; k != -1; k = next[k])
	    if (!bio[dest[k]]) traverse(dest[k]);
}

i64 memo(int x) {
    if (bio[x])
	    return dp[x];
	i64 ret = 0;
	bio[x] = true;
	for (int k = first[x]; k != -1; k = next[k])
	    ret += memo(dest[k]);
	if (ret >= MOD) {
	    exc[x] = true;
		ret = ret % MOD;
	}
	for (int k = first[x]; !exc[x] && k != -1; k = next[k])
	    if (exc[dest[k]]) exc[x] = true;
	return dp[x] = ret;
}

int main() {
    
	scanf("%d%d", &V, &E);

	for (i = 0; i < V; i++)
	    first[i] = -1;

	for (i = 0; i < E; i++) {
	    int a, b;
	    scanf("%d%d", &a, &b); //inverse
		dest[i] = a-1;
		next[i] = first[b-1];
		first[b-1] = i;
	}

	/* find to answer 'inf' */
	node = -1;
	dfs(1);

	if (node != -1)
	    traverse(node);

	if (bio[0]) {
	    printf("inf\n");
		return 0;
	}

	/* looking for a concrete answer */
	for (i = 0; i < V; i++)
	    bio[i] = false;

	dp[0]  = 1;
	bio[0] = true;
	exc[0] = false; //is dp[x] over 9 digits?

	memo(1);

	if (exc[1])
	     printf("%.9lld\n", dp[1]);
	else printf("%lld\n", dp[1]);

    fflush(stdout);
    return 0;

}