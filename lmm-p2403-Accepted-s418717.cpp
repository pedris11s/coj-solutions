#include <cstdio>
#include <iostream>

using namespace std;

bool damag[20], reserv[20];

int main()
{
    int N, S, R;
    cin >> N >> S >> R;
    for(int i = 0; i < S; i++)
    {
        int a;
        cin >> a;
        damag[a] = true;
    }
    for(int i = 0; i < R; i++)
    {
        int a;
        cin >> a;
        reserv[a] = true;
    }
    for(int i = 1; i <= N; i++)
    {
        if(reserv[i])
        {
            if(damag[i])
                damag[i] = false;
            else if(damag[i - 1])
                damag[i - 1] = false;
            else if(damag[i + 1])
                damag[i + 1] = false;
        }
    }
    int sol = 0;
    for(int i = 1; i <= N; i++)
        if(damag[i])
            sol++;
    cout << sol << endl;

    return 0;
}
