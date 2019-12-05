//by pter.the last y pincha
//pequeno arreglo by fr

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

const int MAXN = 1000001;

bool mk[MAXN];
int TA[MAXN];

void criba ()
{
	int j;
	for (int i = 4 ; i < MAXN ; i += 2)
		mk[i] = true;
	for ( int i = 3; i * i < MAXN; i += 2 )
         if ( !mk[i] )
		 {
			j = i * i;
			while ( j <= MAXN )
			{
                 mk[j] = true;
				 j += i + i;
			}
		}
}

typedef long long ll;

int main()
{
	mk[0] = true;
	mk[1] = true;

	criba();
    for (int i = 2 ; i < MAXN ; i++)
    	TA[i] = TA[i - 1] + !mk[i];

	ll x, y;
	int cont = 0;
	int t;
	scanf("%d",&t);
	for(int i = 0; i < t; i++)
	{
         cin >> x >> y;

		 cont = TA[(int)sqrtl(y)] - TA[((int)ceill(sqrtl(x))) - 1];

		 printf("%d\n", cont);
		 cont = 0;
	}
	return 0;
}
