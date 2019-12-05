#include <cstdio>
#include <algorithm>
using namespace std;

struct edge{
    long ini, fin, cost;
    bool operator<( const edge &A ) const{
        return cost < A.cost;
        }
    }E[1000010];
long V, Ed, sol;

long P[1000010],
    rank[1000010];

long Find( long x ){
    if( x != P[x] ) P[x] = Find( P[x] );
    return P[x];
    }
long Make( long Px, long Py ){
    if( rank[Px] > rank[Py] ) P[Py] = Px,rank[Py]+=rank[Px];
    else P[Px] = Py, rank[Px]+=rank[Py];
    }

int main(){

    while(1){
         scanf( "%ld%ld", &V, &Ed );
        if(V==0&&Ed==0)break;

        for( long i = 1; i <= Ed; i++ ){
            scanf( "%ld%ld%ld", &E[i].ini, &E[i].fin, &E[i].cost );
            E[i].ini++; E[i].fin++;
            P[i] = i;
            rank[i] = 1;
            }
        sort( E+1, E+Ed+1 );
        int N = V;
        for( long i = 1; i <= Ed; i++ ){
            long Px = Find( E[i].ini ),
                Py = Find( E[i].fin );
            if( Px != Py ){
                Make( Px, Py );
                N--;
                sol = max( sol, E[i].cost );
                }
            }
        //printf( "--%d--", N );
        if( sol && N == 1 ) printf( "%ld\n", sol );
        else printf( "IMPOSSIBLE\n" );
        sol = 0;
        }


    }
