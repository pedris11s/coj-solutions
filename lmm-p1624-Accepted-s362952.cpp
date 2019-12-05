//by pter

#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int dp[1005];
char a[1005];

bool pal(char s[], int i, int j)
{
	while(i < j)
	{
		if(s[i] != s[j])
			return false;
		i++;
		j--;
	}
	return true;
}

int main()
{
	cin >> &a[1];
	int size = strlen(a + 1);
	
	dp[0] = 0;
	for(int i = 1; i <= size; i++)
	{
		int min = i;
		for(int j = i; j >= 1; j--)
			if(pal(a, j, i) && dp[j - 1] < min)
				min = dp[j - 1];
				
		dp[i] = min + 1;
	}
	cout << dp[size] << endl;
	return 0;
}
