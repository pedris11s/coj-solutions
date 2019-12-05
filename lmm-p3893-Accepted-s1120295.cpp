#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL MAX = 12158598919;
const LL MAX_SQRT = 110266;

vector <LL> P;

LL phi(LL n){
    LL result = n;
    for(LL i = 2; i * i <= n; i++)
        if(n % i == 0){
            while(n % i == 0)
                n /= i;
            result -= result / i;
        }
    if(n > 1)
        result -= result / n;

    return result;
}

int main(){

	//ios_base::sync_with_stdio(0);cin.tie(0);

    P.push_back(1);
    for(int i = 1; ; i++){
        LL v = phi(i) + P[i - 1];
        if(v > MAX)
            break;
        P.push_back(v);
    }

    /*for(int i = 0; i < 10; i++)
        cout << i << ") " << P[i] << endl;*/

    LL num, den;
//    while(true){
        LL N;
        cin >> N;
        //for(N = 1; N <= 5; N++){
        if(N == 1){
            cout << "0/1\n";
            return 0;
        }
        if(N == 2){
            cout << "1/1\n";
            return 0;
        }

        int p = lower_bound(P.begin(), P.end(), N) - P.begin();
        den = p;
        LL v = N - P[p - 1];
        LL cont = 0;
        for(LL i = 1; i < den; i++)
            if(__gcd(i, den) == 1){
                cont++;
                if(cont == v){
                    num = i;
                    break;
                }
            }
          //  cout << N << ") ";
        cout << num << "/" << den << "\n";

       // }
   // }
    return 0;
}

