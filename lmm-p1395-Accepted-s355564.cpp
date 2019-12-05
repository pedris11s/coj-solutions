//by pter & frank

#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 10000005;

double sol[MAX];

int main()
{
    int t;
    cin >> t;
    vector <int> num;
    while(t--)
    {
        int n;
        cin >> n;
        num.push_back(n);
    }
    int indMax = max_element(num.begin(), num.end()) - num.begin();
    sol[1] = 0;
    for(int i = 2; i <= num[indMax]; i++)
        sol[i] = log10(i) + sol[i - 1];

    /*for(int i = 1; i <= num[indMax]; i++)
        cout << i << ") "<< sol[i] << endl;*/

    for(int i = 0; i < num.size(); i++)
        cout << ((int) sol[num[i]]) + 1 << endl;

}
