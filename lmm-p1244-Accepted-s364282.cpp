//by pter

#include <cstdio>
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

char to_lower(char a)
{
	if(isupper(a))
		return a += 32;
	
	return a;
}

bool correct(string s)
{
	int size = s.length();
	char c = to_lower(s[0]);
	
	int i = 1;
	char aux;
	while(i < size)
	{
		if(s[i] == ' ')
		{
			aux = to_lower(s[i + 1]);
			if(c != aux)
				return false;
		}	
		i++;
	}
	return true;
}

int main()
{
	while(true)
	{
		string s;
		getline(cin, s);
		
		if(s == "*")
			break;
		
		if(correct(s))
			cout << "Y\n";
		else
			cout << "N\n";
	}
	
	return 0;
}
