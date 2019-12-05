//by pter

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	string s, t;
	while(cin >> s)
	{
		cin >> t;
		int szS = s.length(); 
		int szT = t.length();
		
		int ind = 0;
		for(int i = 0; i < szT; i++)
			if(s[ind] == t[i])
				ind++;
		
		if(ind == szS)
			cout << "Yes\n";
		else
			cout << "No\n";
			
	}
	return 0;
}
