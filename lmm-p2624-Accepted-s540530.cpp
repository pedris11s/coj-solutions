///by rubens
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double A[1000];

int main(){
    int cas, d, c;
    cin >> cas;
    while(cas--){
        cin >> d >> c;
        for(int i = 0; i < c; i++)
            cin >> A[i];

        sort(A, A + c);

        int maxcities = 0;
        for(int i = 0; i < c; i++){
            int actual = A[i];
            if(actual <= d){
                d -= actual;
                maxcities++;
            }
            else
                break;

        }
        cout << maxcities<<endl;
    }
    return 0;
}
