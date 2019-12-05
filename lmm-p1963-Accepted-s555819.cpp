#include <iostream>

using namespace std;

int N, sol, Num[25];

bool no_carrie(int a, int b)
{
    while(a > 0 && b > 0)
    {
        if(a % 10 + b % 10 > 9)
            return false;
        a /= 10;
        b /= 10;
    }
    return true;
}

void combina(int i, int sum, int cont)
{
    if(cont > sol)
        sol = cont;
    if(i >= N || cont + N - i <= sol)
        return;

    if(no_carrie(sum, Num[i]))
        combina(i + 1, sum + Num[i], cont + 1);

    combina(i + 1, sum, cont);
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> Num[i];

    combina(0, 0, 0);
    cout << sol << endl;


    return 0;
}
