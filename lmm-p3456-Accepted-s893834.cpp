#include <bits/stdc++.h>

using namespace std;

int freq[30];
char p[150], q[150], c;

int main()
{
    int t;
    scanf("%d", &t);
    scanf("%c", &c);
    while (t--)
    {
        scanf("%[^\n]", p);scanf("%c", &c);
        scanf("%[^\n]", q);scanf("%c", &c);

        int szp = strlen(p);
        for(int i = 0; i < szp; i++)
            if(p[i] != ' ')
                freq[p[i] - 'a']++;

        int szq = strlen(q);
        for(int i = 0; i < szq; i++)
            if(q[i]!=' ')
                freq[q[i] - 'a']--;

        bool flag = false;
        for(int i = 0; i <= 27; i++)
        {
            if(freq[i] != 0)
                flag = true;
            freq[i] = 0;
        }
        if(!flag)
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}
