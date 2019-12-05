//by pter

#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 1005;

int dp[MAXN];
char a[MAXN];
bool pal[MAXN][MAXN];

int main()
{
	cin >> &a[1];
	int size = strlen(a + 1);

	for(int i = 1; i <= size; i++)
		pal[i][i] = true;
	
	for(int i = 1; i < size; i++)
		if(a[i] == a[i + 1])
			pal[i][i + 1] = true;
		else
			pal[i][i + 1] = false;
	
	for(int l = 3; l <= size; l++)
		for(int pi = 1; pi <= size - l + 1; pi++)
			if(a[pi] == a[pi + l - 1])
				pal[pi][pi + l - 1] = pal[pi + 1][pi + l - 2];
					
	dp[0] = 0;
	for(int i = 1; i <= size; i++)
	{
		int min = i;
		for(int j = i; j >= 1; j--)
			if(pal[j][i] && dp[j - 1] < min)
				min = dp[j - 1];
				
		dp[i] = min + 1;
	}
	cout << dp[size] << endl;
		
	return 0;
}
