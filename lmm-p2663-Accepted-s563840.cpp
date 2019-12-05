#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

vector<int> GN;

/*
void gen(long long n){
    if (n > 1e9)
        return;

    GN.push_back((int)n);
    int ld = n % 10;
    for (int d = ld + 1 ; d <= 9 ; d++)
        gen(n * 10 + d);
}


bool G(int n){
    while (n >= 10){
        if ((n / 10) % 10 >= n % 10)
            return false;
        n /= 10;
    }
    return true;
}
*/

queue<long long> Q;

int main()
{

    GN.push_back(0);
    /*
    for (int di = 1 ; di <= 9 ; di++)
        gen(di);
        */

    for (long long di = 1 ; di <= 9 ; di++)
        Q.push(di);

    while (!Q.empty()){
        long long n = Q.front();
        Q.pop();
        GN.push_back(n);
        int ld = n % 10;
        for (int df = ld + 1 ; df <= 9 ; df++)
            if (n * 10 + df < 1e9)
                Q.push(n * 10 + df);
    }

    //sort(GN.begin(), GN.end());
    //for (int i = 0 ; i < GN.size() ; i++)
    //    cout << GN[i] << endl;

    //cout << GN.size();

    int t;
    cin >> t;
    long long a, b;
    while(t--){
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        cout << upper_bound(GN.begin(), GN.end(), b) -
                lower_bound(GN.begin(), GN.end(), a) << endl;
    }

    return 0;
}
