#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

bool pitag(int a,int b,int c){
    if(a * a == b * b + c * c)
        return true;
    if(b * b == a * a + c * c)
        return true;
    if(c * c == a * a + b * b)
        return true;
    return false;
}

int main(){
    int n, m, b;
    while(1){
        cin >> n;
        if(n == 0)
            break;
        cin >> m >> b;
        if(pitag(n, m, b))
            cout <<"right\n";
        else
            cout<<"wrong\n";

    }
    return 0;
}
