#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1003;

int Sum[MAXN];

bool is_prime(int n)
{
    if(n == 0 || n == 1)return false;
    if(n == 2)return true;
    if(n % 2 == 0)return false;

    for(int i = 3; i * i <= n; i += 2)
        if(n % i == 0)
            return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int cont = 1;
    for(int i = 1; i < MAXN; i++)
    {
        int suma = 0;
        for(int j = 1; j <= i; j++)
        {
            suma += (is_prime(cont)) ? cont : 0;
            cont++;
        }
        Sum[i] = suma;

    }

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout << Sum[n] << "\n";
    }

    return 0;
}
