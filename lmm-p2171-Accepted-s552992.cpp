#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int freq[1000001];

int main()
{
    int N;
    cin >> N;


    int min_a = (1 << 30), max_b = 0;
    for(int i = 1; i <= N; i++)
    {
        int a, b;
        cin >> a >> b;
        freq[a]++;
        freq[b + 1]--;
        min_a = min(a, min_a);
        max_b = max(b, max_b);
    }

    int sol = 0;
    for(int i = min_a; i <= max_b; i++)
    {
        freq[i] += freq[i - 1];
        if(freq[i] > sol)
            sol = freq[i];
    }
    cout << sol << endl;


    return 0;
}
