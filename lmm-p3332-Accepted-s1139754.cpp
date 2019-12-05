#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll sizesieve;
bool bs[1000010];
vector<int> primes;

void sieves(ll upper){
    sizesieve = upper + 1;
    bs[0] = 1; bs[1] = 1;
    for(ll i = 2; i <= sizesieve; i++)
    if(!bs[i]){
        for(ll j = i * i; j <= sizesieve; j += i)
            bs[j] = 1;
        primes.push_back((int)i);
    }
}

bool is_primo(long long n)
{
    if(n <= sizesieve)
        return !bs[n];
    for(int i = 0;i < (int)primes.size();i++){
        if(n % primes[i] == 0)
            return false;
    }
    return true;
}

ll numDiv(ll N)
{
    ll cont = 0;
    if( is_primo(N)){
         return 1;
    }
    //cout << "ads";
    int i = 0;
    while(N >= primes[i]){
        //cout<<primes[i]<<" "<<endl;
        if(is_primo(N))
        {
            return cont+1;
        }
        if(N % primes[i] == 0){
            //cout << primes[i] << " ";
            cont ++;
            while(N % primes[i] == 0)
                N /= primes[i];
        }

        i ++;
    }
    //cout<<cont<<endl;
    return cont;
}

ll sq (ll n)
{
    return n*n;
}

ll pow2(int p){
    if(p == 0)
        return 1;
    if(p == 1)
        return 2;
    ll ans = sq(pow2(p/2));
    if(p & 1)
        return 2*ans;
    else return ans;
}

int main()
{
    sieves(1000000);
    int n;
    long long a, b, c;
    scanf("%d", &n);

    while(n--){
        scanf("%lld %lld", &a, &b);
        if(a%b != 0 && b%a != 0 || a > b){
            printf("0\n");
            continue;
        }

        if(b/a == 1){
            printf("1\n");
            continue;
        }
        c = numDiv(b/a);
        printf("%lld\n", pow2(c-1));
    }
    return 0;
}
