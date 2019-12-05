 # include <bits/stdc++.h>
 # define RANG 1000010
 using namespace std;

 int cont=0;
 int Prim[RANG], P[RANG], mat[RANG][20], lg[RANG];
 const int N = 1000005;

 void Criba(){
    for(int i = 4; i < N; i += 2)P[i] = 2;
    for(int i = 3; i*i < N; i += 2)
        if(!P[i]){
            for(int j = i*i; j < N; j += 2*i)
                P[j] = i;
        }

    for(int i = 2; i < N; i++)
        if(!P[i])
            Prim[++cont] = i;
 }

 void BuildRMQ(){

    int cc = lg[cont];
    int p = cont, a, i, j;
    for(int i = 1; i <= cc; i++){
        a = 1 << (i-1);
        p-=a;
        for(int j = 1; j <= p; j++)
            mat[j][i] = min(mat[j][i-1],mat[j+a][i-1]);
    }
 }

 int findRMQ(int p1, int p2){

    int c = lg[p2-p1];
    return min(mat[p1][c], mat[p2-(1<<c)+1][c]);
 }

 int main(){

    Criba();
    Prim[cont+1] = 1 << 30;
    Prim[cont+2] = 1 << 30;
    for(int i = 1; i <= cont; i++)
        mat[i][0] = Prim[i+2]-Prim[i];

/*
    printf("%d\n", cont);
    for(int i = 1; i < 22-1; i++)
        printf("%d\n", mat[i][0]);
    printf("----\n");
    for(int i = 1; i < 22-1; i++)
        printf("%d\n", Prim[i]);*/

    lg[0] = 0;
    for(int i = 1; i <= cont; i++)
        lg[i] = log2(i);

    BuildRMQ();

    int tc;
    scanf("%d", &tc);
    while(tc--){
        int a, b, p1, p2;
        scanf("%d %d", &a, &b);
        p1 = lower_bound(Prim+1, Prim+cont+1, a) - Prim;
        p2 = upper_bound(Prim+1, Prim+cont+1, b) - Prim;
        p2--;
        while(Prim[p2+2] > b )p2--;
        if(p2 < p1)
            printf("-1\n");
        else
            printf("%d\n", findRMQ(p1, p2)+1);
    }
 }
