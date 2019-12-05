#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXN = 1e6 + 3;

string a, b;
LL P[MAXN], I[MAXN];

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    LL x = 0;
    for(int i = 1; i < MAXN; i++){
        P[i] = 2 * x;
        P[i] *= P[i];
        P[i] += P[i - 1];
        x++;
    }
    x = 1;
    for(int i = 1; i < MAXN; i++){
        I[i] = (2 * x - 1);
        I[i] *= I[i];
        I[i] += I[i - 1];
        x++;
    }
    LL n;
    while(true){
        scanf("%lld", &n);
        if(n == 0)break;
        LL media = n;
        LL odd, sum = 0, val = 0, cont = 0;

        if(n & 1){
            cont = n / 2 + 1;
            cont = P[cont] * 2;
        }
        else{
            cont = n / 2;
            cont = I[cont] * 2;
        }

        /*for(int i = 1; i <= n; i++){
            odd = (LL)i * 2 - 1;
            sum += (odd - media) * (odd - media);
            val = odd - media;
            cout << val << endl;
        }*/
        //cout << "LA SUMA >> " << sum << endl;
        //cout << cont << endl;
        double sol = sqrt(cont / (n - 1.0));
        printf("%.6lf\n", sol);
    }


    return 0;
}
