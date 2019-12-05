#include <cstdio>
#include <iostream>

using namespace std;

int freq[14];
bool mk[10000];

int main()
{
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        int id, d, m, y;
        scanf("%d %d/%d/%d", &id, &d, &m, &y);

        if(!mk[id])
        {
            freq[m]++;
            mk[id] = true;
        }
    }
    for(int i = 1;  i <= 12; i++)
        cout << i << ' ' << freq[i] << endl;

    return 0;
}

