#include <bits/stdc++.h>

using namespace std;

int toInt(string num){
    int n = 0;
    for(int i = 0; i < num.size(); i++)
        n = n * 10 + (num[i] - '0');
    return n;
}

int main()
{
    string cad;
    cin >> cad;

    int n = cad.size();
    string x = cad.substr(n - 2, 2);
    int hh = toInt(cad.substr(0, 2));
    string sol = "";
    if(x == "AM"){
        if(hh == 12){
            //sol = "00";
            cout << "00" << cad.substr(2, 6);
            return 0;
        }
        else{
            if(hh < 10)
                cout << "0" << hh << cad.substr(2, 6);
            else
                cout << hh << cad.substr(2, 6);
            return 0;
        }
    }else{
        if(hh == 12){
            cout << "12" << cad.substr(2, 6);
            return 0;
        }
        else{
            hh = hh + 12;
            cout << hh << cad.substr(2, 6);
            return 0;
        }
    }

    return 0;
}
