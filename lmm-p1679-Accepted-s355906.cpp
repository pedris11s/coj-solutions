//by pter

#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

string player, best_player;
int pa, pj, g, a, ta, tr;

double factor()
{
    return log10(pa) + pj + 2 * g + a - (ta + 2 * tr);
}

int main()
{
    int t;
    cin >> t;
    double maxf = -1000000000;
    while(t--)
    {
        cin >> player >> pa >> pj >> g >> a >> ta >> tr;
        double fact = factor();
        //cout << fact << endl;
        
        if(fact > maxf)
        {
            maxf = fact;
            best_player = player;
        }
    }
    cout << best_player << endl;
    return 0;
}
