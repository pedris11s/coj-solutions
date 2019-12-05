#include <bits/stdc++.h>

using namespace std;

int R, C, M[2007][2007],sol;

bool checkDer(int a, int b){
    int v = M[a][b];
    for(int j = b + 1; j < C; j++)
        if(M[a][j] >= v)
            return false;
    return true;
}

bool checkIzq(int a, int b){
    int v = M[a][b];
    for(int j = b - 1; j >= 0; j--)
        if(M[a][j] >= v)
            return false;
    return true;
}

bool checkArr(int a, int b){
    int v = M[a][b];
    for(int i = a - 1; i >= 0; i--)
        if(M[i][b] >= v)
            return false;
    return true;
}

bool checkAba(int a, int b){
    int v = M[a][b];
    for(int i = a + 1; i < R; i++)
        if(M[i][b] >= v)
            return false;
    return true;
}

int main(){

    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> R >> C;
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++){
            cin >> M[i][j];
        }
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++){
            sol += checkDer(i, j);
            sol += checkIzq(i, j);
            sol += checkArr(i, j);
            sol += checkAba(i, j);
        }

    cout << sol << "\n";

    return 0;
}
