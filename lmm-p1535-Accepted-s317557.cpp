#include <cstdio>

using namespace std;

int a[15];

bool is_increase(int a[])
{
    int i = 0;
    while(i < 9)
    {
        if(a[i] > a[i + 1])
            return false;

        i++;
    }
    return true;
}

bool is_decrease(int a[])
{
    int i = 0;
    while(i < 9)
    {
        if(a[i] < a[i + 1])
            return false;

        i++;
    }
    return true;
}

int main()
{
    int t;
    scanf("%d", &t);
    printf("Lumberjacks:\n");
    for(int i = 0; i < t; i++)
    {
        for(int j = 0; j < 10; j++)
            scanf("%d", &a[j]);

        if(is_increase(a) || is_decrease(a))
            printf("Ordered\n");
        else
            printf("Unordered\n");
    }

    return 0;
}
