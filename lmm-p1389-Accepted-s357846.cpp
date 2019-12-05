#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int pal(string s, int i, int j)
{
    int ii = i;
    int jj = j;

    while(i < j)
    {
        if(s[i] != s[j])
            return -1;

        i++;
        j--;
    }
    return jj - ii + 1;
}

int main()
{
    string s;
    cin >> s;
	
	//cout << pal(s, 0, s.length() - 1);
	
    string aux;
    int ii = 0;
    int jj = 0;
    int maxl = 0;
    for(int i = 0; i < s.length(); i++)
    {
        for(int j = i + 1; j < s.length(); j++)
        {
            int p = pal(s, i, j);
            if(p != -1 && p > maxl)
            {
                maxl = p;
                ii = i;
                jj = j;
            }
        }
    }
    for(int i = ii; i <= jj; i++)
		cout << s[i];
	cout << endl;

    return 0;
}
