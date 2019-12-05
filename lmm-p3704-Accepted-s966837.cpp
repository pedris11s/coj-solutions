#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

string xSpaces(int x)
{
    string cad = "";
    for(int i = 0; i < 2 * x; i++)
        cad += " ";
    return cad;
}

int main (){

    ios_base::sync_with_stdio(0); cin.tie(0);

    stack <int> pila;
    string cad;
    cin >> cad;

    string sol = "";
    int i = 0;
    while(i < cad.size()){
        bool flag = false;
        if(cad[i] == '{'){
            sol += xSpaces(pila.size()) + "{" + "\n";
            pila.push(i);
        }
        else if(cad[i] == ','){
            sol += ",";
            sol += "\n";
        }
        else if(cad[i] == '}'){
            if(cad[i - 1] != '{')
                sol += "\n";
            pila.pop();
            sol += xSpaces(pila.size()) + "}";
        }
        else{
            string aux = "";
            while(cad[i] != ',' && cad[i] != '{' && cad[i] != '}'){
                aux += cad[i], i++;
                flag = true;
            }
            sol += xSpaces(pila.size()) + aux;
        }
        if(!flag)
            i++;
    }
    cout << sol;

    return 0;
}
