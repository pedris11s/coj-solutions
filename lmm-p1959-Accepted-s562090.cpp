#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1007;

struct trio{
    int pi, si, sum;
    trio(int a = 0, int b = 0, int c = 0){
        pi = a, si = b, sum = c;
    }
    bool operator < (const trio &p)const{
        if(sum != p.sum)
            return sum < p.sum;
    }
}A[MAXN];

int N, X;

int main()
{
    cin >> N >> X;
    for(int i = 0; i < N; i++)
    {
        cin >> A[i].pi >> A[i].si;
        A[i].sum = A[i].pi + A[i].si;
    }
    sort(A, A + N);

    int sol = 0;
    for(int i = 0; i < N; i++)
    {
        int money = X - (A[i].pi / 2 + A[i].si);
        if(money < 0)
            continue;

        int cont = 1;
        for(int j = 0; j < N; j++)
        {
            if(i == j)
                continue;

            if(A[j].pi + A[j].si <= money)
            {
                money -= (A[j].pi + A[j].si);
                cont++;
            }
        }
        sol = max(sol, cont);
    }
    cout << sol << endl;
    /*for(int i = 0; i < N; i++)
        cout << A[i].sum << ' ' << A[i].pi << ' ' << A[i].si << endl;*/

    return 0;
}
