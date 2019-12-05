#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    string cad;
    cin >> cad;

    int n = cad.size();
    vector <int> div;
    div.push_back(1);
    for(int i = 2; i <= n / 2; i++)
        if(n % i == 0)
            div.push_back(i);

    bool flag2 = false;
    for(int i = 0; i < div.size(); i++)
    {
        string aux = cad.substr(0, div[i]);
        int a = 0, b = 0;bool flag = false;
        while(a < n){
            if(cad[a] == aux[b])
                a++, b++;
            else{
                flag = true;
                break;
            }
            if(b == aux.size())
                b = 0;
        }
        if(!flag){
            cout << aux.size() << "\n";
            flag2 = true;
            break;
        }
    }
    if(!flag2)
        cout << 0 << "\n";

    return 0;
}
