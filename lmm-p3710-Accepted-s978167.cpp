#include <bits/stdc++.h>

using namespace std;

int t;
int n,m;
double arr[1004];
double votos[1004];
double arreglo[1004][1004];
double val;
double aux[1004];
const double EPS = 1e-8;


struct NODE
{
    int v;
    int id;
    NODE(){}
    NODE(int v, int id): v(v), id(id){}
} result[1004];

bool operator<(const NODE &a, const NODE &b)
{
    if(a.v == b.v)return a.id<b.id;
    return a.v>b.v;
}
int cmp(double x, double y)
{
	return (x <= y + EPS)?(x + EPS < y) ? -1:0:1;
}
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        double total = 0;
        memset(arr, 0, sizeof(arr));
        scanf("%d%d", &n, &m);
        int idGana = -1;
        int cantVotos = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                scanf("%lf", &arreglo[i][j]);
            }
            scanf("%lf", &votos[i]);
            total += votos[i];
            for(int j = 0; j < n; j++)
            {
                arr[j]+=(arreglo[i][j]*votos[i])/100.0;
            }
        }
        for(int i = 0; i < n; i++)
        {
            aux[i] = arr[i];
            double porciento = aux[i]*100.0/total;
            int cmp1 = cmp(porciento, 50.1);
            if(cmp1>=0)
            {
                idGana = i+1;
                cantVotos = (int)arr[i];
            }
            result[i] = NODE((int)arr[i], i+1);
        }
        sort(result, result+n);
        if(idGana!=-1)
        {
            printf("%d %d\n", idGana, cantVotos);
        }else{
            printf("%d %d\n", result[0].id, result[0].v);
            printf("%d %d\n", result[1].id, result[1].v);
        }
        if(t)
        printf("\n");
    }

    return 0;
}
