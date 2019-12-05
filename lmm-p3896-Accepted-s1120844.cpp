#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int x, y, x1, y1, x2, y2, solx1, soly1, solx2, soly2;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;

    if(x1 != x2){
        solx1 = min(x1, x2);
        solx2 = max(x1, x2);
        soly1 = 0;
        soly2 = y;
    }else{
        soly1 = max(y1, y2);
        soly2 = min(y1, y2);
        solx1 = 0;
        solx2 = x;
    }
/*
    if(abs(ax - bx) > 1){
        solx1 = max(ax, bx) - 1;
        solx2 = solx1;
        soly1 = 0;
        soly2 = y;
    }else if(abs(ay - by) > 1){
        soly1 = max(ay, by) - 1;
        soly2 = soly1;
        solx1 = 0;
        solx2 = x;
    }*/

    cout << solx1 << " " << soly1 << " " << solx2 << " " << soly2 << "\n";

    return 0;
}
