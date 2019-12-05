#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 100;

char A[MAXN], B[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s %s", &A, &B);
        bool hayT = false;
        for(int i = 0; i < strlen(A); i++)
            if(A[i] == 'T')
            {
                hayT = true;
                break;
            }

        if(strstr(A, B) && hayT)
            cout << "Y\n";
        else
            cout << "N\n";

        //cout << A << ' ' <<  B << endl;
    }

    return 0;
}
