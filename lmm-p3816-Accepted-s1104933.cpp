#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

const int MAXN = 105;

int N;
double X[MAXN], Y[MAXN];
double adM[MAXN][MAXN];
double Costo[MAXN];
bool mk[MAXN];

double INF = 0;

int main()
{
	cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> X[i] >> Y[i];

	for(int i = 1; i < N; i++)
		for(int j = i + 1; j <= N; j++)
		{
			double dx = X[j] - X[i];
			double dy = Y[j] - Y[i];
			adM[i][j] = adM[j][i] = sqrt(dx * dx + dy * dy);
			if(adM[i][j] + 1 > INF)
				INF = adM[i][j] + 1;
		}

	double SOL = 0.0;

	for(int i = 1; i <= N; i++)
		Costo[i] = INF;

	Costo[1] = 0;
	for(int i = 1; i <= N; i++)
	{
		double min = INF;
		int nodo;
		
		for(int j = 1; j <= N; j++)
			if( !mk[j] && Costo[j] < min)
			{
				min = Costo[j];
				nodo = j;
			}
		SOL += min;
		mk[nodo] = true;
		
		for(int j = 1; j <= N; j++)
			if( !mk[j] )
				if( Costo[j] > adM[nodo][j] )
					Costo[j] = adM[nodo][j];
	}
	printf("%.2lf\n", SOL);

	return 0;
}


/*#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXN = 1e6 + 7;

bool comp[MAXN];


void criba(){
    for(int i = 4; i < MAXN; i += 2)
        comp[i] = true;

    for(int i = 3; i * i < MAXN; i += 2)
        if(!comp[i])
            for(int j = i * i; j < MAXN; j +=  2 * i)
                comp[j] = true;

   /* int sol = 0;
for(int i =2; i < MAXN; i++)
    if(!comp[i])
    sol++;
cout << sol << endl;

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    criba();

    int N;
    cin >> N;
    int cont = 0;
    for(int i = 2; i <= N; i++){
        int x = __gcd(i, N);
        if(!comp[x] && x != 1)
            cont++;
    }
    cout << cont << "\n";
    return 0;
}*/
