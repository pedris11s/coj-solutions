#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 1000;

struct player{
    string name;
    double R;
    int Ra, K;
    double W, We;
    /*bool operator < (const player &X)const
    {
        if(R != X.R)
            return R > X.R;
    }*/
}A[MAXN];

int main()
{
    string torneo; int N;
    cin >> torneo >> N;
    for(int i = 0; i < N; i++)
        cin >> A[i].name >> A[i].Ra >> A[i].W >> A[i].We >> A[i].K;

    double media = 0;
    for(int i = 0; i < N; i++)
    {
        A[i].R = (double)A[i].Ra + ((double)A[i].K * ((double)A[i].W - (double)A[i].We));
        media += A[i].Ra;
    }
    //cout << A[1].Ra + A[1].K * (A[1].W - A[1].We) << endl << endl;;

    media /= N;
    //sort(A, A + N);
    cout << "Tournament: " << torneo << endl;
    cout << "Number of players: " << N << endl;
    cout << "New ratings:" << endl;
    for(int i = 0; i < N; i++)
        cout << A[i].name << ' ' << A[i].R << endl;

    cout << "Media Elo: " << round(media) << endl;



    return 0;
}
