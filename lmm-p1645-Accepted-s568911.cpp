#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair <int, int> par;

const int MAXN = 1e5 + 7;

par A[MAXN];
int sol[MAXN * 10];

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int N;
        cin >> N;

        memset(sol, 0, sizeof sol);

        //int MIN_A = (1e6 + 3), MAX_B = -1;
        for(int i = 1; i <= N; i++)
        {
            cin >> A[i].first >> A[i].second;
            //MIN_A = min(MIN_A, A[i].first);
            //MAX_B = max(MAX_B, A[i].second);
        }
        int super_sol = 0;
        for(int i = N; i >= 1; i--)
        {
            int fin = A[i].second;
            int ini = A[i].first;
            bool fuevista = false;
            while (fin >= ini){
                if (sol[fin] == 0){
                    sol[fin] = i;
                    fuevista = true;
                    fin--;
                }
                else
                    fin = A[sol[fin]].first - 1;
            }
            if (fuevista)
                super_sol++;
        }
        cout << super_sol << endl;
    }


    return 0;
}
