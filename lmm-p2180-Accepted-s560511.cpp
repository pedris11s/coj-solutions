#include <cstdio>
#include <iostream>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN = 2505;

typedef pair <int, int> par;

par A[MAXN], B[MAXN];

int main()
{
    /*set <int> a;
    a.insert(1892);

    cout << (*a.begin()) << endl;;
    a.erase(a.begin());
    a.insert(1789);
    cout << (*a.begin());*/

    int C, L;
    cin >> C >> L;

    for(int i = 0; i < C; i++)
        cin >> A[i].first >> A[i].second;

    for(int i = 0; i < L; i++)
        cin >> B[i].first >> B[i].second;

    sort(A, A + C);
    sort(B, B + L);

    priority_queue <int, vector <int>, less <int> > cola;

    int i = 0, j = 0, sol = 0;
    while(i < L)
    {
        while((j < C) && (A[j].first <= B[i].first))
                cola.push(-A[j++].second);

        while((!cola.empty()) && (-(cola.top()) < B[i].first))
                cola.pop();

        while((!cola.empty()) && (B[i].second--))
        {
                sol++;
                cola.pop();
        }
        i++;
    }
    cout << sol << endl;

    return 0;
}

