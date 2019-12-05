#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    int n, arr[100000], aux[100000];
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        aux[i] = arr[i];
    }
    sort(aux, aux+n);
    int sol = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i]!=aux[i])
        {
            bool ok = false;
            for(int j = i+1; j < n; j++)
            {
                if(arr[j] == aux[i] && aux[j] == arr[i])
                {
                    swap(arr[i], arr[j]);
                    sol++;
                    ok = true;
                    break;
                }
            }
            if(!ok)
            {
                for(int j = i+1; j < n; j++)
                {
                     if(arr[j] == aux[i] && arr[j]!=aux[j])
                    {
                        swap(arr[i], arr[j]);
                        sol++;
                        break;
                    }
                }
            }
        }
    }
    printf("%d\n", sol);
	return 0;
}


