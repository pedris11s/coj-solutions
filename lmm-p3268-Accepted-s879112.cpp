#include <bits/stdc++.h>

using namespace std;

string givemecandie(char c)
{
    if(c == 'R')
        return "Rat";
    if(c == 'M')
        return "Milk";
    return "Fish";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string cad;
    cin >> cad;

    string candie = "";
    int sol = 0, i = 0, j = 0;
    while(i < cad.size())
    {
        while(cad[i] == cad[j])
            j++;

        if(j - i == sol)
        {
            if((candie == "Fish" && cad[i] != 'F') || (candie == "Milk" && cad[i] == 'R'))
            {
                candie = givemecandie(cad[i]);
            }
        }
        if(j - i > sol)
        {
            sol = j - i;
            candie = givemecandie(cad[i]);
        }
        i = j;
    }
    cout << sol  << " " << candie << endl;
    return 0;
}
