#include <bits/stdc++.h>

using namespace std;

bool board[8][8] = {
                    {0, 1, 0, 1, 0, 1, 0, 1},
                    {1, 0, 1, 0, 1, 0, 1, 0},
                    {0, 1, 0, 1, 0, 1, 0, 1},
                    {1, 0, 1, 0, 1, 0, 1, 0},
                    {0, 1, 0, 1, 0, 1, 0, 1},
                    {1, 0, 1, 0, 1, 0, 1, 0},
                    {0, 1, 0, 1, 0, 1, 0, 1},
                    {1, 0, 1, 0, 1, 0, 1, 0},
                   };

int main()
{
    /*for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
            cout << board[i][j];
        cout << endl;
    }*/

    int t;
    cin >> t;
    while(t--)
    {
        string pos;
        cin >> pos;

        int f = pos[0] - 'a';
        int c = pos[1] - '0' - 1;
        if(board[f][c])
            cout << "BLACK\n";
        else
            cout << "WHITE\n";
    }
    //cout << f << ' ' << c << endl;

    return 0;
}



