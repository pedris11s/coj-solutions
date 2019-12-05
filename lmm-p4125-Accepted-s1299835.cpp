#include <bits/stdc++.h>

using namespace std;

int main(){


//    freopen("01.in", "r", stdin);
//    freopen("01.out", "w", stdout);
//
//    srand(time(NULL));
//
//
    string zero = "0000000", one = "1111111";
//
//    int n = 99;
//    string cad = "";
//    for(int i = 0; i < n; i++){
//        char d = (rand() % 2 == 0) ? '0': '1';
//        cad += d;
//    }
////    int d = (rand() % 2);
////    if(d)
////        cad += zero;
////    else
////        cad += one;
//    cout << cad  << endl;


    string cad;
    cin >> cad;

    if(cad.size() < 7) {
        cout << "NO\n";
        return 0;
    }
    bool flag = false;
    for(int i = 0; i < cad.size() - 7; i++){
        if(cad.substr(i, 7) == zero || cad.substr(i, 7) == one){
            cout << "YES\n";
            flag = true;
            break;
        }
    }
    if(!flag)
        cout << "NO\n";


    return 0;
}
