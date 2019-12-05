#include <bits/stdc++.h>

using namespace std;

int N, A[100], porgusto;
double minvo1, minvo2, dif;

bool is_sol(){

    for(int i = 0; i < N; i++)
    {
        if(A[i] >= minvo1)
            return true;

        if(A[i] >= minvo2)
        {
            for(int j = 0; j < N; j++)
                if(i != j)
                    if(A[i] - A[j] < dif)
                        goto DALE;

            return true;
        }

        DALE:
            porgusto++;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N;


    double sum = 0;
    for(int i = 0; i < N; i++)
    {
        cin >> A[i];
        sum += A[i];
    }

    minvo1 = sum * (0.45);
    minvo2 = sum * (0.4);
    dif = sum * (0.1);

    if(is_sol())
        cout << "1\n";
    else
        cout << "2\n";

    return 0;
}
