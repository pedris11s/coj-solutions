#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>

using namespace std;

int mk[30];
int freq[30];
string d, b, l;
bool cheater;
vector <char> sol;

void diet()
{
    for(int i = 0; i < b.length(); i++) 
    {
        if(freq[b[i] - 64] > 1 || mk[b[i] - 64] == 0)
        {
            cheater = true;
            break;
        }
        else if(mk[b[i] - 64] == 1)
            mk[b[i] - 64]++;
        
    }
    for(int i = 0; i < l.length(); i++) 
    {
        if(freq[l[i] - 64] > 1 || mk[l[i] - 64] == 0)
        {
            cheater = true;
            break;
        }
        else if(mk[l[i] - 64] == 1)
            mk[l[i] - 64]++;
    }
    if(!cheater)
    {
        for(int i = 0; i < d.length(); i++)
            if(mk[d[i] - 64] == 1)
                sol.push_back(d[i]);

        sort(sol.begin(), sol.end());    
    }
}

int main()
{   
    int t;
    cin >> t;
    while(t--)
    {
        fill(mk, mk + 30, 0);
        fill(freq, freq + 30, 0);
        sol.clear();
        cheater = false;
              
        cin >> d >> b >> l;
        for(int i = 0; i < d.length(); i++)
        {
            mk[d[i] - 64] = 1;           
            freq[d[i] - 64]++;
        }
        diet();
        if(cheater)
            cout << "CHEATER\n";
        else
        {
            for(int i = 0; i < sol.size(); i++)
                cout << sol[i];
            cout << endl;
        }
            
    }
    //scanf("%");
    return 0;
}
