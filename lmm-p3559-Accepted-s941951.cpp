#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair <int, int> par;

const int MAX = 170;

vector <LL> p, e;
vector <int> primes;
int A[200], B[200], C[200], POS[1007];
bool comp[1007];


void factoriza(LL n)
 {
     p.clear(); e.clear();
     int exp = 0;
     if(n % 2 == 0)
     {
        while(n % 2 == 0)
            exp++, n /= 2;
        p.push_back(2);
        e.push_back(exp);
     }

     for(int i = 3; i * i <= n; i += 2)
        if(n % i == 0)
        {
            exp = 0;
            while(n % i == 0)
                n /= i, exp++;
            p.push_back(i);
            e.push_back(exp);
        }
    if(n > 1){
        p.push_back(n);
        e.push_back(1);
    }
 }

void criba()
{
    for(int i = 4; i <= 1000; i += 2)
        comp[i] = true;

    for(int i = 3; i * i <= 1000; i += 2)
        if(!comp[i])
            for(int j = i * i; j <= 1000; j += i)
                comp[j] = true;

    int cont = 1;
    primes.push_back(2);
    POS[2] = 0;
    for(int i = 3; i <= 1000; i += 2)
        if(!comp[i]){
            primes.push_back(i);
            POS[i] = cont++;
        }

}

int prime(int n)
{
    for(int i = 3; i *i <= n; i+=2)
        if(n % i == 0)
            return false;
    return true;
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    criba();
    //cout << primes.size() << endl;



    /*int cont = 1;
    for(int i = 3; i <= 1000; i+=2)
        if(prime(i))
            cont++;
    cout << cont << endl;*/
    int t;
    cin >> t;
    while(t--){

        int n, a, b;
        cin >> n >> a >> b;

        for(int i = 0; i < MAX; i++)
            A[i] = B[i] = C[i] = 0;

        factoriza(a);
        for(int i = 0; i < p.size(); i++)
            A[POS[p[i]]] = e[i];

        factoriza(b);
        for(int i = 0; i < p.size(); i++)
            B[POS[p[i]]] = e[i];

        int t = n - 1;
        while(t--){

            for(int i = 0; i < MAX; i++)
                C[i] = A[i] + B[i];

            for(int i = 0; i < MAX; i++){
                A[i] = B[i];
                B[i] = C[i];
            }
        }
        for(int i = 0; i < MAX; i++)
            if(C[i] != 0)
                cout << primes[i] << " " << C[i] << "\n";
        cout << "\n";
    }
    return 0;
}
