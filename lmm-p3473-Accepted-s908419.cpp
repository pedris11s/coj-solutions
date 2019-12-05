#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int arr[4];
int main()
{
    for(int i = 0; i < 4; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr,arr+4);
    int rect = 0;
    for(int i = 0; i < 4; i++)
    {
        if(arr[i]==90)rect++;
    }
    if(rect==2)
    {
        printf("right\n");
    }else if(arr[0]==arr[1] && arr[2]==arr[3] && arr[1]!=arr[3])
    {
        printf("isosceles\n");
    }else{
        printf("none of the previous\n");
    }



    return 0;
}
