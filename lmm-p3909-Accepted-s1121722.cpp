#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair <LL, LL> par;

const LL MAX = 300007;


#define a first
#define b second

map<LL,LL> mapa;
vector<LL> norma;
vector<par> pares;

LL abi[MAX],lista[MAX];

LL query(LL x){
    LL ret = 0;
    for(LL i = x; i > 0; i ^= (i&-i))
        ret += abi[i];
    return ret;
}

void update(LL x){
    for(LL j=x; j < MAX; j += (j&-j))
        abi[j]++;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    LL n,a,b;
    cin>>n;

for(LL i=0; i<n;i++){
    cin>>a>>b;
    norma.push_back(a);
    norma.push_back(b);
    pares.push_back(par(a,b));
}
//valores a normalizar
sort(norma.begin(), norma.end());
//Crear Norma
LL len=norma.size(),cont=1;
for(LL i =0; i< len;i++){
    if(!(mapa.find(norma[i]) != mapa.end())){
        mapa[norma[i]] = cont;
        cont++;
    }
}
//Normalizar
len=pares.size();
for(LL i =0; i< len;i++){
    pares[i].a= mapa[pares[i].a];
    pares[i].b= mapa[pares[i].b];
}

//ordeno x .first
    sort(pares.begin(),pares.end());
    /*for(LL i = 0; i < pares.size(); i++)
        cout << pares[i].a <<  " " << pares[i].b << endl;*/

//creo lista
    for(LL i=1; i<=n;i++){
        lista[i]= pares[i-1].b;
    }
    reverse(lista + 1, lista + n + 1);
//solucion parcial 1
LL sol1=0;
for(LL i =n; i>=1;i--){
    sol1+=(n-i-query(lista[i]));
    update(lista[i]);
}
//limpio todo
for(LL i = 0; i< MAX;i++) abi[i]=0;

//cambio los pares
for(LL i = 0; i < pares.size(); i++){
    swap(pares[i].a, pares[i].b);
}
//ordeno x .first
sort(pares.begin(),pares.end());

//creo lista
for(LL i=1; i<=n;i++){
    lista[i]= pares[i-1].b;
}
reverse(lista + 1, lista + n + 1);
LL sol2=0;
for(LL i =n; i>=1;i--){
    sol2+=(n-i-query(lista[i]));
    update(lista[i]);
}
//cout << sol1 << " " << sol2 << "\n";
cout<<min(sol1,sol2)<<"\n";

    return 0;
}
