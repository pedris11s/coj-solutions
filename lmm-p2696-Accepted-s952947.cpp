#include <iostream>

using namespace std;

int n, m, a, b, MAX, c, S[1002], P[1002];
bool M[1002][1002];

int main(){

    cin >> n >> m;
    for (int i = 1; i <= m; i++){
         cin >> a >> b;
         if (!M[a][b])
             S[a]++;
         M[a][b] = true;
         MAX = max (MAX, S[a]);
    }

    for (int i = 1; i <= n; i++)
         if (S[i] == MAX)
             P[++c] = i;
    cout << P[1];
    for (int i = 2; i <= c; i++) cout << " " << P[i];
    cout << endl;

    return 0;
}
