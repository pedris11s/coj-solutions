#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int mk[150];

int main()
{
    int K, t;
    cin >> K >> t;
    for(int i = 1; i <= K; i++)
        mk[i] = i;
    int size;
    while(t--)
    {
        int ni;
        cin >> ni;
        size = 0;
        for(int i = 0; i <= K; i += ni)
        {
            //cout << "marque " << i << ' ' << mk[i]<<  endl;
            mk[i] = (1 << 30);
            size++;
        }
        sort(mk + 1, mk + K + 1);
        /*for(int i = 1; i <= K; i++)
            cout << mk[i] << ' ';
        cout <<  endl;*/

    }
    //cout << "------------------\n";
    for(int i = 1; i <= K; i++)
        if(mk[i] == (1 << 30))
            break;
        else
            cout << mk[i] << endl;

    return 0;
}
