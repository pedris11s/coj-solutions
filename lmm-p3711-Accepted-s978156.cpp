#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N;
int M[100][100];
bool mk[100];


bool checkFilas()
{
    for(int i = 1; i <= N; i++){
        fill(mk, mk + N + 1, false);
        for(int j = 1; j <= N; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }

    }
    return true;
}

bool checkColum()
{
    for(int i = 1; i <= N; i++)
    {
        fill(mk, mk + N + 1, false);
        for(int j = 1; j <= N; j++){
            if(mk[M[j][i]] == true)
                return false;
            mk[M[j][i]] = true;
        }
    }
}

bool checkCuadrant4()
{
    int R = 2;
    //c1
    fill(mk, mk + N + 1, false);
    for(int i = 1; i <= R; i++)
    {
        for(int j = 1; j <= R; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }
    //c2
    fill(mk, mk + N + 1, false);
    for(int i = 1; i <= R; i++)
    {
        for(int j = 3; j <= 4; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }
    //c3
    fill(mk, mk + N + 1, false);
    for(int i = 3; i <= 4; i++)
    {
        for(int j = 1; j <= 2; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }

    //c4
    fill(mk, mk + N + 1, false);
    for(int i = 3;  i <= 4; i++)
    {
        for(int j = 3; j <= 4; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }

    return true;
}


bool checkCuadrant9()
{
    int R = 3;

    //c1
    fill(mk, mk + N + 1, false);
    for(int i = 1; i <= 3; i++)
    {
        for(int j = 1; j <= 3; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }

    //c2
    fill(mk, mk + N + 1, false);
    for(int i = 1; i <= R; i++)
    {
        for(int j = 4; j <= 6; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }
    //c3
    fill(mk, mk + N + 1, false);
    for(int i = 1; i <= R; i++)
    {
        for(int j = 7; j <= 9; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }
    //c4
    fill(mk, mk + N + 1, false);
    for(int i = 4; i <= 6; i++)
    {
        for(int j = 1; j <= 3; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }
    //c5
    fill(mk, mk + N + 1, false);
    for(int i = 4; i <= 6; i++)
    {
        for(int j = 4; j <= 6; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }
    //c6
    fill(mk, mk + N + 1, false);
    for(int i = 4; i <= 6; i++)
    {
        for(int j = 7; j <= 9; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }
    //c7
    fill(mk, mk + N + 1, false);
    for(int i = 7; i <= 9; i++)
    {
        for(int j = 1; j <= 3; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }
    //c8
    fill(mk, mk + N + 1, false);
    for(int i = 7; i <= 9; i++)
    {
        for(int j = 4; j <= 6; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }
    //c9
    fill(mk, mk + N + 1, false);
    for(int i = 7; i <= 9; i++)
    {
        for(int j = 7; j <= 9; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }

    return true;
}

bool checkCuadrant16()
{
    int R = 4;
    //c1
    fill(mk, mk + N + 1, false);
    for(int i = 1; i <= 4; i++)
    {
        for(int j = 1; j <= 4; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }
    //c2
    fill(mk, mk + N + 1, false);
    for(int i = 1; i <= 4; i++)
    {
        for(int j = 5; j <= 8; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }
    //c3
    fill(mk, mk + N + 1, false);
    for(int i = 1; i <= 4; i++)
    {
        for(int j = 5; j <= 8; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }
    //c3
    fill(mk, mk + N + 1, false);
    for(int i = 1; i <= 4; i++)
    {
        for(int j = 9; j <= 12; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }
    //c4
    fill(mk, mk + N + 1, false);
    for(int i = 1; i <= 4; i++)
    {
        for(int j = 13; j <= 16; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }
    //c5
    fill(mk, mk + N + 1, false);
    for(int i = 5; i <= 8; i++)
    {
        for(int j = 1; j <= 4; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }
    //c6
    fill(mk, mk + N + 1, false);
    for(int i = 5; i <= 8; i++)
    {
        for(int j = 5; j <= 8; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }
    //c7
    fill(mk, mk + N + 1, false);
    for(int i = 5; i <= 8; i++)
    {
        for(int j = 9; j <= 12; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }
    //c8
    fill(mk, mk + N + 1, false);
    for(int i = 5; i <= 8; i++)
    {
        for(int j = 13; j <= 16; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }
    //c9
    fill(mk, mk + N + 1, false);
    for(int i = 9; i <= 12; i++)
    {
        for(int j = 1; j <= 4; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }
    //c10
    fill(mk, mk + N + 1, false);
    for(int i = 9; i <= 12; i++)
    {
        for(int j = 5; j <= 8; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }
    //c11
    fill(mk, mk + N + 1, false);
    for(int i = 9; i <= 12; i++)
    {
        for(int j = 9; j <= 12; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }
    //c12
    fill(mk, mk + N + 1, false);
    for(int i = 9; i <= 12; i++)
    {
        for(int j = 13; j <= 16; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }
    //c13
    fill(mk, mk + N + 1, false);
    for(int i = 13; i <= 16; i++)
    {
        for(int j = 1; j <= 4; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }
    //c14
    fill(mk, mk + N + 1, false);
    for(int i = 13; i <= 16; i++)
    {
        for(int j = 5; j <= 8; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }
    //c15
    fill(mk, mk + N + 1, false);
    for(int i = 13; i <= 16; i++)
    {
        for(int j = 9; j <= 12; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }
    //c16
    fill(mk, mk + N + 1, false);
    for(int i = 13; i <= 16; i++)
    {
        for(int j = 13; j <= 16; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }


    return true;
}

bool checkCuadrant25()
{
    int R = 5;
    //c1
    fill(mk, mk + N + 1, false);
    for(int i = 1; i <= 5; i++)
    {
        for(int j = 1; j <= 5; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }
    //c2
    fill(mk, mk + N + 1, false);
    for(int i = 1; i <= 5; i++)
    {
        for(int j = 6; j <= 10; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }
    //c3
    fill(mk, mk + N + 1, false);
    for(int i = 1; i <= 5; i++)
    {
        for(int j = 11; j <= 15; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }
    //c1
    fill(mk, mk + N + 1, false);
    for(int i = 1; i <= 5; i++)
    {
        for(int j = 16; j <= 20; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }
    //c1
    fill(mk, mk + N + 1, false);
    for(int i = 1; i <= 5; i++)
    {
        for(int j = 21; j <= 25; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }
    //c1
    fill(mk, mk + N + 1, false);
    for(int i = 6; i <= 10; i++)
    {
        for(int j = 1; j <= 5; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }
    //c1
    fill(mk, mk + N + 1, false);
    for(int i = 6; i <= 10; i++)
    {
        for(int j = 6; j <= 10; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }
    //c1
    fill(mk, mk + N + 1, false);
    for(int i = 6; i <= 10; i++)
    {
        for(int j = 16; j <= 20; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }
    //c1
    fill(mk, mk + N + 1, false);
    for(int i = 6; i <= 10; i++)
    {
        for(int j = 21; j <= 25; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }
    //c1
    fill(mk, mk + N + 1, false);
    for(int i = 11; i <= 15; i++)
    {
        for(int j = 1; j <= 5; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }
    //c1
    fill(mk, mk + N + 1, false);
    for(int i = 11; i <= 15; i++)
    {
        for(int j = 6; j <= 10; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }
    //c1
    fill(mk, mk + N + 1, false);
    for(int i = 11; i <= 15; i++)
    {
        for(int j = 11; j <= 15; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }
    //c1
    fill(mk, mk + N + 1, false);
    for(int i = 11; i <= 15; i++)
    {
        for(int j = 16; j <= 20; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }
    //c1
    fill(mk, mk + N + 1, false);
    for(int i = 11; i <= 15; i++)
    {
        for(int j = 21; j <= 25; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }
    //c1
    fill(mk, mk + N + 1, false);
    for(int i = 16; i <= 20; i++)
    {
        for(int j = 1; j <= 5; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }
    //c1
    fill(mk, mk + N + 1, false);
    for(int i = 16; i <= 20; i++)
    {
        for(int j = 6; j <= 10; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }
    //c1
    fill(mk, mk + N + 1, false);
    for(int i = 16; i <= 20; i++)
    {
        for(int j = 11; j <= 15; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }
    //c1
    fill(mk, mk + N + 1, false);
    for(int i = 16; i <= 20; i++)
    {
        for(int j = 16; j <= 20; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }
    //c1
    fill(mk, mk + N + 1, false);
    for(int i = 16; i <= 20; i++)
    {
        for(int j = 21; j <= 25; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }
    //c1
    fill(mk, mk + N + 1, false);
    for(int i = 21; i <= 25; i++)
    {
        for(int j = 1; j <= 5; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }
    //c1
    fill(mk, mk + N + 1, false);
    for(int i = 21; i <= 25; i++)
    {
        for(int j = 6; j <= 10; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }
    //c1
    fill(mk, mk + N + 1, false);
    for(int i = 21; i <= 25; i++)
    {
        for(int j = 11; j <= 15; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }
    //c1
    fill(mk, mk + N + 1, false);
    for(int i = 21; i <= 25; i++)
    {
        for(int j = 16; j <= 20; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }
    //c1
    fill(mk, mk + N + 1, false);
    for(int i = 21; i <= 25; i++)
    {
        for(int j = 21; j <= 25; j++){
            if(mk[M[i][j]] == true)
                return false;
            mk[M[i][j]] = true;
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(".in", "r", stdin);

    int t;
    cin >> t;
    while(t--)
    {

        cin >> N;
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++)
                cin >> M[i][j];

        if(checkFilas() && checkColum()){
            if(N == 1)
                cout << "yes\n";
            else if(N == 4 && checkCuadrant4())
                cout << "yes\n";
            else if(N == 9 && checkCuadrant9())
                cout << "yes\n";
            else if(N == 16 && checkCuadrant16())
                cout << "yes\n";
            else if(N == 25 && checkCuadrant25())
                cout << "yes\n";
            else
                cout << "no\n";
        }
        else
            cout << "no\n";

    }

    return 0;
}
