#include <bits/stdc++.h>

using namespace std;


int BIT[100005];
int read(int idx)
{
    int r = 0;
    while(idx>0)
    {
        r+=BIT[idx];
        idx-=(idx&-idx);
    }
    return r;
}
void update(int idx)
{
    while(idx<100005)
    {
        BIT[idx]++;
        idx+=(idx&-idx);
    }
}
int arr[100005];
int sol[100005];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(int i = n-1; i >= 0; i--)
    {
        int val = arr[i];
        sol[i] = read(100004)-read(val);
        update(val);
    }
    for(int i = 0; i < n; i++)
    {
        if(i)
        printf(" %d", sol[i]);
        else printf("%d", sol[i]);
    }
    printf("\n");
    return 0;
}
