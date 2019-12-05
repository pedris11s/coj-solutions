#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>

using namespace std;

map <string, int> freq;

const string INF = "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ";

int main()
{
    string cad;
    cin >> cad;

    for(int i = 7; i < cad.size(); i++)
    {
        string ncad = cad.substr(i - 7, 8);
        freq[ncad]++;
    }

    map <string, int> :: iterator it;
    int max = 1; string sol = "Solution was not found\n";
    for(it = freq.begin(); it != freq.end(); it++)
    {
        if((*it).second > max)
        {
            max = (*it).second;
            //if((*it).first < sol)
            sol = (*it).first;
        }
    }
    cout << sol << endl;


    return 0;
}
