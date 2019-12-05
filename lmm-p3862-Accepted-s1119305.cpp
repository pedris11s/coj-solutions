
//============================================================================
// Name        : vacas.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
#define MAXN 10000
#define endl '\n'
#define ll long long

#define MOD 1000000007

ll N;
ll solve[6][6] =
       {{1,1,1,1,1,0},
        {1,0,0,0,0,0},
        {1,0,0,1,0,0},
        {1,0,1,0,0,0},
        {1,0,0,0,0,1},
        {0,0,0,0,1,0}};/*
ll solve[6][6] =
       {{1,1,1,1,1,1},
        {1,1,1,1,1,1},
        {1,1,1,1,1,1},
        {1,1,1,1,1,1},
        {1,1,1,1,1,1},
        {1,1,1,1,1,1}};*/

ll sol[6][6] =
       {{1,0,0,0,0,0},
        {0,1,0,0,0,0},
        {0,0,1,0,0,0},
        {0,0,0,1,0,0},
        {0,0,0,0,1,0},
        {0,0,0,0,0,1}};

ll tmp[6][6];

void EXP(ll N){
    while(N > 0){
        //cout << "loka" << endl;
        if(N&1){
            for(ll i = 0 ; i < 6; i++)
                for(ll j = 0 ; j < 6; j++){
                    tmp[i][j] = 0;
                    for(ll k = 0 ; k < 6; k++)
                        tmp[i][j] += (solve[i][k] * sol[j][k]) % MOD;
                }
        for(ll i = 0 ; i < 6; i++)
            for(ll j = 0 ; j < 6; j++)
                sol[i][j] = tmp[i][j];
        }

        for(ll i = 0 ; i < 6; i++)
            for(ll j = 0 ; j < 6; j++){
                tmp[i][j] = 0;
                for(ll k = 0 ; k < 6; k++)
                    tmp[i][j] += (solve[i][k] * solve[j][k]) % MOD, tmp[i][j] %= MOD;
            }
        for(ll i = 0 ; i < 6; i++)
            for(ll j = 0 ; j < 6; j++)
                solve[i][j] = tmp[i][j];
        N >>= 1;
    }
/*
    for(ll i = 0 ; i < 6; i++, cout << endl)
        for(ll j = 0 ; j < 6; j++)
        {
            cout << sol[i][j] << " ";
        }*/
}
int main() {
    cin >> N;

    ll soll = 0 ;
    EXP(N-1);

        for(ll j = 0 ; j < 5 ; j++)
                soll += sol[0][j], soll %= MOD;

    cout << soll  << endl;


    return 0;
}

