#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){

        string cad;
        cin >> cad;
        if(cad[0] == '1')
        {
            bool flag = true;
            for(int i = 1; i < cad.size(); i++)
                if(cad[i] != '0'){
                    flag = false;
                    break;
                }
            if(flag)
                cout << "1\n";
            else
                cout << "0\n";
        }
        else
            cout << "0\n";
    }
    return 0;
}
