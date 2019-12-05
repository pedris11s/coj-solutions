#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

typedef long long huge;
typedef pair <int, huge> par;

map <string, par> freq1;
map <string, par> freq2;

vector <string> PALABRAS1;
vector <string> PALABRAS2;

const int MAXN = 1000;

bool mk[MAXN];

string sol = "";

int main()
{
    //freopen(".out", "w", stdout);

    int t;
    cin >> t;
    for(int k = 0; k < t; k++)
    {
        freq1.clear();
        freq2.clear();

        PALABRAS1.clear();
        PALABRAS2.clear();

        int N;
        cin >> N;
        for(int i = 0; i < N; i++)
        {
            string pizza;
            cin >> pizza;
            int ci;
            cin >> ci;
            for(int j = 0; j < ci; j++)
            {
                string ingred;
                cin >> ingred;
                freq1[ingred].first++;
                freq1[ingred].second |= 1 << i;
            }

            cin >> ci;
            for(int j = 0; j < ci; j++)
            {
                string ingred;
                cin >> ingred;
                freq2[ingred].first++;
                freq2[ingred].second |= 1 << i;
            }
        }

        map <string, par> :: iterator it;
        for(it = freq1.begin(); it != freq1.end(); it++)
            PALABRAS1.push_back((*it).first);

        for(it = freq2.begin(); it != freq2.end(); it++)
            PALABRAS2.push_back((*it).first);



        for(int i = 0; i < PALABRAS1.size(); i++)
        {
            for(int j = 0; j < PALABRAS2.size(); j++)
                if(freq1[PALABRAS1[i]].first == freq2[PALABRAS2[j]].first    // Misma frecuencia
                && freq1[PALABRAS1[i]].second == freq2[PALABRAS2[j]].second) // Misma Pizzas
                    sol = sol + "(" + PALABRAS1[i] + ", " + PALABRAS2[j] + ")\n";
                    //cout << "(" << PALABRAS1[i] << ", " << PALABRAS2[j] << ")\n";
        }
        if(k != (t - 1))
            sol = sol + "\n";
            //cout << "\n";

    }
    cout << sol;

    return 0;
}
