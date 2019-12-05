#include <bits/stdc++.h>

using namespace std;

int n, m, color[205];
bool flag;
queue <int> cola;
vector <int> adlist[205];

bool bfs(){
    cola.push(0);
   color[0] = 1;
   flag = false;
   while (!cola.empty()){
         int nod = cola.front();
         cola.pop();
         for (int i = 0; i < adlist[nod].size(); i++){
              int newn = adlist[nod][i];
              if (color[newn] > 0){
                  if (color[nod] == color[newn]) flag = true;
              }
               else{
                  if (color[nod] == 1) color[newn] = 2;
                   else color[newn] = 1;
                  cola.push(newn);
               }
         }
    }
    return flag;

}

int main(){


    while(true){
           cin >> n;

           if (n == 0) break;
           cin >> m;

           for (int i = 0; i <= 200; i++)
                adlist[i].clear(), color[i] = 0;

           for (int i = 1; i <= m; i++){
                int a, b;
                cin >> a >> b;
                adlist[a].push_back(b);
                adlist[b].push_back(a);
           }

           if (bfs())
                cout << "NOT BICOLORABLE.\n";
            else
                cout << "BICOLORABLE.\n";

    }

    return 0;
}
