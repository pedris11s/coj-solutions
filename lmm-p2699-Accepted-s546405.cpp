#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    double x, sum = 0;
    for(int i = 0; i < 30; i++)
    {
        cin >> x;
        sum += x;
    }
    double sol = double(sum) + double(sum / 30);
    printf("%.3lf\n", sol);
    //cout << sol << endl;

	return 0;
}
