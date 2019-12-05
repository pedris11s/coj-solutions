#include <cstdio>
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>

using namespace std;

map <char, int> freq;

int main()
{
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        string cad;
        cin >> cad;
        freq[cad[0]]++;
    }
    map <char, int> :: iterator it;
    string sol = "";
    for(it = freq.begin(); it != freq.end(); it++)
    {
        if((*it).second >= 5)
            sol += (*it).first;
    }
    sort(sol.begin(), sol.end());
    if(sol == "")
        cout << "PREDAJA\n";
    else
        cout << sol << endl;
    
    //system("pause");
    
    return 0;
}
