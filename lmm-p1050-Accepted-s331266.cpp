#include <cstdio>
#include <cstdlib>

using namespace std;

int mcd(int k, int m)
{ if (m == 0)
    return k;
    return mcd(m, k%m);
  }

int main()
{   int n;
    int cont = 0;
    scanf("%d", &n);
    for(int i = 1; i < n; i++)
        {
        if (mcd(i, n) == 1)
            cont++;
        }

    printf("%d",cont);
    return 0;
}

