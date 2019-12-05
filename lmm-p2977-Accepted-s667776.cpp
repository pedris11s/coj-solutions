#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

bool happy[256];
int appearance[256];

int main()
{
    while(true)
    {
        int N;
        cin >> N;
        if(N == 0)
            break;

        string cad;
        cin >> cad;

        fill(happy, happy + 256, false);
        fill(appearance, appearance + 256, 0);

        int beds = 0, sol = 0;
        for(int i = 0; i < cad.size(); i++)
        {
            appearance[cad[i]]++;
            if(appearance[cad[i]] == 1)
            {
                if(beds < N)
                {
                    beds++;
                    happy[cad[i]] = true;
                }
            }
            else
            {
                if(happy[cad[i]])
                    beds--;
                else
                    sol++;
            }
        }
        if(sol == 0)
            cout << "All customers tanned successfully.\n";
        else
            cout << sol << " customer(s) walked away.\n";
    }

    return 0;
}

