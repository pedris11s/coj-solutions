//by pter

#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 505;

int ed[MAXN][MAXN];
char a[MAXN], b[MAXN];

int main()
{
	gets(a + 1);
	gets(b + 1);
		
	int sza = strlen(a + 1);
	int szb = strlen(b + 1);
	
	for(int i = 1; i <= sza; i++) ed[i][0] = i;
	for(int j = 1; j <= szb; j++) ed[0][j] = j;
	
	for(int i = 1; i <= sza; i++)
		for(int j = 1; j <= szb; j++)
			if(a[i] == b[j])
				ed[i][j] = ed[i - 1][j - 1];
			else
				ed[i][j] = min(ed[i - 1][j - 1], min(ed[i - 1][j], ed[i][j - 1])) + 1;
	
	cout << ed[sza][szb] << endl;
		
	return 0;
}
