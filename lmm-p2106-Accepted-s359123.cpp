//by pter

#include <cstdio>

using namespace std;

const int a[] = {0, 1, 2, 4, 8, 16, 23, 46, 29, 58, 116, 223, 446, 289, 578, 1156,
                 1223, 2446, 2489, 4789, 5789, 11578, 12356, 12247, 24449, 48889,
                 77789, 155578, 111356, 122227, 244445};

int main()
{
    int n;
    scanf("%d", &n);

    int sol;
    if(n <= 30)
        sol = n;
    else
    {
        if(n % 6 == 0)
            sol = 30;
        else
            sol = 24 + (n % 6);
    }
    printf("%d\n", a[sol]);

    return 0;
}
