#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

//int A[1000];

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        map <int, int> freq;

        int sum = 0, sol = 0;
        freq[0] = 1;

        int N, x;
        cin >> N;
        for(int i = 0; i < N; i++)
        {
            cin >> x;
            sum += x;
            sol += freq[sum - 47];
            freq[sum]++;
        }
        cout << sol << endl;
    }

	return 0;
}
