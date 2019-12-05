#include <cstdio>
#include <algorithm>

using namespace std;

int con, nd, nc, nod, newn, S[1000], M[105][105];
bool mar;

int main(){

    while (scanf ("%d%d",&nd,&nc) != EOF){
           con++;
           for (int i = 1; i <= nc; i++){
                scanf ("%d%d",&nod, &newn);
                if (M[newn][nod] != con) S[nod]++, S[newn]++;
                M[newn][nod] = M[nod][newn] = con;
           }

           mar = false;
           for (int i = 1; i <= nd; i++){
                if (S[i] < nd-1) mar = true;
                S[i] = 0;
           }

           if (mar == true) printf ("Yes\n");
            else printf ("No\n");
    }

    return 0;
}
