#include <bits/stdc++.h>

using namespace std;

char cad[20];

int main()
{
    while(true)
    {
        scanf("%s", cad);

        if(cad[0] == 'E')break;

        int size = strlen(cad);
        for(int i = size - 1; i > -1; i--)
        {
            if(cad[i] != '0'){
                cad[i]--;
                break;
            }
        }
        int sol = atoi(cad);
        printf("%d\n", sol);
    }

    return 0;
}
