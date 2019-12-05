#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef pair <string, string> par;

int main()
{
    int n;
    cin >> n;
    int cont1 = 0, cont2 = 0;
    while(n--)
    {
        string a, b;
        cin >> a >> b;

        if(a == "rock" && b == "scissors")
            cont1++;
        else if(b == "rock" && a == "scissors")
            cont2++;
        else if(a == "rock" && b == "paper")
            cont2++;
        else if(b == "rock" && a == "paper")
            cont1++;
        else if(a == "paper" && b == "scissors")
            cont2++;
        else if(b == "paper" && a == "scissors")
            cont1++;
    }
    if(cont1 == cont2)
        cout << "tied\n";
    else if(cont1 > cont2)
        cout << "A win\n";
    else
        cout << "B win\n";



	return 0;
}
