#include <bits/stdc++.h>

using namespace std;

#define val first
#define sum second.first
#define id second.second.first
#define type second.second.second

const int MAX = 30;

string A, B;
int N, M, canta[MAX], cantA[MAX], cantb[MAX], cantB[MAX], sol;

bool check()
{
    for(int i = 0; i < 27; i++)
        if(canta[i] != cantb[i])
            return false;
    for(int i = 0; i < 27; i++)
        if(cantA[i] != cantB[i])
            return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    cin >> A >> B;

    for(int i = 0; i < N; i++)
    {
        if(islower(A[i]))canta[A[i] - 'a']++;
        else cantA[A[i] - 'A']++;
    }

    for(int i = 0; i < N; i++)
    {
        if(islower(B[i]))cantb[B[i] - 'a']++;
        else cantB[B[i] - 'A']++;
    }

    sol += check();
    for(int i = N; i < M; i++){
        if(islower(B[i]))cantb[B[i] - 'a']++;
        else cantB[B[i] - 'A']++;

        if(islower(B[i - N]))cantb[B[i - N] - 'a']--;
        else cantB[B[i - N] - 'A']--;

        sol += check();
    }
    cout << sol << "\n";

    return 0;
}
