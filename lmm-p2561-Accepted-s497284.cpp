#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100005;

int N, K;
int T1[MAXN], T2[MAXN];
string cad;

bool is_ok(int n, int* T)
{
        for(int i = n; i <= N; i++)
        {
            int d = T[i] - T[i - n];
            if(d <= K && cad.size() - n - 1 >= K - d)
                return true;
        }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {

        cin >> K >> cad;
        cad = "+" + cad;
        N = cad.size() - 1;

        fill(T1, T1 + N + 1, 0);
        fill(T2, T2 + N + 1, 0);

        for(int i = 1; i <= N; i++)
        {
            T1[i] = T1[i - 1] + (cad[i] == '<');
            T2[i] = T2[i - 1] + (cad[i] == '>');
        }

        //caso '>>>>' # 1
        int ini = 1, fin = N;
        while(fin - ini >= 3)
        {
            int mid = (ini + fin) / 2;
            if(is_ok(mid, T2))
                ini = mid;
            else
                fin = mid - 1;
        }
        int sol1 = fin;
        while(!is_ok(sol1, T2))
            sol1--;


        //caso '<<<<<' # 2
        ini = 1, fin = N;
        while(fin - ini >= 3)
        {
            int mid = (ini + fin) / 2;
            if(is_ok(mid, T1))
                ini = mid;
            else
                fin = mid - 1;
        }
        int sol2 = fin;
        while(!is_ok(sol2, T1))
            sol2--;

        cout << max(sol1, sol2) << endl;
    }

    return 0;
}


