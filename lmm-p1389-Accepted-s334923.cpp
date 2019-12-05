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
	
	
	for(int l = size; l > 1; l--)
		for(int ind = 0; ind <= size - l; ind++)
		{
			bool flag = true;
			string a = s.substr(ind, l);
			int ini = 0; 
			int fin = a.length() - 1;
			while(ini < fin)
			{
				if(a[ini] != a[fin])
				{
					flag = false;
					break;
				}
				
				ini++;
				fin--;
			}
			if(flag)
			{
				cout << a << endl;
				return 0;
			}
		}
		
	
	//int pal = is_pal(s, 0, size - 1);
	//cout << pal << endl;
	
	return 0;
}

