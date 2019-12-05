//by pter

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int is_pal(string s, int ini, int fin)
{
	int ii = ini;
	int jj = fin;
	while(ini < fin)
	{
		if(s[ini] != s[fin])
			return -1;
		
		ini++;
		fin--;
	}
	return jj - ii + 1;
}

int main()
{
	string s;
	cin >> s;
	
	int size = s.length();
	int ii, jj;
	int max = 0;
	
	for(int i = 0; i < size; i++)
		for(int j = i + 1; j < size; j++)
		{	
			int pal = is_pal(s, i, j);
			if(pal != -1 && pal > max)
			{
				max = pal; 
				ii = i;
				jj = j;
			}
		}
		
	for(int i = ii; i <= jj; i++)
		cout << s[i];
	
	cout << endl;
	//int pal = is_pal(s, 0, size - 1);
	//cout << pal << endl;
	
	return 0;
}

