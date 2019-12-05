#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

int sol[10];
int input[10];
int mq[10];
bool mk[10];

int main()
{
    int t;

    cin >> t;

    while(t--)
    {
        for(int i = 0; i < 10; i++)
            cin >> input[i];

        for(int i = 0; i < 10; i++)
            mq[i] = abs(i - 9);

        int ind = 10;
        while(ind--)
        {
            for(int j = 0; j < 10; j++)
                if(input[ind] == mq[j])
                {
                    mq[j] = -1;
                    sol[ind] = j;
                    for(int k = 0; k <= j - 1; k++)
                        mq[k]--;
                    break;
                }
        }
        for(int i = 0; i < 9; i++)
            cout << sol[i] << " ";
        cout << sol[9];
        cout << endl;
    }
    return 0;
}
