#include <cstdio>
#include <iostream>
#include <map>
#include <string>

using namespace std;

const int MAXN = 40007;

/*
2
TFTF
TTTF
TFTF
TFTF
*/

int NUM[MAXN];
map <int, int> freq;

int main()
{
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        string cad;
        cin >> cad;
        for(int j = 0; j < cad.size(); j++)
            if(cad[j] == 'T')
                NUM[i] = NUM[i] + (1 << j);
    }

    long long sol = 0;

    for(int i = 0; i < N; i++)
    {
        if((freq.find(NUM[i]) != freq.end()))
            sol += freq[NUM[i]];

        for(int j = 0; j < 30; j++)
        {
            int x = NUM[i];
            if(x & (1 << j))
                x -= (1 << j);
            else
                x += (1 << j);

            if((freq.find(x) != freq.end()))
                sol += freq[x];

            for(int k = j + 1; k < 30; k++)
            {
                int y = x;
                if(y & (1 << k))
                    y -= (1 << k);
                else
                    y += (1 << k);

                if((freq.find(y) != freq.end()))
                    sol += freq[y];
            }
        }
        if(!(freq.find(NUM[i]) != freq.end()))
            freq[NUM[i]] = 1;
        else
            freq[NUM[i]]++;
    }
    cout << sol << endl;

    /*for(int i = 0; i < N; i++)
        cout << NUM[i] << ' ';
    cout << endl;*/

    return 0;
}
