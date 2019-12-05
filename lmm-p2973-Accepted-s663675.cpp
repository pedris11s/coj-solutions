#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <vector>

using namespace std;

int to_int(vector <int> v)
{
    int num = 0,  p = 1;
    for(int i = v.size() - 1; i > -1; i--)
    {
        num = (v[i] * p) + num;
        p *= 10;
    }
    return num;
}

int A[20];
bool mk[20];

int main()
{
    //freopen("in.txt", "r", stdin);

    int N;
    while(cin >> N)
    {
        if(N == 0)
            break;

        fill(mk, mk + N, false);

        for(int i = 0; i < N; i++)
            cin >> A[i];

        vector <int> v1, v2;
        sort(A, A + N);

        for(int i = 0; i < N; i++)
            if(A[i] != 0)
            {
                v1.push_back(A[i]);
                mk[i] = true;
                break;
            }

        for(int i = 0; i < N; i++)
            if(A[i] != 0 && !mk[i])
            {
                v2.push_back(A[i]);
                mk[i] = true;
                break;
            }
        int cont = 0;
        for(int i = 0; i < N; i++)
        {
            if(!mk[i])
            {
                if(cont % 2 == 0)
                    v1.push_back(A[i]);
                else
                    v2.push_back(A[i]);
                cont++;
            }
        }
        int n1 = to_int(v1), n2 = to_int(v2);
        //cout << n1  << ' ' << n2 << endl;
        cout << n1 + n2 << endl;;
    }
    return 0;
}
