#include <bits/stdc++.h>

using namespace std;

multiset<int> aux;

bool prime(int n)
{
    if(n == 0 )return false;
    if(n == 2 || n==1)return true;
    if(n % 2 == 0)return false;

    for(int i = 3; i * i <= n; i += 2)
        if(n % i == 0)
            return false;
    return true;
}

int main()
{
    int a,b;
    scanf("%d%d", &a,&b);
    while(a>0)
    {
        aux.insert(a%b);
        a/=b;
    }
    vector <int> aux2;
    multiset<int> :: iterator it;

    for(it = aux.begin(); it != aux.end(); it++)
        if(prime((*it)))
            aux2.push_back((*it));

    printf("%d", aux2.size());
    for(int i = 0; i < aux2.size(); i++)
        printf(" %d", aux2[i]);

    printf("\n");
    return 0;
}
