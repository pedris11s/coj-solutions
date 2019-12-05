#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAX = 1e9;

LL a, b, h, l;
LL x[4];
LL y[4];
/*
LL a1x, a1y, a2x, a2y;
LL b1x, b1y, b2x, b2y;

*/

bool analiza(){
    if(x[3] - x[2] >= a && h >= b)return true;
    //if(x[3] - x[2] >= b && h >= a)return true;

    if(x[1] - x[0] >= a && h >= b)return true;
   // if(x[1] - x[0] >= b && h >= a)return true;

    if(y[1] - y[0] >= b && l >= a)return true;
   // if(y[1] - y[0] >= a && l >= b)return true;

   // if(y[3] - y[2] >= a && l >= b)return true;
    if(y[3] - y[2] >= b && l >= a)return true;

    return false;
}


/*
bool ok(){

    LL w, h;
    w = a2y - a1y;
    h = b1x - a1x;

    if(w > h)swap(w, h);
    if(a <= w && b <= h)return true;

    w = a2x - a1x;
    h = a2y - b2y;

    if(w > h)swap(w, h);
    if(a <= w && b <= h)return true;

    w = a2x - b2x;
    h = a2y - a1y;

    if(w > h)swap(w, h);
    if(a <= w && b <= h)return true;

    w = a2x - a1x;
    h = b1y - a1y;

    if(w > h)swap(w, h);
    if(a <= w && b <= h)return true;

    return false;

}*/

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

  /*  cin >> a1x >> a1y >> a2x >> a2y;
    cin >> b1x >> b1y >> b2x >> b2y;

    a1x += MAX;
    a1y += MAX;
    a2x += MAX;
    a2y += MAX;
    b1x += MAX;
    b1y += MAX;
    b2x += MAX;
    b2y += MAX;
*/
    for(LL i = 0; i < 4; i++){
        cin >> x[i] >> y[i];
        x[i]+=MAX;
        y[i]+=MAX;
    }

    cin >> a >> b;

    l = x[1] - x[0];
    h = y[1] - y[0];
    sort(x, x + 4);
    sort(y, y + 4);

    if(analiza())
        cout << "Yes\n";
    else
        cout << "No\n";


    return 0;
}
