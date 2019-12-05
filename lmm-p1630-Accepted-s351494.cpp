#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int A[15];
int D[15];

int main()
{
    while(true)
    {
        int a, d;
        cin >> a >> d;
        
        if(a == 0)
            break;
            
        for(int i = 0; i < a; i++)
            cin >> A[i];
        
        for(int i = 0; i < d; i++)
            cin >> D[i];
            
        sort(A, A + a);
        sort(D, D + d);
        
        if(A[0] < D[0] || A[0] < D[1])
            cout << "Y" << endl;
        else
            cout << "N" << endl;
    }
    return 0;
}
