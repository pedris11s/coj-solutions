#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int A[10], B[10];

int main()
{
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> A[i];

    for(int i = 1; i <= N; i++)
        cin >> B[i];

    sort(B + 1, B + N + 1);

    int sol = 1 << 30;
    do
    {
        int sum = 0;
        for(int i = 1; i <= N; i++)
            sum += (A[i] * B[i]);

        if(sum < sol)
            sol = sum;

    }while(next_permutation(B + 1, B + N + 1));

    cout << sol << endl;

    return 0;
}

