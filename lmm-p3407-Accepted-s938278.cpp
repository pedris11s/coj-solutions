#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> par;

const int MAXN = 3000;

par A[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> A[i].first >> A[i].second;

    sort(A, A + N);
    int sol = 0; double med = (double)INT_MAX;
    for(int i = 0; i < N - 2; i++)
    {
        double x = (double)(A[i].second + A[i + 1].second + A[i + 2].second) / (double)3;
        if(x <= med)
        {
            med = x;
            sol = i;
        }
    }
    cout << A[sol].first << " " << A[sol + 1].first << " " << A[sol + 2].first << "\n";
    return 0;
}
