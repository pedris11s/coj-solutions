#include <bits/stdc++.h>

using namespace std;

int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);

    double w, h, sol;
    scanf("%lf%lf", &w, &h);
    //cin >> w >> h;

    if(w < h)swap(w, h);
    if(w >= 3 * h)sol = h;
    else if(h / 2 < w / 3)sol = w / 3;
    else sol = h / 2;

    //==cout.precision(3);
    //cout << sol << '\n';
    //sol = round(sol);

    printf("%.4lf\n", sol);


    return 0;
}
