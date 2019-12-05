
#include <cstdio>
#include <vector>
#include <algorithm>

#define RAN 20005
using namespace std;

int nd, nc, id_nod, id_newn;
int Id[RAN], Ran[RAN];
vector <int>V;

struct tri{
       int nod, newn, cos;
       tri (int a=0, int b=0, int c=0){
            nod = a;
            newn = b;
            cos = c;
       }
       bool operator <(const tri &R)
       const{
            return R.cos > cos;
       }
}A[RAN];

int bus_id(int nod){
    if (nod != Id[nod])
        Id[nod] = bus_id(Id[nod]);
    return Id[nod];
}

void are_id(int nod, int newn){
     if (Ran[nod] > Ran[newn]){
         Ran[nod] += Ran[newn];
         Id[newn] = nod;
     }
     else{
         Ran[newn] += Ran[nod];
         Id[nod] = newn;
     }
}

int seg_mst(int id){
     for (int i = 1; i <= nd; i++)
          Ran[i] = 1, Id[i] = i;

     int sol = 0;
     for (int i = 1; i <= nc; i++){

         if (i == id)continue;

         id_nod = bus_id(A[i].nod);
         id_newn = bus_id(A[i].newn);
         if (id_nod != id_newn){
             sol += A[i].cos;
             are_id(id_nod, id_newn);
         }
    }

    return sol;
}

int main(){

    scanf ("%d %d", &nd, &nc);
    for (int i = 1, a, b, c; i <= nc; i++){
         scanf ("%d %d %d", &a, &b, &c);
         A[i] = tri (a, b, c);
    }

    for (int i = 1; i <= nd; i++)
         Ran[i] = 1, Id[i] = i;

    sort (A + 1, A + nc + 1);
    for (int i = 1; i <= nc; i++){
         id_nod = bus_id(A[i].nod);
         id_newn = bus_id(A[i].newn);
         if (id_nod != id_newn){
             V.push_back(i);
             are_id(id_nod, id_newn);
         }
    }

    int segmst = 1 << 30;
    for (int i = 0; i < nd-1; i++)
         segmst = min(segmst, seg_mst(V[i]));

    printf ("%d\n", segmst);

    return 0;
}

