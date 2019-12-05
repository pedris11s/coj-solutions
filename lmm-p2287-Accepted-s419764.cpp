#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1000001;

int N, D, M;
int jobs[MAXN];

bool check(int cm)
{
    int j = 1;
    for(int i = 1; i <= N; i++)
    {
        int cant = 0;
        if(jobs[j] > i)
            continue;
        if(i - jobs[j] > D)
            return false;
        while(jobs[j] <= i && j <= M && cant < cm)
            cant++, j++;
        if(j > M)
            return true;
    }
    return true;
}

int main()
{
    cin >> N >> D >> M;
    for(int i = 1; i <= M; i++)
        cin >> jobs[i];

    sort(jobs + 1, jobs + M + 1);

    int ini = 1, fin = M;
    while(fin - ini > 5)
    {
        int mit = (ini + fin) / 2;
        if(!check(mit))
            ini = mit + 1;
        else
            fin = mit - 1;
    }
    while(!check(ini++));

    cout << ini - 1 << endl;

    return 0;
}
