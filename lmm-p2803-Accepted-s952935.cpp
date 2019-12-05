#include <cstdio>
#include <iostream>

using namespace std;

int N;
char M[100][100];

bool check()
{
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++){
            if(M[i][j] == M[i - 1][j])return false;
            if(M[i][j] == M[i + 1][j])return false;
            if(M[i][j] == M[i][j + 1])return false;
            if(M[i][j] == M[i][j - 1])return false;
        }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        for(int i = 1; i < 100; i++)
            for(int j = 1; j < 100; j++)
                M[i][j] = '#';

        cin >> N;
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++)
                cin >> M[i][j];

        if(!check())
            cout << "NO\n";
        else
            cout << "YES\n";
    }

	return 0;
}
