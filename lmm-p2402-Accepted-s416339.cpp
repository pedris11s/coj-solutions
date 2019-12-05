#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

struct par{
    int id, d;
    bool operator < (const par &R)const
    {
        if (R.d != d)
            return R.d > d;
        return R.id > id;
    }
}S[20];

int F, C, A[20], p;
char car;

int main(){

    cin >> F >> C;
    for(int i = 1; i <= F; i++)
    {
         for(int j = 1; j <= C; j++)
         {
              cin >> car;
              if(car == '.' || car == 'S' || car == 'F')continue;
              if(S[car - '0'].d == 0)
              {
                  S[car - '0'].d = C - j - 2;
                  S[car - '0'].id = car - '0';
              }
         }
    }

    sort (S + 1, S + 10);

    A[S[1].id] = ++p;
    for (int i = 2; i <= 9; i++)
    {
         if (S[i - 1].d != S[i].d)
              p++;
         A[S[i].id] = p;
    }
    for (int i = 1; i <= 9; i++)
         cout << A[i] << endl;
    return 0;
}
