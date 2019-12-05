#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL MAXN = 1e5 + 7;

LL N;
LL X[MAXN], Y[MAXN];
LL TAXR[MAXN], TAXL[MAXN];
LL TAYR[MAXN], TAYL[MAXN];

int main(){

    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> N;
    for(LL i = 0; i < N; i++)
        cin >> X[i] >> Y[i];

    sort(X, X + N);
    sort(Y, Y + N);

    for(LL i = 1; i < N; i++)
        TAXR[i] = TAXR[i - 1] + i * abs(X[i] - X[i - 1]);

    for(LL i = N - 2; i >= 0; i--)
        TAXL[i] = TAXL[i + 1] + (N - i - 1) * abs(X[i] - X[i + 1]);

    for(LL i = 1; i < N; i++){
        TAYR[i] = TAYR[i - 1] + i * abs(Y[i] - Y[i - 1]);
     //   cout << TAYR[i] << " ";
    }

    for(LL i = N - 2; i >= 0; i--)
        TAYL[i] = TAYL[i + 1] + (N - i - 1) * abs(Y[i] - Y[i + 1]);


    LL Q;
    cin >> Q;
    while(Q--){
        LL x, y;
        cin >> x >> y;

        LL p1 = lower_bound(X, X + N, x) - X;
        LL p2 = lower_bound(Y, Y + N, y) - Y;
        LL solx = 0, soly = 0;


        if(X[p1] == x && p1 < N){
            solx += TAXR[p1] + TAXL[p1];
        }else{
            if(p1==N){
                p1--;
                solx += TAXR[p1];
                solx += abs(x - X[p1]) * (p1 + 1);
            }else if(p1==0){
            solx += TAXL[p1];
                solx += abs(x - X[p1]) * (N);
            }else{
                p1--;
                solx += TAXR[p1];
                solx += abs(x - X[p1]) * (p1 + 1);
                solx += TAXL[p1+1];
                solx += abs(x - X[p1+1]) * (N - p1 - 1);
            }
        }
        //cout << solx << endl;
//con la sy

       if(Y[p2] == y && p2 < N){
            soly += TAYR[p2] + TAYL[p2];
        }else{
            if(p2==N){
                p2--;
                soly += TAYR[p2];
                soly += abs(y - Y[p2]) * (p2 + 1);
            }else if(p2==0){
            soly += TAYL[p2];
                soly += abs(y - Y[p2]) * (N);
            }else{
                p2--;
                soly += TAYR[p2];
                soly += abs(y - Y[p2]) * (p2 + 1);
                soly += TAYL[p2+1];
                soly += abs(y - Y[p2+1]) * (N - p2 - 1);
            }
        }
        //cout << soly << endl;
cout << solx + soly << "\n";
    }


    return 0;
}
