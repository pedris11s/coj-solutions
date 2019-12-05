#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

typedef long long LL;

map <LL, LL> freq;

LL A[10005], B[105], sol[105];

int main()
{
    int L;
    cin >> L;
    for(int i = 1; i <= L; i++)
        cin >> B[i];

    int N;
    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> A[i];

    for(int j = 1; j <= L; j++)
    {
        LL sum = 0;
        freq[0] = 1;
        for(int i = 1; i <= N; i++)
        {
            sum += A[i];
            sol[j] += freq[sum - B[j]];
            freq[sum]++;
        }
        freq.clear();
    }
    for(int i = 1; i <= L; i++)
        cout << sol[i] << endl;

    return 0;
}
