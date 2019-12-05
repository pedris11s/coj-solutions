#include <cstdio>
#include <iostream>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool valido(int x, int y)
{
    return x <= 8  && y <= 8 && x >= 1 && y >= 1;
}

int main()
{
    int p, x1, y1, x2, y2;
    while(cin >> p >> x1 >> y1 >> x2 >> y2)
    {
        bool sol = false;
        if(valido(x1, y1) && valido(x2, y2))
        {
            for(int i = 0; i < 4; i++)
            {
                int nx = x1 + dx[i];
                int ny = y1 + dy[i];
                if(valido(nx, ny))
                    if(nx == x2 && ny == y2)
                    {
                        sol = true;
                        break;
                    }
            }
            if(sol)
            {
                if(p == 1)
                    cout << "2\n";
                else
                    cout << "1\n";
            }
            else
                cout << "ERROR\n";
        }
        else
            cout << "ERROR\n";

    }

    return 0;
}
