#include <cstdio>
#include <iostream>
#include <map>

const int MAXN = 2501;

using namespace std;

int N;
map <string, int> mk;
string order[MAXN];
string user[MAXN];
int a[MAXN];

int lowbit(int x)
{
    return x & -x;
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
         cin >> order[i];
         mk[order[i]] = i;
    }

    for(int i = 0; i < N; i++)
         cin >> user[i];

    int sol = 0;
    for(int i = 0; i < N; i++)
    {
         for(int j = mk[user[i]] + 1; j <= N; j += lowbit(j))
              a[j]++;

         for(int j = mk[user[i]]; j >= 1; j -= lowbit(j))
              sol += a[j];
    }
    cout << sol << "/" << N * (N - 1) / 2 << endl;
    return 0;
}
