//by pter

#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 1001;

char a[MAX];

bool is_evil(char a[])
{
    int size = strlen(a);
    int sum = 0;
    bool hay6 = false;

    if(a[size - 1] - 48 & 1)
        return false;


    for(int i = 0; i < size; i++)
    {
        if(a[i] == '-')
            continue;

        sum += a[i] - 48;
        if(a[i] == '6')
            hay6 = true;
    }
    if(hay6 && sum % 6 == 0)
        return true;

    return false;
}

int main()
{
    while(scanf("%s", a) != EOF)
    {
        if(is_evil(a))
            printf("EVIL\n");
        else
            printf("GOOD\n");
    }
    return 0;
}
