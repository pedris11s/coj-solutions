#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

bool mk_a[26], mk_b[26];

int main()
{
    string a, b;
    cin >> a >> b;

    for(int i = 0; i < a.size(); i++)
        mk_a[a[i] - 'A'] = true;

    for(int i = 0; i < b.size(); i++)
        mk_b[b[i] - 'A'] = true;

    string sol_a = "";
    for(int i = 0; i < a.size(); i++)
        if(!mk_b[a[i] - 'A'])
            sol_a += a[i];

    string sol_b = "";
    for(int i = 0; i < b.size(); i++)
        if(!mk_a[b[i] - 'A'])
            sol_b += b[i];

    string sol_a_b = "";
    for(int i = 0; i < a.size(); i++)
        if(mk_a[a[i] - 'A'] && mk_b[a[i] - 'A'])\
            sol_a_b += a[i];

    cout << "First:" << sol_a << "\n";
    cout << "Second:"<< sol_b << "\n";
    cout << "First&Second:"<< sol_a_b << "\n";
	return 0;
}
