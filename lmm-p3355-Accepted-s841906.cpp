#include <bits/stdc++.h>

using namespace std;

const int MAX_SQRT = 3001;

int P;
int primes[1000];
bool comp[MAX_SQRT];
bool isOK[MAX_SQRT];
int TA[MAX_SQRT];

void criba()
{
	comp[1] = true;
	for(int i = 4; i < MAX_SQRT ; i += 2)
		comp[i] = true;

	for(int i = 3; i * i < MAX_SQRT; i += 2)
		if (!comp[i])
			for (int j = i * i ; j < MAX_SQRT; j += i + i)
				comp[j] = true;

	primes[0] = 2;
	P = 1;
	for(int i = 3; i < MAX_SQRT; i += 2)
		if(!comp[i])
			primes[P++] = i;

    //for(int i= 0; i < ind; i++)
    //    cout << primes[i] << ' ';
    //cout << P << endl;
}

bool iscorrect(int n)
{
    int cont = 0;
    for(int i = 0; i < P && primes[i] <= n; i++)
    {
        if(n % primes[i] == 0)
            cont++;
        if(cont > 2)
            return false;
    }
    if(cont == 2)
        return true;
    return false;

}

int main()
{
    criba();
    //Divisors(14);
    int cont = 0;
    for(int i = 2; i < MAX_SQRT; i++)
        if(iscorrect(i))
        {
            //cout << i <<endl;
            isOK[i] = true;
            cont++;
        }
    for(int i = 1; i < MAX_SQRT; i++)
        TA[i] += TA[i - 1] + isOK[i];

    int n;
    cin >> n;
    cout << TA[n] << endl;

    return 0;
}
