//by pter

#include <cstdio>
#include <iostream>

using namespace std;

const int MAX = 10;

int n,cont;
bool mk[42];

int main()
{
    for(int i = 0; i < MAX; i++)
    {
         scanf("%d",&n);
         mk[n % 42] = true;
    }
    
    for(int i = 0; i < 42; i++)
         cont += mk[i];
              
    if(cont == 1)
         cont = 0;
              
    printf("%d\n",cont);
    return 0;
}
