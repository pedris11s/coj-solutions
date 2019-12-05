#include <bits/stdc++.h>

using namespace std;

string A[107];

const int MAXN = 1e5 + 7;

int manh(int a, int b, int c, int d){
    return abs(a - c) + abs(b - d);
}



int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

//    int N;
//    cin >> N;
//    for(int i = 0; i < )

int N;
string su= "sunny", rai="rainy", nub="cloudy";
cin>>N;
string g;
int len = N;
vector<string> lista;
while(N--){
cin>>g;
lista.push_back(g);
}

int cont=0;
if(lista[0]!=su) cont++;

for(int i =1; i<len;i++){
if(lista[i-1]==su || lista[i-1]==rai){
  if(lista[i-1]!=lista[i])cont++;
}else if(i>2){
  if(lista[i-3]==nub && lista[i-2]==nub && lista[i-1]==nub ){
    if(lista[i]!=rai) cont++;
  }else if(lista[i]!=nub)cont++;
}else if(lista[i]!=nub) cont++;
}
cout<<(len-cont)<<'\n';
    return 0;
}
