#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        string cad;
        cin >> cad;

        string aux = cad;
        reverse(aux.begin(), aux.end());


        bool flag = false;
        for(int i = 0; i < cad.size(); i++)
            if(cad[i] == aux[i]){
                cout << "no\n";
                flag = true;
                break;
            }
        if(!flag)
            cout << "yes\n";
    }
    return 0;
}
