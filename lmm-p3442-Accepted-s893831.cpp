#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

char cad[30];

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    scanf("%s", cad);

    int size = strlen(cad);
    if(size % 2 == 0)
        printf("error\n");
    else
    {
        //cout << "\n\n";
        int a = size / 2, b = a;
        for(int k = 0; k < size; k++)
        {
            if(k == 0 || k == size - 1){
                printf("%s\n", cad);
                continue;
            }

            for(int i = 0; i < size; i++)
                printf("%c", (a <= i && i <= b) ? ' ' : cad[i]);
            printf("\n");

            if(k == size / 2)
                a += 2, b -= 2;

            if(k > size / 2)
                a++, b--;
            else
                a--, b++;
        }
    }
    return 0;
}
