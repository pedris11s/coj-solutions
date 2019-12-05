#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

bool is_SQ(char s[])
{
    if(s[0] == 's')    
         return true;
    else
         return false; 
}

bool is_Rec(char s[])
{
    if(s[0] = 'r') 
         return true;
    else 
         return false;

}
int main()
{
    char s[11];
    scanf("%s",&s);
    int a,b;

    if(is_SQ(s))
    {
         scanf("%d",&a);
         printf("%d\n",a * a);
    }
    else if(is_Rec(s))
    {
         scanf("%d%d",&a,&b);
         printf("%d\n",a * b);
    }
    return 0;
}
