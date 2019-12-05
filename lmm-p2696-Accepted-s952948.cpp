#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int freq[1007];
bool mk[1007][1007];

int main()
{
    int N, M;
    cin >> N >> M;

    for(int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        if(!mk[a][b])
            freq[a]++;

        mk[a][b] = true;
    }
    int may = -1;
    for(int i = 1; i <= N; i++)
        may = max(may, freq[i]);

    vector <int> sol;
    for(int i = 1; i <= N; i++)
        if(may == freq[i])
            sol.push_back(i);

    for(int i = 0; i < sol.size(); i++)
    {
        if(i == sol.size() - 1)
            cout << sol[i] << endl;
        else
            cout << sol[i] << ' ';
    }

	return 0;
}
